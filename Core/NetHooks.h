#pragma once

class NetHooks
{
public:
	static inline void (*ServerReplicateActors)(UReplicationGraph* RepGraph);

	static inline void (*TickFlush)(UNetDriver*);
	static inline void TickFlushHook(UNetDriver* NetDriver)
	{
		if (NetDriver->ReplicationDriver)
		{
			ServerReplicateActors((UReplicationGraph*)NetDriver->ReplicationDriver);
		}

		return TickFlush(NetDriver);
	}

	static inline void (*SetClientLoginState)(UNetConnection*, uint8_t);
	static inline void SetClientLoginStateHook(UNetConnection* NetConnection, uint8_t State)
	{
		if (State == 3)
		{
			static bool bSpawnedFloorLoot = false;
			if (!bSpawnedFloorLoot)
			{
				bSpawnedFloorLoot = true;
				Loot::SpawnFloorLoot();
			}

			auto PlayerController = (AFortPlayerControllerAthena*)(NetConnection->PlayerController);

			auto Pawn = SpawnActor<AFortPlayerPawnAthena>(GetPlayerStartLocation(), { 0,0,0 }, Core::PawnClass);
			Pawn->bCanBeDamaged = false;
			PlayerController->Possess(Pawn);

			static auto NoBackpackQuestionMark = UObject::FindObjectFast<UCustomCharacterPart>("/Game/Characters/CharacterParts/Backpacks/NoBackpack.NoBackpack");
			static auto HeadPart = UObject::FindObjectFast<UCustomCharacterPart>("/Game/Characters/CharacterParts/Female/Medium/Heads/F_Med_Head1.F_Med_Head1");
			static auto BodyPart = UObject::FindObjectFast<UCustomCharacterPart>("/Game/Characters/CharacterParts/Female/Medium/Bodies/F_Med_Soldier_01.F_Med_Soldier_01");

			Pawn->ServerChoosePart(EFortCustomPartType::Head, HeadPart);
			Pawn->ServerChoosePart(EFortCustomPartType::Body, BodyPart);
			Pawn->ServerChoosePart(EFortCustomPartType::Backpack, NoBackpackQuestionMark);
			((AFortPlayerState*)Pawn->PlayerState)->OnRep_CharacterParts();

			PlayerController->bHasServerFinishedLoading = true;
			PlayerController->OnRep_bHasServerFinishedLoading();

			PlayerController->OverriddenBackpackSize = 5;

			auto PlayerState = (AFortPlayerStateAthena*)(PlayerController->PlayerState);

			PlayerState->OnRep_SquadId();

			PlayerState->bHasFinishedLoading = true;
			PlayerState->bHasStartedPlaying = true;
			PlayerState->OnRep_bHasStartedPlaying();

			Abilities::GiveAbilities(Pawn);
			Inventory::Setup(PlayerController);
			Inventory::Update(PlayerController);
		}

		return SetClientLoginState(NetConnection, State);
	}

	static inline char KickPatch(int64 a1, int64 a2)
	{
		return 0;
	}

	static void Init()
	{
		ServerReplicateActors = decltype(ServerReplicateActors)(Util::BaseAddress() + 0x788D40);
		CREATE_HOOK(Util::BaseAddress() + 0x29CE460, TickFlushHook, &TickFlush);
		CREATE_HOOK(Util::BaseAddress() + 0x29CBA40, SetClientLoginStateHook, &SetClientLoginState);
		CREATE_HOOK(Util::BaseAddress() + 0x1251DA0, KickPatch, nullptr);
	}
};