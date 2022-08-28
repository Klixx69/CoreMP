#pragma once

class Inventory
{
public:
	static UFortWorldItem* FindItemFromDefinition(AFortPlayerController* PlayerController, UFortItemDefinition* ItemDef)
	{
		for (int i = 0; i < PlayerController->WorldInventory->Inventory.ItemInstances.Num(); i++)
		{
			auto ItemInstance = PlayerController->WorldInventory->Inventory.ItemInstances[i];

			if (ItemInstance->ItemEntry.ItemDefinition == ItemDef)
			{
				return ItemInstance;
			}
		}

		return nullptr;
	}

	static FFortItemEntry* FindEntryFromDefinition(AFortPlayerController* PlayerController, UFortItemDefinition* ItemDef)
	{
		for (int i = 0; i < PlayerController->WorldInventory->Inventory.ReplicatedEntries.Num(); i++)
		{
			auto Entry = &PlayerController->WorldInventory->Inventory.ReplicatedEntries[i];

			if (Entry->ItemDefinition == ItemDef)
			{
				return Entry;
			}
		}

		return nullptr;
	}

	static UFortWorldItem* FindItemFromGuid(AFortPlayerController* PlayerController, FGuid Guid)
	{
		for (int i = 0; i < PlayerController->WorldInventory->Inventory.ItemInstances.Num(); i++)
		{
			auto ItemInstance = PlayerController->WorldInventory->Inventory.ItemInstances[i];

			if (ItemInstance->ItemEntry.ItemGuid == Guid)
			{
				return ItemInstance;
			}
		}

		return nullptr;
	}

	static FFortItemEntry* FindEntryFromGuid(AFortPlayerController* PlayerController, FGuid Guid)
	{
		for (int i = 0; i < PlayerController->WorldInventory->Inventory.ReplicatedEntries.Num(); i++)
		{
			auto Entry = &PlayerController->WorldInventory->Inventory.ReplicatedEntries[i];

			if (Entry->ItemGuid == Guid)
			{
				return Entry;
			}
		}

		return nullptr;
	}

	static UFortWorldItem* CreateItem(UFortItemDefinition* ItemDef, int Count)
	{
		return Cast<UFortWorldItem>(ItemDef->CreateTemporaryItemInstanceBP(Count, 1));
	}

	static FGuid AddItem(AFortPlayerController* PlayerController, UFortWorldItem* Item)
	{
		PlayerController->WorldInventory->Inventory.ItemInstances.Add(Item);
		PlayerController->WorldInventory->Inventory.ReplicatedEntries.Add(Item->ItemEntry);

		return Item->ItemEntry.ItemGuid;
	}

	static FGuid AddItem(AFortPlayerController* PlayerController, UFortWorldItem* Item, EFortQuickBars QuickBarIndex, int Slot)
	{
		FGuid Guid = AddItem(PlayerController, Item);
		PlayerController->QuickBars->ServerAddItemInternal(Guid, QuickBarIndex, Slot);

		return Guid;
	}

	static FGuid AddItem(AFortPlayerController* PlayerController, UFortItemDefinition* ItemDef, int Count)
	{
		UFortWorldItem* Item = FindItemFromDefinition(PlayerController, ItemDef);
		if (Item != nullptr)
		{
			if ((Item->ItemEntry.Count + Count) > ItemDef->MaxStackSize)
				return Item->ItemEntry.ItemGuid;

			Item->ItemEntry.Count += Count;
			PlayerController->WorldInventory->Inventory.MarkItemDirty(Item->ItemEntry);

			auto Entry = FindEntryFromDefinition(PlayerController, ItemDef);
			Entry->Count += Count;
			PlayerController->WorldInventory->Inventory.MarkItemDirty(*Entry);

			return Entry->ItemGuid;
		}

		Item = CreateItem(ItemDef, Count);
		AddItem(PlayerController, Item);

		return Item->ItemEntry.ItemGuid;
	}

	static FGuid AddItem(AFortPlayerController* PlayerController, UFortItemDefinition* ItemDef, int Count, EFortQuickBars QuickBarIndex, int Slot)
	{
		auto Guid = AddItem(PlayerController, ItemDef, Count);
		PlayerController->QuickBars->ServerAddItemInternal(Guid, QuickBarIndex, Slot);

		return Guid;
	}

	static void RemoveItem(AFortPlayerController* PlayerController, FGuid Guid)
	{
		for (int i = 0; i < PlayerController->WorldInventory->Inventory.ItemInstances.Num(); i++)
		{
			if (PlayerController->WorldInventory->Inventory.ItemInstances[i]->ItemEntry.ItemGuid == Guid)
			{
				PlayerController->WorldInventory->Inventory.ItemInstances.Remove(i);

				for (int j = 0; j < PlayerController->WorldInventory->Inventory.ReplicatedEntries.Num(); j++)
				{
					if (PlayerController->WorldInventory->Inventory.ReplicatedEntries[j].ItemGuid == Guid)
					{
						PlayerController->WorldInventory->Inventory.ReplicatedEntries.Remove(j);
						break;
					}
				}
			}
		}
	}

	static void DropAllLootInInventory(AFortPlayerController* PlayerController)
	{

	}

	static void Setup(AFortPlayerController* PlayerController)
	{
		if (!PlayerController->QuickBars)
			PlayerController->QuickBars = SpawnActor<AFortQuickBarsAthena>();

		PlayerController->QuickBars->SetOwner(PlayerController);
		PlayerController->OnRep_QuickBar();

		static auto PickaxeDef = UObject::FindObjectFast<UFortItemDefinition>("/Game/Athena/Items/Weapons/WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");
		static auto WallDef = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/Weapons/BuildingTools/BuildingItemData_Wall.BuildingItemData_Wall");
		static auto FloorDef = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/Weapons/BuildingTools/BuildingItemData_Floor.BuildingItemData_Floor");
		static auto StairDef = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/Weapons/BuildingTools/BuildingItemData_Stair_W.BuildingItemData_Stair_W");
		static auto RoofDef = UObject::FindObjectFast<UFortItemDefinition>("/Game/Items/Weapons/BuildingTools/BuildingItemData_RoofS.BuildingItemData_RoofS");

		AddItem(PlayerController, PickaxeDef, 1, EFortQuickBars::Primary, 0);
		AddItem(PlayerController, WallDef, 1, EFortQuickBars::Secondary, 0);
		AddItem(PlayerController, FloorDef, 1, EFortQuickBars::Secondary, 1);
		AddItem(PlayerController, StairDef, 1, EFortQuickBars::Secondary, 2);
		AddItem(PlayerController, RoofDef, 1, EFortQuickBars::Secondary, 3);
	}

	static void Update(AFortPlayerController* PlayerController)
	{
		PlayerController->WorldInventory->Inventory.MarkArrayDirty();

		PlayerController->HandleWorldInventoryLocalUpdate();
		PlayerController->WorldInventory->HandleInventoryLocalUpdate();
		PlayerController->ForceUpdateQuickbar(EFortQuickBars::Primary);
		PlayerController->ForceUpdateQuickbar(EFortQuickBars::Secondary);
		PlayerController->WorldInventory->ForceNetUpdate();
		PlayerController->QuickBars->ForceNetUpdate();
	}
};