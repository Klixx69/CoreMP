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

// BlueprintGeneratedClass CheckFrontEndRewardsAction.CheckFrontEndRewardsAction_C
// 0x0071 (0x0401 - 0x0390)
class ACheckFrontEndRewardsAction_C : public AFortScriptedAction
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0390(0x0008) (ZeroConstructor, Transient, DuplicateTransient)
	class USceneComponent*                             DefaultSceneRoot;                                         // 0x0398(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FFrontEndRewards_Definition                 RewardsDefinition;                                        // 0x03A0(0x0060) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	bool                                               ShowRewardsWidget;                                        // 0x0400(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass CheckFrontEndRewardsAction.CheckFrontEndRewardsAction_C");
		return ptr;
	}


	void PopulateItemCacheRewards();
	void PopulateNewGiftBoxes();
	void PopulateDifficultyIncreaseRewards();
	void HandleRewardsIgnored(class UFrontEndRewards_Widget_C* RewardsWidget);
	bool CanShowFrontendRewards();
	void Is_FrontEndRewards_Running(bool* bRunning);
	void PopulateMissionAlertRewards();
	void HandleRewardsClaimError(class UFrontEndRewards_Widget_C* RewardsWidget);
	void Clear();
	void HandleRewardsClaimed(class UFrontEndRewards_Widget_C* RewardsWidget);
	void PopulateCollectionBookRewards();
	void PopulateRewards();
	void OpenFrontEndRewards();
	void PopulateUnseenQuests(EFortQuestType QuestType);
	void GetCompletedQuests(TArray<class UFortQuestItem*>* Completed_Quests);
	void PopulateNewQuests();
	void PopulateQuestRewards();
	void PopulateMissionRewards();
	void CompleteRewardsAction();
	void UserConstructionScript();
	void Execute(struct FFortScriptedActionParams Params);
	void ExecuteUbergraph_CheckFrontEndRewardsAction(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
