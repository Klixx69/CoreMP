#pragma once

// Fortnite (7.3) SDK
// Dumped with <3 by android#1337

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// BlueprintGeneratedClass StyleLibrary.StyleLibrary_C
// 0x0000 (0x0028 - 0x0028)
class UStyleLibrary_C : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass StyleLibrary.StyleLibrary_C");
		return ptr;
	}


	void STATIC_Get_Conning_Color_For_Specific_Difficulty(int Difficulty_Value, class UObject* __WorldContext, struct FLinearColor* Difficulty_Linear_Color, bool* Invalid);
	void STATIC_Get_Conning_Color_From_Difficulty_Value(int Player_Account_Level, float Content_Difficulty_Level, class UObject* __WorldContext, struct FLinearColor* Difficulty_Linear_Color, bool* Success, struct FText* ToolTipText, int* DifficultyValue);
	void STATIC_Get_HarvestWeakPoint_Color(struct FFortUIStylesheet Stylesheet, class UObject* __WorldContext, struct FLinearColor* StyleSheetOut);
	void STATIC_ResizeBrush(TEnumAsByte<EFortBrushSize> BrushSize, struct FSlateBrush BaseBrush, class UObject* __WorldContext, struct FSlateBrush* ResizedBrush);
	void STATIC_Get_Base___Buff_Colors(EFortStatValueDisplayType Display_Type, EFortBuffState Buff_State, struct FFortUIStylesheet Stylesheet, class UObject* __WorldContext, struct FLinearColor* Base, struct FLinearColor* Buff);
	void STATIC_Get_Bolt_Elemental_Color(struct FFortUIStylesheet Stylesheet, class UObject* __WorldContext, struct FLinearColor* Color);
	void STATIC_Get_Ice_Elemental_Color(struct FFortUIStylesheet Stylesheet, class UObject* __WorldContext, struct FLinearColor* Color);
	void STATIC_Get_Fire_Elemental_Color(struct FFortUIStylesheet Stylesheet, class UObject* __WorldContext, struct FLinearColor* Color);
	void STATIC_Get_Unique_Color(struct FFortUIStylesheet Stylesheet, class UObject* __WorldContext, struct FLinearColor* Color);
	void STATIC_Get_Item_Size(struct FFortUIStylesheet Stylesheet, TEnumAsByte<EFortBrushSize> Brush_Size, class UObject* __WorldContext, struct FVector2D* Item_Size);
	void STATIC_Get_Debuff_Color(struct FFortUIStylesheet Stylesheet, class UObject* __WorldContext, struct FLinearColor* Color);
	void STATIC_Get_Buff_Color(struct FFortUIStylesheet Stylesheet, class UObject* __WorldContext, struct FLinearColor* Color);
	void STATIC_Get_Item_Icon_Size(struct FFortUIStylesheet Stylesheet, TEnumAsByte<EFortBrushSize> Brush_Size, class UObject* __WorldContext, struct FVector2D* Icon_Size);
	void STATIC_Get_Standard_Icon_Size(struct FFortUIStylesheet Stylesheet, TEnumAsByte<EFortBrushSize> Brush_Size, class UObject* __WorldContext, struct FVector2D* Icon_Size);
	void STATIC_Get_Theme(struct FFortUIStylesheet Stylesheet, TEnumAsByte<EFortUITheme> Theme_Type, class UObject* __WorldContext, struct FFortUITheme* Theme);
	void STATIC_Get_Theme_Color(struct FFortUIStylesheet Stylesheet, TEnumAsByte<EFortUITheme> Theme_Type, TEnumAsByte<EFortUIThemeColor> Color_Type, class UObject* __WorldContext, struct FLinearColor* Theme_Color);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
