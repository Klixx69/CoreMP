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

// BlueprintGeneratedClass Threat_RainAttachedToPlayer.Threat_RainAttachedToPlayer_C
// 0x0010 (0x0340 - 0x0330)
class AThreat_RainAttachedToPlayer_C : public AActor
{
public:
	class UParticleSystemComponent*                    ParticleSystem;                                           // 0x0330(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USceneComponent*                             DefaultSceneRoot;                                         // 0x0338(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass Threat_RainAttachedToPlayer.Threat_RainAttachedToPlayer_C");
		return ptr;
	}


	void UserConstructionScript();
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
