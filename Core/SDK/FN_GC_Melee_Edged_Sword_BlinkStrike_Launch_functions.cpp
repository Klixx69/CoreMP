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

// Function GC_Melee_Edged_Sword_BlinkStrike_Launch.GC_Melee_Edged_Sword_BlinkStrike_Launch_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AGC_Melee_Edged_Sword_BlinkStrike_Launch_C::UserConstructionScript()
{
	static auto fn = UObject::FindObject<UFunction>("Function GC_Melee_Edged_Sword_BlinkStrike_Launch.GC_Melee_Edged_Sword_BlinkStrike_Launch_C.UserConstructionScript");

	AGC_Melee_Edged_Sword_BlinkStrike_Launch_C_UserConstructionScript_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function GC_Melee_Edged_Sword_BlinkStrike_Launch.GC_Melee_Edged_Sword_BlinkStrike_Launch_C.OnLoopingStart
// (Event, Public, HasOutParms, BlueprintEvent)
// Parameters:
// class AActor*                  MyTarget                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// struct FGameplayCueParameters  Parameters                     (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// TArray<class UParticleSystemComponent*> ParticleComponents             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
// TArray<class UAudioComponent*> AudioComponents                (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)

void AGC_Melee_Edged_Sword_BlinkStrike_Launch_C::OnLoopingStart(class AActor* MyTarget, struct FGameplayCueParameters Parameters, TArray<class UParticleSystemComponent*> ParticleComponents, TArray<class UAudioComponent*> AudioComponents)
{
	static auto fn = UObject::FindObject<UFunction>("Function GC_Melee_Edged_Sword_BlinkStrike_Launch.GC_Melee_Edged_Sword_BlinkStrike_Launch_C.OnLoopingStart");

	AGC_Melee_Edged_Sword_BlinkStrike_Launch_C_OnLoopingStart_Params params;
	params.MyTarget = MyTarget;
	params.Parameters = Parameters;
	params.ParticleComponents = ParticleComponents;
	params.AudioComponents = AudioComponents;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function GC_Melee_Edged_Sword_BlinkStrike_Launch.GC_Melee_Edged_Sword_BlinkStrike_Launch_C.OnRemoval
// (Event, Public, HasOutParms, BlueprintEvent)
// Parameters:
// class AActor*                  MyTarget                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// struct FGameplayCueParameters  Parameters                     (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// TArray<class UParticleSystemComponent*> ParticleComponents             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
// TArray<class UAudioComponent*> AudioComponents                (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
// class UCameraShake*            BurstCameraShakeInstance       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// class ADecalActor*             BurstDecalInstance             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void AGC_Melee_Edged_Sword_BlinkStrike_Launch_C::OnRemoval(class AActor* MyTarget, struct FGameplayCueParameters Parameters, TArray<class UParticleSystemComponent*> ParticleComponents, TArray<class UAudioComponent*> AudioComponents, class UCameraShake* BurstCameraShakeInstance, class ADecalActor* BurstDecalInstance)
{
	static auto fn = UObject::FindObject<UFunction>("Function GC_Melee_Edged_Sword_BlinkStrike_Launch.GC_Melee_Edged_Sword_BlinkStrike_Launch_C.OnRemoval");

	AGC_Melee_Edged_Sword_BlinkStrike_Launch_C_OnRemoval_Params params;
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


// Function GC_Melee_Edged_Sword_BlinkStrike_Launch.GC_Melee_Edged_Sword_BlinkStrike_Launch_C.ExecuteUbergraph_GC_Melee_Edged_Sword_BlinkStrike_Launch
// (Final, HasDefaults)
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void AGC_Melee_Edged_Sword_BlinkStrike_Launch_C::ExecuteUbergraph_GC_Melee_Edged_Sword_BlinkStrike_Launch(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function GC_Melee_Edged_Sword_BlinkStrike_Launch.GC_Melee_Edged_Sword_BlinkStrike_Launch_C.ExecuteUbergraph_GC_Melee_Edged_Sword_BlinkStrike_Launch");

	AGC_Melee_Edged_Sword_BlinkStrike_Launch_C_ExecuteUbergraph_GC_Melee_Edged_Sword_BlinkStrike_Launch_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
