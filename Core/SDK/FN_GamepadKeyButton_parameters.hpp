#pragma once

// Fortnite (7.3) SDK
// Dumped with <3 by android#1337

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Parameters
//---------------------------------------------------------------------------

// Function GamepadKeyButton.GamepadKeyButton_C.SetContentAlignment
struct UGamepadKeyButton_C_SetContentAlignment_Params
{
	TEnumAsByte<EHorizontalAlignment>                  ContentAlignment;                                         // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function GamepadKeyButton.GamepadKeyButton_C.UpdateContentAlignment
struct UGamepadKeyButton_C_UpdateContentAlignment_Params
{
};

// Function GamepadKeyButton.GamepadKeyButton_C.SetTabLabelInfo
struct UGamepadKeyButton_C_SetTabLabelInfo_Params
{
	struct FFortTabButtonLabelInfo                     TabLabelInfo;                                             // (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function GamepadKeyButton.GamepadKeyButton_C.PreConstruct
struct UGamepadKeyButton_C_PreConstruct_Params
{
	bool                                               IsDesignTime;                                             // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function GamepadKeyButton.GamepadKeyButton_C.OnTriggeredInputActionChanged
struct UGamepadKeyButton_C_OnTriggeredInputActionChanged_Params
{
	struct FDataTableRowHandle                         NewTriggeredAction;                                       // (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function GamepadKeyButton.GamepadKeyButton_C.BndEvt__InputActionWidget_K2Node_ComponentBoundEvent
struct UGamepadKeyButton_C_BndEvt__InputActionWidget_K2Node_ComponentBoundEvent_Params
{
	bool                                               bUsingGamepad;                                            // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function GamepadKeyButton.GamepadKeyButton_C.ExecuteUbergraph_GamepadKeyButton
struct UGamepadKeyButton_C_ExecuteUbergraph_GamepadKeyButton_Params
{
	int                                                EntryPoint;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
