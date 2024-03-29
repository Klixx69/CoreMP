#pragma once

// Fortnite (7.3) SDK
// Dumped with <3 by android#1337

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

namespace SDK
{
//---------------------------------------------------------------------------
//Enums
//---------------------------------------------------------------------------

// Enum CommonUI.ECommonNumericType
enum class ECommonNumericType : uint8_t
{
	Number                         = 0,
	Percentage                     = 1,
	Seconds                        = 2,
	Distance                       = 3,
	ECommonNumericType_MAX         = 4
};


// Enum CommonUI.EOperation
enum class EOperation : uint8_t
{
	Intro                          = 0,
	Outro                          = 1,
	Push                           = 2,
	Pop                            = 3,
	Invalid                        = 4,
	EOperation_MAX                 = 5
};


// Enum CommonUI.ECommonPlatformType
enum class ECommonPlatformType : uint8_t
{
	PC                             = 0,
	Mac                            = 1,
	PS4                            = 2,
	XBox                           = 3,
	IOS                            = 4,
	Android                        = 5,
	Erebus                         = 6,
	Count                          = 7,
	ECommonPlatformType_MAX        = 8
};


// Enum CommonUI.EInputActionState
enum class EInputActionState : uint8_t
{
	Enabled                        = 0,
	Disabled                       = 1,
	Hidden                         = 2,
	HiddenAndDisabled              = 3,
	EInputActionState_MAX          = 4
};


// Enum CommonUI.ETransitionCurve
enum class ETransitionCurve : uint8_t
{
	Linear                         = 0,
	QuadIn                         = 1,
	QuadOut                        = 2,
	QuadInOut                      = 3,
	CubicIn                        = 4,
	CubicOut                       = 5,
	CubicInOut                     = 6,
	ETransitionCurve_MAX           = 7
};


// Enum CommonUI.ECommonSwitcherTransition
enum class ECommonSwitcherTransition : uint8_t
{
	FadeOnly                       = 0,
	Horizontal                     = 1,
	Vertical                       = 2,
	Zoom                           = 3,
	ECommonSwitcherTransition_MAX  = 4
};



//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// ScriptStruct CommonUI.CommonInputActionHandlerData
// 0x0020
struct FCommonInputActionHandlerData
{
	struct FDataTableRowHandle                         InputActionRow;                                           // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly)
	EInputActionState                                  State;                                                    // 0x0010(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0xF];                                       // 0x0011(0x000F) MISSED OFFSET
};

// ScriptStruct CommonUI.CommonButtonStyleOptionalSlateSound
// 0x0020
struct FCommonButtonStyleOptionalSlateSound
{
	bool                                               bHasSound;                                                // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FSlateSound                                 Sound;                                                    // 0x0008(0x0018) (Edit, BlueprintVisible)
};

// ScriptStruct CommonUI.Operation
// 0x0018
struct FOperation
{
	EOperation                                         Operation;                                                // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	class UCommonActivatablePanel*                     Panel;                                                    // 0x0008(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               bIntroPanel;                                              // 0x0010(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bActivatePanel;                                           // 0x0011(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bOutroPanelBelow;                                         // 0x0012(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x0013(0x0005) MISSED OFFSET
};

// ScriptStruct CommonUI.CommonNumberFormattingOptions
// 0x0014
struct FCommonNumberFormattingOptions
{
	TEnumAsByte<ERoundingMode>                         RoundingMode;                                             // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               UseGrouping;                                              // 0x0001(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0002(0x0002) MISSED OFFSET
	int                                                MinimumIntegralDigits;                                    // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                MaximumIntegralDigits;                                    // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                MinimumFractionalDigits;                                  // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                MaximumFractionalDigits;                                  // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct CommonUI.CommonRegisteredTabInfo
// 0x0018
struct FCommonRegisteredTabInfo
{
	int                                                TabIndex;                                                 // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	class UCommonButton*                               TabButton;                                                // 0x0008(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UWidget*                                     ContentInstance;                                          // 0x0010(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// ScriptStruct CommonUI.SoftSlateBrush
// 0x0070
struct FSoftSlateBrush
{
	struct FVector2D                                   ImageSize;                                                // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FMargin                                     Margin;                                                   // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FSlateColor                                 TintColor;                                                // 0x0018(0x0028) (Edit, BlueprintVisible)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0040(0x0028) UNKNOWN PROPERTY: SoftObjectProperty CommonUI.SoftSlateBrush.ResourceObject
	TEnumAsByte<ESlateBrushDrawType>                   DrawAs;                                                   // 0x0068(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESlateBrushTileType>                   Tiling;                                                   // 0x0069(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESlateBrushMirrorType>                 Mirroring;                                                // 0x006A(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESlateBrushImageType>                  ImageType;                                                // 0x006B(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x006C(0x0004) MISSED OFFSET
};

// ScriptStruct CommonUI.CommonInputKeyDisplayData
// 0x02A0
struct FCommonInputKeyDisplayData
{
	struct FSoftSlateBrush                             KeyboardBrush;                                            // 0x0000(0x0070) (Edit)
	struct FSoftSlateBrush                             GamepadBrushes[0x4];                                      // 0x0070(0x0070) (Edit)
	struct FSoftSlateBrush                             TouchBrush;                                               // 0x0230(0x0070) (Edit)
};

// ScriptStruct CommonUI.CommonInputKeyDisplayConfiguration
// 0x02B8
struct FCommonInputKeyDisplayConfiguration
{
	struct FKey                                        Key;                                                      // 0x0000(0x0018) (Edit)
	struct FCommonInputKeyDisplayData                  Value;                                                    // 0x0018(0x02A0) (Edit)
};

// ScriptStruct CommonUI.CommonInputTypeInfo
// 0x00A8
struct FCommonInputTypeInfo
{
	struct FKey                                        Key;                                                      // 0x0000(0x0018) (Edit)
	EInputActionState                                  OverrrideState;                                           // 0x0018(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bActionRequiresHold;                                      // 0x0019(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x001A(0x0002) MISSED OFFSET
	float                                              HoldTime;                                                 // 0x001C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	struct FSlateBrush                                 OverrideBrush;                                            // 0x0020(0x0088) (Edit)
};

// ScriptStruct CommonUI.CommonInputActionData
// 0x0420 (0x0428 - 0x0008)
struct FCommonInputActionData : public FTableRowBase
{
	struct FText                                       DisplayName;                                              // 0x0008(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FText                                       HoldDisplayName;                                          // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FCommonInputTypeInfo                        KeyboardInputTypeInfo;                                    // 0x0038(0x00A8) (Edit)
	struct FCommonInputTypeInfo                        GamepadInputTypeInfos[0x4];                               // 0x00E0(0x00A8) (Edit)
	struct FCommonInputTypeInfo                        TouchInputTypeInfo;                                       // 0x0380(0x00A8) (Edit)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
