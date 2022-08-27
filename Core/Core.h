#pragma once

class Core
{
public:
	static inline bool bIsInProgress = false;

	static inline UFortEngine* FortEngine;
	static inline UClass* PawnClass;

public:
	static inline void Init()
	{
		FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
		PawnClass = APlayerPawn_Athena_C::StaticClass();


	}
};

inline UFortEngine* GetEngine()
{
	if (!Core::FortEngine)
		Core::FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");

	return Core::FortEngine;
}

inline UWorld* GetWorld()
{
	return Core::FortEngine->GameViewport->World;
}

template <typename T>
inline T* GetDefaultObject()
{
	return T::StaticClass()->CreateDefaultObject<T>();
}

inline APlayerController* GetLocalPlayerController()
{
	return GetDefaultObject<UGameplayStatics>()->STATIC_GetPlayerController(GetWorld(), 0);
}