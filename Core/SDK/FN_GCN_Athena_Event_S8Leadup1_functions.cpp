// Fortnite (7.3) SDK
// Dumped with <3 by android#1337

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------------

// Function GCN_Athena_Event_S8Leadup1.GCN_Athena_Event_S8Leadup1_C.OnBurst
// (Event, Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// class AActor*                  MyTarget                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// struct FGameplayCueParameters  Parameters                     (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// TArray<class UParticleSystemComponent*> ParticleComponents             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
// TArray<class UAudioComponent*> AudioComponents                (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
// class UCameraShake*            BurstCameraShakeInstance       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// class ADecalActor*             BurstDecalInstance             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UGCN_Athena_Event_S8Leadup1_C::OnBurst(class AActor* MyTarget, struct FGameplayCueParameters Parameters, TArray<class UParticleSystemComponent*> ParticleComponents, TArray<class UAudioComponent*> AudioComponents, class UCameraShake* BurstCameraShakeInstance, class ADecalActor* BurstDecalInstance)
{
	static auto fn = UObject::FindObject<UFunction>("Function GCN_Athena_Event_S8Leadup1.GCN_Athena_Event_S8Leadup1_C.OnBurst");

	UGCN_Athena_Event_S8Leadup1_C_OnBurst_Params params;
	params.MyTarget = MyTarget;
	params.Parameters = Parameters;
	params.ParticleComponents = ParticleComponents;
	params.AudioComponents = AudioComponents;
	params.BurstCameraShakeInstance = BurstCameraShakeInstance;
	params.BurstDecalInstance = BurstDecalInstance;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function GCN_Athena_Event_S8Leadup1.GCN_Athena_Event_S8Leadup1_C.SpawnParticles
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                           Indoors                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// struct FVector                 Location                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UGCN_Athena_Event_S8Leadup1_C::SpawnParticles(bool Indoors, struct FVector Location)
{
	static auto fn = UObject::FindObject<UFunction>("Function GCN_Athena_Event_S8Leadup1.GCN_Athena_Event_S8Leadup1_C.SpawnParticles");

	UGCN_Athena_Event_S8Leadup1_C_SpawnParticles_Params params;
	params.Indoors = Indoors;
	params.Location = Location;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function GCN_Athena_Event_S8Leadup1.GCN_Athena_Event_S8Leadup1_C.ExecuteUbergraph_GCN_Athena_Event_S8Leadup1
// (Final)
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UGCN_Athena_Event_S8Leadup1_C::ExecuteUbergraph_GCN_Athena_Event_S8Leadup1(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function GCN_Athena_Event_S8Leadup1.GCN_Athena_Event_S8Leadup1_C.ExecuteUbergraph_GCN_Athena_Event_S8Leadup1");

	UGCN_Athena_Event_S8Leadup1_C_ExecuteUbergraph_GCN_Athena_Event_S8Leadup1_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
