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

// WidgetBlueprintGeneratedClass ChallengeBundleLockedReasonDisplay.ChallengeBundleLockedReasonDisplay_C
// 0x0048 (0x0270 - 0x0228)
class UChallengeBundleLockedReasonDisplay_C : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0228(0x0008) (ZeroConstructor, Transient, DuplicateTransient)
	class UCommonTextBlock*                            LockedText;                                               // 0x0230(0x0008) (BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, RepNotify, Interp, NonTransactional, EditorOnly, NoDestructor, AutoWeak, ContainsInstancedReference, AssetRegistrySearchable, SimpleDisplay, AdvancedDisplay, Protected, BlueprintCallable, BlueprintAuthorityOnly, TextExportTransient, NonPIEDuplicateTransient, ExposeOnSpawn, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic, NativeAccessSpecifierProtected, NativeAccessSpecifierPrivate)
	TScriptInterface<class UFortTimespanDataSource>    TimeSpanSource;                                           // 0x0238(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FFortChallengeBundleInfoLockedReason        ReasonForLock;                                            // 0x0248(0x0028) (Edit, BlueprintVisible, DisableEditOnInstance)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("WidgetBlueprintGeneratedClass ChallengeBundleLockedReasonDisplay.ChallengeBundleLockedReasonDisplay_C");
		return ptr;
	}


	void GetTimeSpanValue(struct FTimespan* Result);
	void HandleTick(class UObject* Source);
	void SetTimespanSource(TScriptInterface<class UFortTimespanDataSource> Value);
	void UpdateLockReasonDisplay();
	void SetLockReason(struct FFortChallengeBundleInfoLockedReason InValue);
	void Construct();
	void ExecuteUbergraph_ChallengeBundleLockedReasonDisplay(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
