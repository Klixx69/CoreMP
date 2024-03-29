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

// Function GA_SiphonEffect_OnKillGrant.GA_SiphonEffect_OnKillGrant_C.K2_ShouldAbilityRespondToEvent
// (Event, Protected, HasOutParms, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// struct FGameplayAbilityActorInfo ActorInfo                      (BlueprintVisible, BlueprintReadOnly, Parm)
// struct FGameplayEventData      Payload                        (BlueprintVisible, BlueprintReadOnly, Parm)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UGA_SiphonEffect_OnKillGrant_C::K2_ShouldAbilityRespondToEvent(struct FGameplayAbilityActorInfo ActorInfo, struct FGameplayEventData Payload)
{
	static auto fn = UObject::FindObject<UFunction>("Function GA_SiphonEffect_OnKillGrant.GA_SiphonEffect_OnKillGrant_C.K2_ShouldAbilityRespondToEvent");

	UGA_SiphonEffect_OnKillGrant_C_K2_ShouldAbilityRespondToEvent_Params params;
	params.ActorInfo = ActorInfo;
	params.Payload = Payload;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function GA_SiphonEffect_OnKillGrant.GA_SiphonEffect_OnKillGrant_C.K2_ActivateAbilityFromEvent
// (Event, Protected, HasOutParms, BlueprintEvent)
// Parameters:
// struct FGameplayEventData      EventData                      (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UGA_SiphonEffect_OnKillGrant_C::K2_ActivateAbilityFromEvent(struct FGameplayEventData EventData)
{
	static auto fn = UObject::FindObject<UFunction>("Function GA_SiphonEffect_OnKillGrant.GA_SiphonEffect_OnKillGrant_C.K2_ActivateAbilityFromEvent");

	UGA_SiphonEffect_OnKillGrant_C_K2_ActivateAbilityFromEvent_Params params;
	params.EventData = EventData;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function GA_SiphonEffect_OnKillGrant.GA_SiphonEffect_OnKillGrant_C.ExecuteUbergraph_GA_SiphonEffect_OnKillGrant
// (Final, HasDefaults)
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UGA_SiphonEffect_OnKillGrant_C::ExecuteUbergraph_GA_SiphonEffect_OnKillGrant(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function GA_SiphonEffect_OnKillGrant.GA_SiphonEffect_OnKillGrant_C.ExecuteUbergraph_GA_SiphonEffect_OnKillGrant");

	UGA_SiphonEffect_OnKillGrant_C_ExecuteUbergraph_GA_SiphonEffect_OnKillGrant_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
