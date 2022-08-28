#pragma once

#define SOLO
//#define DUO
//#define SQUAD
//#define PLAYGROUND
//#define LATEGAME

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

template <typename T>
inline T* SpawnActor(FVector Loc = {}, FRotator Rot = {}, UClass* ActorClass = T::StaticClass())
{
	FQuat Quat;
	FTransform Transform;

	auto DEG_TO_RAD = 3.14159 / 180;
	auto DIVIDE_BY_2 = DEG_TO_RAD / 2;

	auto SP = sin(Rot.Pitch * DIVIDE_BY_2);
	auto CP = cos(Rot.Pitch * DIVIDE_BY_2);

	auto SY = sin(Rot.Yaw * DIVIDE_BY_2);
	auto CY = cos(Rot.Yaw * DIVIDE_BY_2);

	auto SR = sin(Rot.Roll * DIVIDE_BY_2);
	auto CR = cos(Rot.Roll * DIVIDE_BY_2);

	Quat.X = CR * SP * SY - SR * CP * CY;
	Quat.Y = -CR * SP * CY - SR * CP * SY;
	Quat.Z = CR * CP * SY - SR * SP * CY;
	Quat.W = CR * CP * CY + SR * SP * SY;

	Transform.Rotation = Quat;
	Transform.Scale3D = FVector{ 1,1,1 };
	Transform.Translation = Loc;

	auto Actor = GetDefaultObject<UGameplayStatics>()->STATIC_BeginSpawningActorFromClass(GetWorld(), ActorClass, Transform, false, nullptr);
	GetDefaultObject<UGameplayStatics>()->STATIC_FinishSpawningActor(Actor, Transform);
	return (T*)Actor;
}

template <typename T>
inline T* Cast(void* ToCast)
{
	return (T*)ToCast;
}

template <typename T>
inline T* NewObject(UObject* Outer, UClass* ObjClass = T::StaticClass())
{
	return (T*)GetDefaultObject<UGameplayStatics>()->STATIC_SpawnObject(ObjClass, Outer);
}

inline FVector GetPlayerStartLocation()
{
	TArray<AActor*> PlayerStarts;
	GetDefaultObject<UGameplayStatics>()->STATIC_GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), &PlayerStarts);
	return PlayerStarts[rand() % PlayerStarts.Num()]->K2_GetActorLocation();
}