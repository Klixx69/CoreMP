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

// WidgetBlueprintGeneratedClass TabGameOptionsMain.TabGameOptionsMain_C
// 0x0010 (0x02A0 - 0x0290)
class UTabGameOptionsMain_C : public UFortGameOptions
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0290(0x0008) (ZeroConstructor, Transient, DuplicateTransient)
	class UCommonTextBlock*                            TooltipDisplayReference;                                  // 0x0298(0x0008) (Edit, BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("WidgetBlueprintGeneratedClass TabGameOptionsMain.TabGameOptionsMain_C");
		return ptr;
	}


	void Construct();
	void UpdatePossibleLanguages();
	void CenterOnTab();
	void UpdateOptionsTab();
	void BndEvt__OptionsListView_K2Node_ComponentBoundEvent(class UUserWidget* Widget);
	void Setting_Value_Changed();
	void ExecuteUbergraph_TabGameOptionsMain(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
