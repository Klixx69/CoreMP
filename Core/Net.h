#pragma once

class Net
{
public:
	static inline bool (*InitHost)(AOnlineBeaconHost*);
	static inline void (*SetWorld)(UNetDriver*, UWorld*);
	static inline void (*InitListen)(UNetDriver*, void*, FURL, bool, FString&);

	static void Listen()
	{
		auto Beacon = SpawnActor<AOnlineBeaconHost>();
		Beacon->ListenPort = 6969;
		InitHost(Beacon);

		Beacon->NetDriverName = FName(282);
		Beacon->NetDriver->NetDriverName = FName(282);
		Beacon->NetDriver->World = GetWorld();

		FURL Url;
		Url.Port = 7777;

		FString Error;

		InitListen((UIpNetDriver*)Beacon->NetDriver, GetWorld(), Url, false, Error);

		GetWorld()->NetDriver = Beacon->NetDriver;
		SetWorld(Beacon->NetDriver, GetWorld());

		GetWorld()->LevelCollections[0].NetDriver = Beacon->NetDriver;
		GetWorld()->LevelCollections[1].NetDriver = Beacon->NetDriver;

		if (!Beacon->NetDriver->ReplicationDriver)
		{
			static auto SetReplicationDriver = reinterpret_cast<void(*)(UNetDriver*, UReplicationDriver*)>(Util::BaseAddress() + 0x29CC930);
			SetReplicationDriver(Beacon->NetDriver, NewObject<UFortReplicationGraph>(Beacon->NetDriver));
		}
	}

	static void Init()
	{
		InitHost = decltype(InitHost)(Util::BaseAddress() + 0x4588A0);
		SetWorld = decltype(SetWorld)(Util::BaseAddress() + 0x29CCCC0);
		InitListen = decltype(InitListen)(Util::BaseAddress() + 0x458C90);
	}
};