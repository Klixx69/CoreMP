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

// BlueprintGeneratedClass GA_BoostJumpPack.GA_BoostJumpPack_C
// 0x0159 (0x0AB1 - 0x0958)
class UGA_BoostJumpPack_C : public UFortGameplayAbility_JumpBoostPack
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0958(0x0008) (ZeroConstructor, Transient, DuplicateTransient)
	float                                              Jump_Multiple;                                            // 0x0960(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FVector                                     Basic_Jump_Z_Adjust;                                      // 0x0964(0x000C) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FVector                                     FinalJumpHeight;                                          // 0x0970(0x000C) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x097C(0x0004) MISSED OFFSET
	struct FGameplayEventData                          EventTriggerData;                                         // 0x0980(0x00A8) (Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                               bJumpButtonHeld;                                          // 0x0A28(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAtApex;                                                  // 0x0A29(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x0A2A(0x0002) MISSED OFFSET
	struct FActiveGameplayEffectHandle                 JetpackEffectHandle;                                      // 0x0A2C(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0A34(0x0004) MISSED OFFSET
	class AFortPlayerPawn*                             FortPlayerPawn;                                           // 0x0A38(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	bool                                               bBoundToPawnLanded;                                       // 0x0A40(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x0A41(0x0003) MISSED OFFSET
	float                                              FuelFudge;                                                // 0x0A44(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FActiveGameplayEffectHandle                 RegenEffectHandle;                                        // 0x0A48(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                               bRegenEffectActive;                                       // 0x0A50(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x7];                                       // 0x0A51(0x0007) MISSED OFFSET
	struct FGameplayTagContainer                       ExecuteTags;                                              // 0x0A58(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance)
	int                                                JumpButtonHeldCount;                                      // 0x0A78(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x0A7C(0x0004) MISSED OFFSET
	struct FGameplayTagContainer                       ReleaseTags;                                              // 0x0A80(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance)
	float                                              TimeStartedHovering;                                      // 0x0AA0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TimeStartedFalling;                                       // 0x0AA4(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EndHoverDelay;                                            // 0x0AA8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EndFallingDelay;                                          // 0x0AAC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bHasDied;                                                 // 0x0AB0(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass GA_BoostJumpPack.GA_BoostJumpPack_C");
		return ptr;
	}


	void Handle_Jetpack_Equipped();
	bool Reasons_To_Reset_on_Transition(struct FGameplayTag Tag);
	class AFortPlayerPawn* Get_Player_Pawn(class UObject* Object);
	bool IsCurrentlyDead(struct FGameplayTag TagOne);
	void Reengage_Falling_Movement();
	void Reengage_Hovering_Movement();
	void SavePlayerPawn();
	void OnAbilityCanceled();
	void OnFuelIsEmpty();
	void OnFuelIsFull();
	void Reset_Toggle_Input_State();
	void ProcessTriggerData(struct FGameplayTag TagOne);
	void Stop_Regen_Effect();
	void Start_Regen_Effect();
	void Consider_Stopping_Regen_Effect();
	void Consider_Starting_Regen_Effect();
	bool IsBoostAllowed();
	void K2_OnEndAbility(bool bWasCancelled);
	bool K2_ShouldAbilityRespondToEvent(struct FGameplayAbilityActorInfo ActorInfo, struct FGameplayEventData Payload);
	void GetMaxFuel(float* MaxFuel);
	void GetFuel(float* Fuel);
	void Setup_PlayerPawn();
	bool IsUsingJetpackEffectActive();
	void HandleCurrentBoostStateChanged(EJumpBoostPackState PreviousState, EJumpBoostPackState CurrentState);
	void SetCurrentBoostState(EJumpBoostPackState NewState);
	void PotentiallyEndHovering(bool bForceEndHovering);
	void Setup_Notify_at_Apex(bool bNotifyApex);
	void HandleIdle();
	void HandleFalling();
	void HandleHovering();
	void ResetTransitionVariables();
	void TransitionFromFalling(TEnumAsByte<Enum_BoostJumpStates>* TargetBoostState);
	void TransitionFromHovering(TEnumAsByte<Enum_BoostJumpStates>* TargetBoostState);
	void TransitionFromBoost(TEnumAsByte<Enum_BoostJumpStates>* TargetBoostState);
	void TransitionFromIdle(TEnumAsByte<Enum_BoostJumpStates>* TargetBoostState);
	void ProcessAbilityStateMachine();
	void DetermineStateToTransitionTo(TEnumAsByte<Enum_BoostJumpStates>* BoostState);
	void SetupTransitionVariables(struct FGameplayTag Tag);
	void HandleBoostJump();
	void SetJumpHeight(class AFortPlayerPawn* Pawn, class AFortPlayerPawn** Pawn_Out, struct FVector* Jump_Height);
	void On_Reached_Jump_Apex();
	void OnPawnLanded(struct FHitResult Hit);
	void K2_ActivateAbilityFromEvent(struct FGameplayEventData EventData);
	void OnCurrentStateChanged(EJumpBoostPackState InPreviousState, EJumpBoostPackState InCurrentState);
	void Delay_ProcessAbilityStateMachine();
	void ExecuteUbergraph_GA_BoostJumpPack(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
