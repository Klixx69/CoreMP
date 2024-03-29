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

// Function ColorLibrary.ColorLibrary_C.Get HarvestWeakPoint Color
struct UColorLibrary_C_Get_HarvestWeakPoint_Color_Params
{
	struct FColorStylesheet                            Stylesheet;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
	class UObject*                                     __WorldContext;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                StyleSheetOut;                                            // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function ColorLibrary.ColorLibrary_C.Get Base & Buff Colors
struct UColorLibrary_C_Get_Base___Buff_Colors_Params
{
	EFortStatValueDisplayType                          Display_Type;                                             // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	EFortBuffState                                     Buff_State;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FColorStylesheet                            Stylesheet;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
	class UObject*                                     __WorldContext;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                Base;                                                     // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                Buff;                                                     // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function ColorLibrary.ColorLibrary_C.Get Bolt Elemental Color
struct UColorLibrary_C_Get_Bolt_Elemental_Color_Params
{
	struct FColorStylesheet                            Stylesheet;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
	class UObject*                                     __WorldContext;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                Color;                                                    // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function ColorLibrary.ColorLibrary_C.Get Ice Elemental Color
struct UColorLibrary_C_Get_Ice_Elemental_Color_Params
{
	struct FColorStylesheet                            Stylesheet;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
	class UObject*                                     __WorldContext;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                Color;                                                    // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function ColorLibrary.ColorLibrary_C.Get Fire Elemental Color
struct UColorLibrary_C_Get_Fire_Elemental_Color_Params
{
	struct FColorStylesheet                            Stylesheet;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
	class UObject*                                     __WorldContext;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                Color;                                                    // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function ColorLibrary.ColorLibrary_C.Get Unique Color
struct UColorLibrary_C_Get_Unique_Color_Params
{
	struct FColorStylesheet                            Stylesheet;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
	class UObject*                                     __WorldContext;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                Color;                                                    // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function ColorLibrary.ColorLibrary_C.Get Debuff Color
struct UColorLibrary_C_Get_Debuff_Color_Params
{
	struct FColorStylesheet                            Stylesheet;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
	class UObject*                                     __WorldContext;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                Color;                                                    // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function ColorLibrary.ColorLibrary_C.Get Buff Color
struct UColorLibrary_C_Get_Buff_Color_Params
{
	struct FColorStylesheet                            Stylesheet;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
	class UObject*                                     __WorldContext;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                Color;                                                    // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
