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

// Function BattlePassGiftReceived.BattlePassGiftReceived_C.BndEvt__ShowNextButton_K2Node_ComponentBoundEvent
// (BlueprintEvent)
// Parameters:
// class UCommonButton*           Button                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)

void UBattlePassGiftReceived_C::BndEvt__ShowNextButton_K2Node_ComponentBoundEvent(class UCommonButton* Button)
{
	static auto fn = UObject::FindObject<UFunction>("Function BattlePassGiftReceived.BattlePassGiftReceived_C.BndEvt__ShowNextButton_K2Node_ComponentBoundEvent");

	UBattlePassGiftReceived_C_BndEvt__ShowNextButton_K2Node_ComponentBoundEvent_Params params;
	params.Button = Button;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function BattlePassGiftReceived.BattlePassGiftReceived_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UBattlePassGiftReceived_C::Construct()
{
	static auto fn = UObject::FindObject<UFunction>("Function BattlePassGiftReceived.BattlePassGiftReceived_C.Construct");

	UBattlePassGiftReceived_C_Construct_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function BattlePassGiftReceived.BattlePassGiftReceived_C.ExecuteUbergraph_BattlePassGiftReceived
// (Final)
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UBattlePassGiftReceived_C::ExecuteUbergraph_BattlePassGiftReceived(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function BattlePassGiftReceived.BattlePassGiftReceived_C.ExecuteUbergraph_BattlePassGiftReceived");

	UBattlePassGiftReceived_C_ExecuteUbergraph_BattlePassGiftReceived_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
