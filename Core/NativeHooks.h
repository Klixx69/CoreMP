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

		ServerUpdateLevelVisibility(PlayerController, PackageName, bIsVisible);
	}

	static inline void (*ServerAcknowledgePossession)(APlayerController* PlayerController, APawn* P);
	static inline void ServerAcknowledgePossessionHook(APlayerController* PlayerController, APawn* P)
	{
		PlayerController->AcknowledgedPawn = P;
	}

	static void Init()
	{
		auto DefaultPC = UObject::FindObject<AFortPlayerControllerAthena>("Default__Athena_PlayerController");

		CREATE_HOOK(Util::BaseAddress() + 0x2AF8910, ServerUpdateLevelVisibilityHook, &ServerUpdateLevelVisibility);
		
		VIRTUAL_HOOK(DefaultPC, 261, ServerAcknowledgePossessionHook, &ServerAcknowledgePossession);
	}
};