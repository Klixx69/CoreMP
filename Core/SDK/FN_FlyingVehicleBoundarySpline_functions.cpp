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

// Function FlyingVehicleBoundarySpline.FlyingVehicleBoundarySpline_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AFlyingVehicleBoundarySpline_C::UserConstructionScript()
{
	static auto fn = UObject::FindObject<UFunction>("Function FlyingVehicleBoundarySpline.FlyingVehicleBoundarySpline_C.UserConstructionScript");

	AFlyingVehicleBoundarySpline_C_UserConstructionScript_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
