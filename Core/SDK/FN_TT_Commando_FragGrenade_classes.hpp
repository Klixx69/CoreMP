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

// BlueprintGeneratedClass TT_Commando_FragGrenade.TT_Commando_FragGrenade_C
// 0x0000 (0x0168 - 0x0168)
class UTT_Commando_FragGrenade_C : public UFortGameplayAbilityTooltip
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass TT_Commando_FragGrenade.TT_Commando_FragGrenade_C");
		return ptr;
	}


	bool GetApplicationTag(class UGameplayAbility* AbilityInstance, struct FGameplayTag* OutTag);
	bool GetTextForTokenFromAbilityInstanceInternal(class UGameplayAbility* AbilityInstance, struct FGameplayTag Tag, class UFortTooltipContext* Context, struct FGameplayTag Token, struct FText* OutText);
	void InitializeAbilityInstanceInternal(class UGameplayAbility* AbilityInstance, class UFortTooltipContext* Context);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
