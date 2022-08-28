#pragma once

class Loot
{
public:
	static inline std::vector<UFortItemDefinition*> CommonWeapons;
	static inline std::vector<UFortItemDefinition*> UnCommonWeapons;
	static inline std::vector<UFortItemDefinition*> RareWeapons;
	static inline std::vector<UFortItemDefinition*> EpicWeapons;
	static inline std::vector<UFortItemDefinition*> LegendaryWeapons;

	static inline std::vector<UFortItemDefinition*> Resources;
	static inline std::vector<UFortItemDefinition*> Consumables;
	static inline std::vector<UFortItemDefinition*> Ammo;

	static void InitTables()
	{
#if defined(SOLO) || defined(DUO) || defined(LATEGAME)
		auto LootPackages = UObject::LoadObject<UDataTable>("/Game/Items/Datatables/AthenaLootPackages_Client.AthenaLootPackages_Client");
		CORE_LOG(Loot, "LootPackages: {}", LootPackages->GetFullName().c_str());
#else
		auto AthenaGameState = (AFortGameStateAthena*)(GetWorld()->GameState);
		auto LootPackages = AthenaGameState->CurrentPlaylistInfo.BasePlaylist->LootPackages.Get();
		CORE_LOG(Loot, "LootPackages: {}", LootPackages->GetFullName().c_str());
#endif

		for (auto Row : LootPackages->RowMap)
		{
			auto RowName = Row.Key();
			auto RowStruct = (FFortLootPackageData*)Row.Value();

			if (RowName.ComparisonIndex == 0)
				continue;

			if (RowStruct->ItemDefinition.SoftObjectPtr.ObjectID.AssetPathName.ComparisonIndex == 0)
				continue;

			auto ItemDef = RowStruct->ItemDefinition.Get();

			if (!ItemDef)
				continue;

			auto RowNameStr = ItemDef->Name.ToString();
			CORE_LOG(Loot, "Test: {}", RowNameStr);
			if (RowNameStr.contains("Resource"))
				Resources.push_back(ItemDef);
			else if (RowNameStr.contains("Ammo"))
				Ammo.push_back(ItemDef);
			else if (RowNameStr.contains("Consumable"))
				Consumables.push_back(ItemDef);
			else if (RowNameStr.compare("Weapon"))
			{
				switch (ItemDef->Tier)
				{
				case EFortItemTier::I:
					CommonWeapons.push_back(ItemDef);
					break;
				case EFortItemTier::II:
					UnCommonWeapons.push_back(ItemDef);
					break;
				case EFortItemTier::III:
					RareWeapons.push_back(ItemDef);
					break;
				case EFortItemTier::IV:
					EpicWeapons.push_back(ItemDef);
					break;
				case EFortItemTier::V:
					LegendaryWeapons.push_back(ItemDef);
					break;
				default:
					LegendaryWeapons.push_back(ItemDef);
					break;
				}
			}
		}
	}

	static int GetRandomRarity()
	{
		bool bEpicOrLeg = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomBoolWithWeight(0.07);

		int Index = 0;

		if (bEpicOrLeg)
		{
			Index = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomIntegerInRange(3, 4);
		}
		else {
			Index = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomIntegerInRange(0, 2);
		}

		return Index;
	}

	static UFortItemDefinition* GetRandomWeapon()
	{
		switch (GetRandomRarity())
		{
		case 0:
			return CommonWeapons[rand() % CommonWeapons.size()];
		case 1:
			return UnCommonWeapons[rand() % UnCommonWeapons.size()];
		case 2:
			return RareWeapons[rand() % RareWeapons.size()];
		case 3:
			return EpicWeapons[rand() % EpicWeapons.size()];
		case 4:
			return LegendaryWeapons[rand() % LegendaryWeapons.size()];
		}

		return nullptr;
	}
	
	static UFortItemDefinition* GetRandomAmmo()
	{
		return Ammo[rand() % Ammo.size()];
	}

	static UFortItemDefinition* GetRandomConsumable()
	{
		return Consumables[rand() % Consumables.size()];
	}

	static UFortItemDefinition* GetRandomResource()
	{
		return Resources[rand() % Resources.size()];
	}

	static void SpawnPickup(UFortItemDefinition* ItemDef, int Count, FVector Location, FRotator Rotation = {}, bool bTossedFromContainer = false)
	{
		if (ItemDef)
		{
			auto NewPickup = SpawnActor<AFortPickupAthena>(Location, Rotation);
			NewPickup->PrimaryPickupItemEntry.ItemDefinition = ItemDef;
			NewPickup->PrimaryPickupItemEntry.Count = Count;
			NewPickup->OnRep_PrimaryPickupItemEntry();

			NewPickup->TossPickup(Location, nullptr, 999, true);

			NewPickup->bTossedFromContainer = bTossedFromContainer;
			NewPickup->OnRep_TossedFromContainer();

			NewPickup->SetReplicateMovement(true);
			NewPickup->OnRep_ReplicateMovement();
			NewPickup->MovementComponent = (UProjectileMovementComponent*)GetDefaultObject<UGameplayStatics>()->STATIC_SpawnObject(UProjectileMovementComponent::StaticClass(), NewPickup);
		}
	}

	static void SpawnFloorLoot()
	{
		static auto FloorLootClass = UObject::FindObjectFast<UClass>("/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_01.Tiered_Athena_FloorLoot_01_C");

		TArray<AActor*> FloorLootActors;
		GetDefaultObject<UGameplayStatics>()->STATIC_GetAllActorsOfClass(GetWorld(), FloorLootClass, &FloorLootActors);

		for (int i = 0; i < FloorLootActors.Num(); i++)
		{
			auto FloorLootActor = FloorLootActors[i];

			if (FloorLootActor)
			{
				bool bIsConsumable = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomBoolWithWeight(0.4f);
				auto SpawnLocation = FloorLootActor->K2_GetActorLocation();
				auto bShouldSpawn = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomBoolWithWeight(0.7f);

				if (bShouldSpawn)
				{
					if (!bIsConsumable)
					{
						auto RandomWeapon = GetRandomWeapon();
						if (RandomWeapon)
						{
							SpawnPickup(RandomWeapon, 1, SpawnLocation);

							if (auto AmmoDef = ((UFortWorldItemDefinition*)RandomWeapon)->GetAmmoWorldItemDefinition_BP())
							{
								SpawnPickup(AmmoDef, AmmoDef->DropCount, SpawnLocation);
							}
						}
					}
					else {
						auto ConsumableDef = GetRandomConsumable();
						SpawnPickup(ConsumableDef, ((UFortWorldItemDefinition*)ConsumableDef)->DropCount, SpawnLocation);
					}
				}
			}
		}
	}


};