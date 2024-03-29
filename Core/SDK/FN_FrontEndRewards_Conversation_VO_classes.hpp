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

// WidgetBlueprintGeneratedClass FrontEndRewards_Conversation_VO.FrontEndRewards_Conversation_VO_C
// 0x0028 (0x0280 - 0x0258)
class UFrontEndRewards_Conversation_VO_C : public UFortRewardConversationWidget
{
public:
	struct FDataTableRowHandle                         ReplayAction;                                             // 0x0258(0x0010) (Edit, BlueprintVisible, DisableEditOnInstance)
	class UFortConversation*                           Conversation;                                             // 0x0268(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UFortQuestItem*                              QuestItemRef;                                             // 0x0270(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class AAnnounce_Gen_Quest_Conversation_FrontEndRewards_C* ConversationActor;                                        // 0x0278(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("WidgetBlueprintGeneratedClass FrontEndRewards_Conversation_VO.FrontEndRewards_Conversation_VO_C");
		return ptr;
	}


	void CreateConversationActor(class AAnnounce_Gen_Quest_Conversation_FrontEndRewards_C** NewAnnoucement);
	void PlayConversation(class UFortQuestItem* QuestItem);
	void HandleConversationFinished();
	void HandleNewSentence(struct FFortConversationSentence Sentence);
	void StopConversation();
	void HandleReplayAction(bool* Committed);
	void PopulateFromConversation(class UFortConversation* Conversation);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
