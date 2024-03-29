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

// Function TabGamePadConfig.TabGamePadConfig_C.SetupDisplayObject
struct UTabGamePadConfig_C_SetupDisplayObject_Params
{
	int                                                InputIndex;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class UOptionsMenuInputOneKeyDisplayOnly_C*        ReturnObject;                                             // (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.InputCommonListViewNav
struct UTabGamePadConfig_C_InputCommonListViewNav_Params
{
	EUINavigation                                      Navigation;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class UWidget*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.CustomInputTemplateConfigsNav
struct UTabGamePadConfig_C_CustomInputTemplateConfigsNav_Params
{
	EUINavigation                                      Navigation;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class UWidget*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.GamepadPlatformConfigNav
struct UTabGamePadConfig_C_GamepadPlatformConfigNav_Params
{
	EUINavigation                                      Navigation;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class UWidget*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.IsConsole
struct UTabGamePadConfig_C_IsConsole_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.GamepadConfigNav
struct UTabGamePadConfig_C_GamepadConfigNav_Params
{
	EUINavigation                                      Navigation;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class UWidget*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.GetCurrentPlatformIndex
struct UTabGamePadConfig_C_GetCurrentPlatformIndex_Params
{
	int                                                Platform_Index;                                           // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.IsCustomConfig
struct UTabGamePadConfig_C_IsCustomConfig_Params
{
	int                                                PresetIndex;                                              // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.SetInputEnabled
struct UTabGamePadConfig_C_SetInputEnabled_Params
{
	bool                                               Enable;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.OverlayKeyPressed
struct UTabGamePadConfig_C_OverlayKeyPressed_Params
{
	struct FKey                                        NewKey;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm)
};

// Function TabGamePadConfig.TabGamePadConfig_C.HandleGamepadMappingInfoChange
struct UTabGamePadConfig_C_HandleGamepadMappingInfoChange_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.Handle Mode Toggled
struct UTabGamePadConfig_C_Handle_Mode_Toggled_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.Update Data
struct UTabGamePadConfig_C_Update_Data_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.Initialize Data
struct UTabGamePadConfig_C_Initialize_Data_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.DialogResult
struct UTabGamePadConfig_C_DialogResult_Params
{
	EFortDialogResult                                  Result;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FName                                       ResultName;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.CenterOnTab
struct UTabGamePadConfig_C_CenterOnTab_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.Gamepad Config Changed
struct UTabGamePadConfig_C_Gamepad_Config_Changed_Params
{
	int                                                Selected_Index;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.UpdateOptionsTab
struct UTabGamePadConfig_C_UpdateOptionsTab_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.GamepadPlatformConfigChanged
struct UTabGamePadConfig_C_GamepadPlatformConfigChanged_Params
{
	int                                                Selected_Index;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.Configuration Changed
struct UTabGamePadConfig_C_Configuration_Changed_Params
{
	int                                                Selected_Index;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.Construct
struct UTabGamePadConfig_C_Construct_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.ClearAndConstructKeybindList
struct UTabGamePadConfig_C_ClearAndConstructKeybindList_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.BndEvt__InputCommonListView_K2Node_ComponentBoundEvent
struct UTabGamePadConfig_C_BndEvt__InputCommonListView_K2Node_ComponentBoundEvent_Params
{
	class UUserWidget*                                 Widget;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.InputClicked_Bind
struct UTabGamePadConfig_C_InputClicked_Bind_Params
{
	int                                                Number_in_List;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               Is_Primary_Button;                                        // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.HandleGamePadToggleMode
struct UTabGamePadConfig_C_HandleGamePadToggleMode_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.UnbindClicked_Bind
struct UTabGamePadConfig_C_UnbindClicked_Bind_Params
{
	int                                                Number_in_List;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class UOptionsMenuInputOneKey_C*                   Widget;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.BndEvt__CustomInputTemplateConfigs_K2Node_ComponentBoundEvent
struct UTabGamePadConfig_C_BndEvt__CustomInputTemplateConfigs_K2Node_ComponentBoundEvent_Params
{
	int                                                Selected_Index;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.DoResetToDefault
struct UTabGamePadConfig_C_DoResetToDefault_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.DoNotResetToDefault
struct UTabGamePadConfig_C_DoNotResetToDefault_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.TrySetInputEnabled
struct UTabGamePadConfig_C_TrySetInputEnabled_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.HandleChangeBinding
struct UTabGamePadConfig_C_HandleChangeBinding_Params
{
	struct FKey                                        NewKey;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm)
};

// Function TabGamePadConfig.TabGamePadConfig_C.ExecuteUbergraph_TabGamePadConfig
struct UTabGamePadConfig_C_ExecuteUbergraph_TabGamePadConfig_Params
{
	int                                                EntryPoint;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function TabGamePadConfig.TabGamePadConfig_C.ShowResetToDefaultMessage__DelegateSignature
struct UTabGamePadConfig_C_ShowResetToDefaultMessage__DelegateSignature_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.GamepadMappingInfoChanged__DelegateSignature
struct UTabGamePadConfig_C_GamepadMappingInfoChanged__DelegateSignature_Params
{
};

// Function TabGamePadConfig.TabGamePadConfig_C.EnableGamepadInputOverlay__DelegateSignature
struct UTabGamePadConfig_C_EnableGamepadInputOverlay__DelegateSignature_Params
{
	bool                                               AcceptInput;                                              // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FText                                       OverlayText;                                              // (BlueprintVisible, BlueprintReadOnly, Parm)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
