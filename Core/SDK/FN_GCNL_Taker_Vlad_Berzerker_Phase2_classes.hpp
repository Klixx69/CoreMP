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

// BlueprintGeneratedClass GCNL_Taker_Vlad_Berzerker_Phase2.GCNL_Taker_Vlad_Berzerker_Phase2_C
// 0x0058 (0x0480 - 0x0428)
class AGCNL_Taker_Vlad_Berzerker_Phase2_C : public AFortGameplayCueNotify_Looping
{
public:
	class UParticleSystemComponent*                    BodyMistFX;                                               // 0x0428(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	TMap<struct FName, struct FLinearColor>            Berserker_Map;                                            // 0x0430(0x0050) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass GCNL_Taker_Vlad_Berzerker_Phase2.GCNL_Taker_Vlad_Berzerker_Phase2_C");
		return ptr;
	}


	bool OnRemove(class AActor* MyTarget, struct FGameplayCueParameters Parameters);
	bool OnActive(class AActor* MyTarget, struct FGameplayCueParameters Parameters);
	void UserConstructionScript();
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
