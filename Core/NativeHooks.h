#pragma once

class NativeHooks
{
public:
	static inline void (*ServerUpdateLevelVisibility)(APlayerController* PlayerController, FName PackageName, bool bIsVisible);
	static inline void ServerUpdateLevelVisibilityHook(APlayerController* PlayerController, FName PackageName, bool bIsVisible)
	{
		if (PackageName.ToString().starts_with("Athena_SUB_5x5_House_"))
		{
			static bool bSetup = false;
			if (!bSetup)
			{
				bSetup = true;

				NewObject<UCheatManager>(GetLocalPlayerController())->DestroyAll(APlayerController::StaticClass());
					
#if defined(SOLO)
				auto Playlist = UObject::FindObjectFast<UFortPlaylistAthena>("/Game/Athena/Playlists/Playlist_DefaultSolo.Playlist_DefaultSolo");
#elif defined(DUO)
				auto Playlist = UObject::FindObjectFast<UFortPlaylistAthena>("/Game/Athena/Playlists/Playlist_DefaultDuo.Playlist_DefaultDuo");
#elif defined(PLAYGROUND)
				auto Playlist = UObject::FindObjectFast<UFortPlaylistAthena>("/Game/Athena/Playlists/Playground/Playlist_Playground.Playlist_Playground");
#elif defined(LATEGAME)
				auto Playlist = UObject::FindObjectFast<UFortPlaylistAthena>("/Game/Athena/Playlists/Playlist_DefaultSolo.Playlist_DefaultSolo");
#endif

				auto AthenaGameState = Cast<AFortGameStateAthena>(GetWorld()->GameState);
				AthenaGameState->CurrentPlaylistInfo.BasePlaylist = Playlist;
				AthenaGameState->CurrentPlaylistInfo.OverridePlaylist = Playlist;
				AthenaGameState->CurrentPlaylistInfo.PlaylistReplicationKey++;
				AthenaGameState->CurrentPlaylistInfo.MarkArrayDirty();
				AthenaGameState->OnRep_CurrentPlaylistInfo();

				auto AthenaGameMode = Cast<AFortGameModeAthena>(GetWorld()->AuthorityGameMode);
				AthenaGameMode->GameSession->MaxPlayers = 100;

				AthenaGameMode->StartMatch();
				AthenaGameMode->StartPlay();

				Net::Listen();
			}
		}

		return ServerUpdateLevelVisibility(PlayerController, PackageName, bIsVisible);
	}

	static inline void ServerAcknowledgePossessionHook(APlayerController* PlayerController, APawn* P)
	{
		PlayerController->AcknowledgedPawn = P;
	}

	static inline void ServerAttemptAircraftJumpHook(AFortPlayerControllerAthena* PlayerController, FRotator ClientRotation)
	{
		if (PlayerController->Pawn)
			return;

		auto Pawn = SpawnActor<APlayerPawn_Athena_C>(Cast<AFortGameStateAthena>(GetWorld()->GameState)->GetAircraft(0)->K2_GetActorLocation());
		PlayerController->Possess(Pawn);

		PlayerController->SetControlRotation(ClientRotation);
	}
	
	static void ServerTryActivateAbilityWithEventDataHook(UAbilitySystemComponent* Comp, FGameplayAbilitySpecHandle AbilityToActivate, bool InputPressed, FPredictionKey PredictionKey, FGameplayEventData TriggerEventData)
	{
		FGameplayAbilitySpec* Spec = Abilities::FindAbilitySpecFromHandle(Comp, AbilityToActivate);
		if (!Spec)
		{
			CORE_LOG(Abilities, "InternalServerTryActiveAbility. Rejecting ClientActivation of ability with invalid SpecHandle!");
			Comp->ClientActivateAbilityFailed(AbilityToActivate, PredictionKey.Current);
			return;
		}

		UGameplayAbility* AbilityToActivate_ = Spec->Ability;

		UGameplayAbility* InstancedAbility = nullptr;
		Spec->InputPressed = true;

		if (Abilities::InternalTryActivateAbility(Comp, AbilityToActivate, PredictionKey, &InstancedAbility, nullptr, &TriggerEventData))
		{

		}
		else {
			CORE_LOG(Abilities, "InternalServerTryActiveAbility. Rejecting ClientActivation of {}. InternalTryActivateAbility failed!", AbilityToActivate_->GetName());
			Comp->ClientActivateAbilityFailed(AbilityToActivate, PredictionKey.Current);
			Spec->InputPressed = false;
		}
	}

	static void ServerTryActivateAbilityHook(UAbilitySystemComponent* Comp, FGameplayAbilitySpecHandle AbilityToActivate, bool InputPressed, FPredictionKey PredictionKey)
	{
		FGameplayAbilitySpec* Spec = Abilities::FindAbilitySpecFromHandle(Comp, AbilityToActivate);
		if (!Spec)
		{
			CORE_LOG(Abilities, "InternalServerTryActiveAbility. Rejecting ClientActivation of ability with invalid SpecHandle!");
			Comp->ClientActivateAbilityFailed(AbilityToActivate, PredictionKey.Current);
			return;
		}

		UGameplayAbility* AbilityToActivate_ = Spec->Ability;

		UGameplayAbility* InstancedAbility = nullptr;
		Spec->InputPressed = true;

		if (Abilities::InternalTryActivateAbility(Comp, AbilityToActivate, PredictionKey, &InstancedAbility, nullptr, nullptr))
		{

		}
		else {
			CORE_LOG(Abilities, "InternalServerTryActiveAbility. Rejecting ClientActivation of {}. InternalTryActivateAbility failed!", AbilityToActivate_->GetName());
			Comp->ClientActivateAbilityFailed(AbilityToActivate, PredictionKey.Current);
			Spec->InputPressed = false;
		}
	}

	static void ServerAbilityRPCBatchHook(UAbilitySystemComponent* Comp, FServerAbilityRPCBatch& BatchInfo)
	{
		Comp->ServerTryActivateAbility(BatchInfo.AbilitySpecHandle, BatchInfo.InputPressed, BatchInfo.PredictionKey);
		Comp->ServerSetReplicatedTargetData(BatchInfo.AbilitySpecHandle, BatchInfo.PredictionKey, BatchInfo.TargetData, FGameplayTag(), BatchInfo.PredictionKey);

		if (BatchInfo.Ended)
		{
			FGameplayAbilityActivationInfo FakeInfo = FGameplayAbilityActivationInfo();
			FakeInfo.PredictionKeyWhenActivated = BatchInfo.PredictionKey;
			Comp->ServerEndAbility(BatchInfo.AbilitySpecHandle, FakeInfo, BatchInfo.PredictionKey);
		}
	}

	static void ServerExecuteInventoryItemHook(AFortPlayerControllerAthena* PlayerController, FGuid ItemGuid)
	{
		if (PlayerController->IsInAircraft())
			return;

		auto WorldInventory = PlayerController->WorldInventory;

		for (int i = 0; i < WorldInventory->Inventory.ReplicatedEntries.Num(); i++)
		{
			auto Entry = WorldInventory->Inventory.ReplicatedEntries[i];

			if (Entry.ItemGuid == ItemGuid)
			{
				if (PlayerController->Pawn) {
					((AFortPlayerPawn*)PlayerController->Pawn)->EquipWeaponDefinition((UFortWeaponItemDefinition*)(Entry.ItemDefinition), Entry.ItemGuid);
				}
			}
		}
	}

	static inline void (*OnDamageServer)(ABuildingActor* BuildingActor, float Damage, FGameplayTagContainer DamageTags, FVector Momentum, FHitResult HitInfo, AController* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);
	static void OnDamageServerHook(ABuildingSMActor* BuildingActor, float Damage, FGameplayTagContainer DamageTags, FVector Momentum, FHitResult HitInfo, AController* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext)
	{
		bool bHitWeakPoint = Damage == 100;

		if (InstigatedBy && InstigatedBy->IsA(AFortPlayerController::StaticClass()) && !BuildingActor->bPlayerPlaced)
		{
			auto FortController = (AFortPlayerController*)InstigatedBy;

			if (bHitWeakPoint)
			{
				if (FortController->MyFortPawn)
				{
					if (FortController->MyFortPawn->CurrentWeapon) {
						if (FortController->MyFortPawn->CurrentWeapon->WeaponData == UObject::FindObjectFast<UFortWeaponMeleeItemDefinition>("/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Assassin.WID_Harvest_Pickaxe_Assassin"))
						{
							bool bLess = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomBoolWithWeight(0.8f);
							if (bLess)
							{
								int PotentialResourceCount = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomIntegerInRange(4, 9);
								FortController->ClientReportDamagedResourceBuilding(BuildingActor, BuildingActor->ResourceType, PotentialResourceCount, false, bHitWeakPoint);

								auto ResourceType = BuildingActor->ResourceType;
								auto ResourceCount = PotentialResourceCount;

								static auto WoodDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
								static auto StoneDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/StoneItemData.StoneItemData");
								static auto MetalDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/MetalItemData.MetalItemData");

								UFortItemDefinition* CurrentResourceDefinition = nullptr;

								switch (ResourceType)
								{
								case EFortResourceType::Wood:
									CurrentResourceDefinition = WoodDefinition;
									break;
								case EFortResourceType::Stone:
									CurrentResourceDefinition = StoneDefinition;
									break;
								case EFortResourceType::Metal:
									CurrentResourceDefinition = MetalDefinition;
									break;
								default:
									CurrentResourceDefinition = WoodDefinition;
									break;
								}

								Inventory::AddItem(FortController, CurrentResourceDefinition, ResourceCount);
								Inventory::Update(FortController);
							}
							else {
								int PotentialResourceCount = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomIntegerInRange(3, 7);
								FortController->ClientReportDamagedResourceBuilding(BuildingActor, BuildingActor->ResourceType, PotentialResourceCount, false, bHitWeakPoint);

								auto ResourceType = BuildingActor->ResourceType;
								auto ResourceCount = PotentialResourceCount;

								static auto WoodDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
								static auto StoneDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/StoneItemData.StoneItemData");
								static auto MetalDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/MetalItemData.MetalItemData");

								UFortItemDefinition* CurrentResourceDefinition = nullptr;

								switch (ResourceType)
								{
								case EFortResourceType::Wood:
									CurrentResourceDefinition = WoodDefinition;
									break;
								case EFortResourceType::Stone:
									CurrentResourceDefinition = StoneDefinition;
									break;
								case EFortResourceType::Metal:
									CurrentResourceDefinition = MetalDefinition;
									break;
								default:
									CurrentResourceDefinition = WoodDefinition;
									break;
								}

								Inventory::AddItem(FortController, CurrentResourceDefinition, ResourceCount);
								Inventory::Update(FortController);
							}
						}
					}
				}
			}
			else {
				if (FortController->MyFortPawn)
				{
					if (FortController->MyFortPawn->CurrentWeapon) {
						if (FortController->MyFortPawn->CurrentWeapon->WeaponData == UObject::FindObjectFast<UFortWeaponMeleeItemDefinition>("/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Assassin.WID_Harvest_Pickaxe_Assassin"))
						{
							bool bLess = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomBoolWithWeight(0.8f);
							if (bLess)
							{
								int PotentialResourceCount = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomIntegerInRange(2, 4);
								FortController->ClientReportDamagedResourceBuilding(BuildingActor, BuildingActor->ResourceType, PotentialResourceCount, false, bHitWeakPoint);

								auto ResourceType = BuildingActor->ResourceType;
								auto ResourceCount = PotentialResourceCount;

								static auto WoodDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
								static auto StoneDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/StoneItemData.StoneItemData");
								static auto MetalDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/MetalItemData.MetalItemData");

								UFortItemDefinition* CurrentResourceDefinition = nullptr;

								switch (ResourceType)
								{
								case EFortResourceType::Wood:
									CurrentResourceDefinition = WoodDefinition;
									break;
								case EFortResourceType::Stone:
									CurrentResourceDefinition = StoneDefinition;
									break;
								case EFortResourceType::Metal:
									CurrentResourceDefinition = MetalDefinition;
									break;
								default:
									CurrentResourceDefinition = WoodDefinition;
									break;
								}

								Inventory::AddItem(FortController, CurrentResourceDefinition, ResourceCount);
								Inventory::Update(FortController);
							}
							else {
								int PotentialResourceCount = GetDefaultObject<UKismetMathLibrary>()->STATIC_RandomIntegerInRange(2, 6);
								FortController->ClientReportDamagedResourceBuilding(BuildingActor, BuildingActor->ResourceType, PotentialResourceCount, false, bHitWeakPoint);

								auto ResourceType = BuildingActor->ResourceType;
								auto ResourceCount = PotentialResourceCount;

								static auto WoodDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
								static auto StoneDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/StoneItemData.StoneItemData");
								static auto MetalDefinition = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/ResourcePickups/MetalItemData.MetalItemData");

								UFortItemDefinition* CurrentResourceDefinition = nullptr;

								switch (ResourceType)
								{
								case EFortResourceType::Wood:
									CurrentResourceDefinition = WoodDefinition;
									break;
								case EFortResourceType::Stone:
									CurrentResourceDefinition = StoneDefinition;
									break;
								case EFortResourceType::Metal:
									CurrentResourceDefinition = MetalDefinition;
									break;
								default:
									CurrentResourceDefinition = WoodDefinition;
									break;
								}

								Inventory::AddItem(FortController, CurrentResourceDefinition, ResourceCount);
								Inventory::Update(FortController);
							}
						}
					}
				}
			}
		}

		return OnDamageServer(BuildingActor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);
	}

	static void Init()
	{
		auto DefaultPC = UObject::FindObject<AFortPlayerControllerAthena>("Default__Athena_PlayerController");
		auto DefaultAbilityComp = UObject::FindObject<UFortAbilitySystemComponentAthena>("Default__FortAbilitySystemComponentAthena");

		CREATE_HOOK(Util::BaseAddress() + 0x2AF8910, ServerUpdateLevelVisibilityHook, &ServerUpdateLevelVisibility);
		CREATE_HOOK(Util::BaseAddress() + 0x177B4D0, OnDamageServerHook, &OnDamageServer);

		VIRTUAL_HOOK(DefaultPC, 261, ServerAcknowledgePossessionHook, nullptr);
		VIRTUAL_HOOK(DefaultPC, 1061, ServerAttemptAircraftJumpHook, nullptr);
		VIRTUAL_HOOK(DefaultPC, 500, ServerExecuteInventoryItemHook, nullptr);

		VIRTUAL_HOOK(DefaultAbilityComp, 140, ServerTryActivateAbilityHook, nullptr);
		VIRTUAL_HOOK(DefaultAbilityComp, 138, ServerTryActivateAbilityWithEventDataHook, nullptr);
		VIRTUAL_HOOK(DefaultAbilityComp, 155, ServerAbilityRPCBatchHook, nullptr);

	}
};