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

// BlueprintGeneratedClass BP_ReadyUp_Interact.BP_ReadyUp_Interact_C
// 0x009D (0x0D75 - 0x0CD8)
class ABP_ReadyUp_Interact_C : public ABuildingProp
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0CD8(0x0008) (ZeroConstructor, Transient, DuplicateTransient)
	struct FText                                       InteractText;                                             // 0x0CE0(0x0018) (Edit, BlueprintVisible, Net, DisableEditOnInstance)
	bool                                               CanInteract;                                              // 0x0CF8(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0CF9(0x0007) MISSED OFFSET
	unsigned char                                      UnknownData01[0x28];                                      // 0x0CF9(0x0028) UNKNOWN PROPERTY: SoftClassProperty BP_ReadyUp_Interact.BP_ReadyUp_Interact_C.MissionControlWidgetRef
	class UClass*                                      MissionControlWidget;                                     // 0x0D28(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class AFortPlayerController*                       PlayerController;                                         // 0x0D30(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	class AFortPlayerController*                       PlayerWhoOpenedMissionControl;                            // 0x0D38(0x0008) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	class UFortWorldItemDefinition*                    ItemToDeposit;                                            // 0x0D40(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                BluGloMissionActivationQty;                               // 0x0D48(0x0004) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0D4C(0x0004) MISSED OFFSET
	class AFortObjectiveBase*                          ReadyUpObjectiveRef;                                      // 0x0D50(0x0008) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	struct FGuid                                       MissionGuid;                                              // 0x0D58(0x0010) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               DifficultyVoteInProgress;                                 // 0x0D68(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x0D69(0x0003) MISSED OFFSET
	int                                                BluGloDifficulytActivationQty;                            // 0x0D6C(0x0004) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               ActivateVoteInProgress;                                   // 0x0D70(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               ShouldDisableDifficultyVoting;                            // 0x0D71(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               IsFightTheStorm;                                          // 0x0D72(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               Supported;                                                // 0x0D73(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               BluGloTaken;                                              // 0x0D74(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass BP_ReadyUp_Interact.BP_ReadyUp_Interact_C");
		return ptr;
	}


	void ReturnBluGloToPlayer(TScriptInterface<class UFortInventoryOwnerInterface> InventoryOwner, int NumberBGtoReturn);
	void TakeBluGloFromPlayer(class AFortPlayerController* PlayerController, int NumberBGtoTake);
	void OnRep_CanInteract();
	bool ShouldDie(float Damage, class AController* EventInstigator, class AActor* DamageCauser);
	struct FText BlueprintGetInteractionString(class AFortPawn* InteractingPawn);
	bool BlueprintCanInteract(class AFortPawn* InteractingPawn);
	void UserConstructionScript();
	void OnCanceled();
	void OnAllClientsReady();
	void OnLoaded_EF452E634A72368CE34CF0A4B53E9FCE(class UClass* Loaded);
	void ReceiveBeginPlay();
	void OpenMissionControl();
	void BlueprintOnInteract(class AFortPawn* InteractingPawn);
	void VoteCalled(EFortVoteType VoteType, EFortVoteStatus VoteStatus, int VoteResult, TArray<struct FVoter> Voters);
	void DisableDifficultyVoting();
	void AtlasUnsupported();
	void HandleMissionEvent_Supported(struct FGuid InMissionGuid, struct FGameplayTagContainer ObjectiveHandle, class UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, class UObject* EventFocus, class UDataAsset* EventContent, class AActor* EventInstigator, int GenericInt, float GenericFloat, struct FText GenericText, struct FGameplayTagContainer GameplayTags, struct FFortMissionEvent MissionEvent);
	void HandleMissionEvent_UnSupported(struct FGuid InMissionGuid, struct FGameplayTagContainer ObjectiveHandle, class UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, class UObject* EventFocus, class UDataAsset* EventContent, class AActor* EventInstigator, int GenericInt, float GenericFloat, struct FText GenericText, struct FGameplayTagContainer GameplayTags, struct FFortMissionEvent MissionEvent);
	void HandleMissionEvent_ActivatePrimary(struct FGuid InMissionGuid, struct FGameplayTagContainer ObjectiveHandle, class UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, class UObject* EventFocus, class UDataAsset* EventContent, class AActor* EventInstigator, int GenericInt, float GenericFloat, struct FText GenericText, struct FGameplayTagContainer GameplayTags, struct FFortMissionEvent MissionEvent);
	void ExecuteUbergraph_BP_ReadyUp_Interact(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
