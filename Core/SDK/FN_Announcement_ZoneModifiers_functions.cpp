// Fortnite (7.3) SDK
// Dumped with <3 by android#1337

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------------

// Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.UpdateWidgetData
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// class AFortClientAnnouncement* Announcement                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAnnouncement_ZoneModifiers_C::UpdateWidgetData(class AFortClientAnnouncement* Announcement)
{
	static auto fn = UObject::FindObject<UFunction>("Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.UpdateWidgetData");

	UAnnouncement_ZoneModifiers_C_UpdateWidgetData_Params params;
	params.Announcement = Announcement;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.OnDisplayTimerFinished
// (BlueprintCallable, BlueprintEvent)

void UAnnouncement_ZoneModifiers_C::OnDisplayTimerFinished()
{
	static auto fn = UObject::FindObject<UFunction>("Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.OnDisplayTimerFinished");

	UAnnouncement_ZoneModifiers_C_OnDisplayTimerFinished_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.OnConversationStopped
// (BlueprintCallable, BlueprintEvent)

void UAnnouncement_ZoneModifiers_C::OnConversationStopped()
{
	static auto fn = UObject::FindObject<UFunction>("Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.OnConversationStopped");

	UAnnouncement_ZoneModifiers_C_OnConversationStopped_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.OnAnnouncementStopped
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class AFortClientAnnouncement* NewAnnouncement                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAnnouncement_ZoneModifiers_C::OnAnnouncementStopped(class AFortClientAnnouncement* NewAnnouncement)
{
	static auto fn = UObject::FindObject<UFunction>("Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.OnAnnouncementStopped");

	UAnnouncement_ZoneModifiers_C_OnAnnouncementStopped_Params params;
	params.NewAnnouncement = NewAnnouncement;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.ExecuteUbergraph_Announcement_ZoneModifiers
// (Final, HasDefaults)
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAnnouncement_ZoneModifiers_C::ExecuteUbergraph_Announcement_ZoneModifiers(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function Announcement_ZoneModifiers.Announcement_ZoneModifiers_C.ExecuteUbergraph_Announcement_ZoneModifiers");

	UAnnouncement_ZoneModifiers_C_ExecuteUbergraph_Announcement_ZoneModifiers_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
