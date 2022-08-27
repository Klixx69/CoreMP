#pragma once

class Hooks
{
public:
	static inline void GetPlayerViewPointHook(APlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation)
	{
		if (PlayerController->StateName == NAME_Spectating && PlayerController->HasAuthority() && !PlayerController->IsLocalController())
		{
			out_Location = PlayerController->LastSpectatorSyncLocation;
			out_Rotation = PlayerController->LastSpectatorSyncRotation;
		}
		else if (PlayerController->PlayerCameraManager != nullptr &&
			PlayerController->PlayerCameraManager->CameraCachePrivate.Timestamp > 0.f)
		{
			out_Location = PlayerController->PlayerCameraManager->GetCameraLocation();
			out_Rotation = PlayerController->PlayerCameraManager->GetCameraRotation();
		}
		else {
			AActor* TheViewTarget = PlayerController->GetViewTarget();

			if (TheViewTarget != nullptr)
			{
				out_Location = TheViewTarget->K2_GetActorLocation();
				out_Rotation = TheViewTarget->K2_GetActorRotation();
			}
			else {
				PlayerController->GetActorEyesViewPoint(&out_Location, &out_Rotation);
			}
		}
	}

	static void Init()
	{
		CREATE_HOOK(Util::BaseAddress() + 0x2AED2E0, GetPlayerViewPointHook, nullptr);
	}
};