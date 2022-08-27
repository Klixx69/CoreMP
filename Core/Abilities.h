#pragma once

class Abilities
{
public:
	static FGameplayAbilitySpec* FindAbilitySpecFromHandle(UAbilitySystemComponent* AbilitySystem, FGameplayAbilitySpecHandle Handle)
	{
		for (int i = 0; i < AbilitySystem->ActivatableAbilities.Items.Num(); i++)
		{
			auto Spec = AbilitySystem->ActivatableAbilities.Items[i];

			if (Spec.Handle.Handle == Handle.Handle)
			{
				return &Spec;
			}
		}

		return nullptr;
	}

	static inline bool (*InternalTryActivateAbility)(UAbilitySystemComponent*, FGameplayAbilitySpecHandle, FPredictionKey, UGameplayAbility**, void*, FGameplayEventData*);
	static inline FGameplayAbilitySpecHandle* (*GiveAbility_)(UAbilitySystemComponent*, FGameplayAbilitySpecHandle*, FGameplayAbilitySpec);

	static void Init()
	{
		auto BaseAddr = (uintptr_t)GetModuleHandle(0);
		InternalTryActivateAbility = decltype(InternalTryActivateAbility)(BaseAddr + 0x6905A0);
		GiveAbility_ = decltype(GiveAbility_)(BaseAddr + 0x68ED10);
	}

	static void GiveAbility(AFortPlayerPawn* InPawn, UClass* AbilityClass)
	{
		auto AbilitySystemComponent = InPawn->AbilitySystemComponent;

		if (!AbilitySystemComponent)
			return;

		auto GenerateNewSpec = [&]() -> FGameplayAbilitySpec
		{
			FGameplayAbilitySpecHandle Handle{ rand() };

			FGameplayAbilitySpec Spec{ -1, -1, -1, Handle, AbilityClass->CreateDefaultObject<UGameplayAbility>(), 1, -1, nullptr, 0, false, false, false };

			return Spec;
		};

		auto Spec = GenerateNewSpec();

		for (int i = 0; i < AbilitySystemComponent->ActivatableAbilities.Items.Num(); i++)
		{
			auto& CurrentSpec = AbilitySystemComponent->ActivatableAbilities.Items[i];

			if (CurrentSpec.Ability == Spec.Ability)
				return;
		}

		auto Handle = GiveAbility_(AbilitySystemComponent, &Spec.Handle, Spec);
	}

	static void GiveAbilities(AFortPlayerPawn* InPawn)
	{
		static auto AbilitySet = UObject::FindObjectFast<UFortAbilitySet>("/Game/Abilities/Player/Generic/Traits/DefaultPlayer/GAS_DefaultPlayer.GAS_DefaultPlayer");

		for (int i = 0; i < AbilitySet->GameplayAbilities.Num(); i++)
		{
			auto Ability = AbilitySet->GameplayAbilities[i];

			GiveAbility(InPawn, Ability);
		}

		static std::vector<UClass*> CustomAbilitySet
		{
			UObject::FindObjectFast<UClass>("/Game/Abilities/Weapons/Ranged/GA_Ranged_GenericDamage.GA_Ranged_GenericDamage_C"),
		};

		for (auto Ability : CustomAbilitySet)
		{
			GiveAbility(InPawn, Ability);
		}
	}
};