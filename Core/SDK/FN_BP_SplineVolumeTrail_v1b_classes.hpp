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

// BlueprintGeneratedClass BP_SplineVolumeTrail_v1b.BP_SplineVolumeTrail_v1b_C
// 0x0230 (0x0560 - 0x0330)
class ABP_SplineVolumeTrail_v1b_C : public AActor
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0330(0x0008) (ZeroConstructor, Transient, DuplicateTransient)
	class UArrowComponent*                             DebugArrow;                                               // 0x0338(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USceneComponent*                             DefaultSceneRoot;                                         // 0x0340(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	TEnumAsByte<ETimelineDirection>                    DebugRotateTimeline__Direction_A8B473E74A53FB0F346216B4D4D23AC9;// 0x0348(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0349(0x0007) MISSED OFFSET
	class UTimelineComponent*                          DebugRotateTimeline;                                      // 0x0350(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USplineComponent*                            Spline;                                                   // 0x0358(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	class USkeletalMeshComponent*                      Skeletal_Mesh;                                            // 0x0360(0x0008) (Edit, BlueprintVisible, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       Socket_Attach_Point;                                      // 0x0368(0x0008) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	class UStaticMesh*                                 SplineMeshTemplate;                                       // 0x0370(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UMaterialInterface*                          SplineMeshMaterialOverride;                               // 0x0378(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UParticleSystem*                             Particles;                                                // 0x0380(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              LifeTime;                                                 // 0x0388(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Lifetime_Buffer;                                          // 0x038C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SplineSystemDuration;                                     // 0x0390(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              LifetimeAfterCompletion;                                  // 0x0394(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               KeepTickEnabledWhenCompleting;                            // 0x0398(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0399(0x0003) MISSED OFFSET
	int                                                NumberOfSplineMeshesToUpdate;                             // 0x039C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Initial_Size;                                             // 0x03A0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x03A4(0x0004) MISSED OFFSET
	TArray<class USplineMeshComponent*>                SplineMeshes;                                             // 0x03A8(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	float                                              SplineDistanceThreshold;                                  // 0x03B8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SplineDistanceThresholdEmpty;                             // 0x03BC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<class USplineMeshComponent*>                SplineMeshesHidden;                                       // 0x03C0(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<float>                                      SplineTimestamps;                                         // 0x03D0(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	int                                                ArrayIndex;                                               // 0x03E0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               SplineSystemActive;                                       // 0x03E4(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x03E5(0x0003) MISSED OFFSET
	float                                              CompletionTimestamp;                                      // 0x03E8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              LifetimeAdjusted;                                         // 0x03EC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           SizeOverLife;                                             // 0x03F0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<class UMaterialInstanceDynamic*>            MIDs_1;                                                   // 0x03F8(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	class UCurveLinearColor*                           ColorAndAlphaOverLife;                                    // 0x0408(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UParticleSystemComponent*                    ParticlesComponent;                                       // 0x0410(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	int                                                SplineID;                                                 // 0x0418(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x041C(0x0004) MISSED OFFSET
	class USplineMeshComponent*                        Current_Spline_Mesh;                                      // 0x0420(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	float                                              Initial_Rotation__Roll_;                                  // 0x0428(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x042C(0x0004) MISSED OFFSET
	class UCurveFloat*                                 RotationOverLife;                                         // 0x0430(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               DebugMode;                                                // 0x0438(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x3];                                       // 0x0439(0x0003) MISSED OFFSET
	struct FVector                                     DebugPositionOffset;                                      // 0x043C(0x000C) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FRotator                                    DebugRotationRate;                                        // 0x0448(0x000C) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              DebugTickDelta;                                           // 0x0454(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DebugPreviousTickTimestamp;                               // 0x0458(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData07[0x4];                                       // 0x045C(0x0004) MISSED OFFSET
	struct FTimerHandle                                Spline_System_Duration_Event_Handle;                      // 0x0460(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                               Use_Tick_Interval_LODs;                                   // 0x0468(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0x7];                                       // 0x0469(0x0007) MISSED OFFSET
	struct FTimerHandle                                Tick_Interval_Event_Handle;                               // 0x0470(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	float                                              Tick_Interval_LOD_Check_Rate;                             // 0x0478(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData09[0x4];                                       // 0x047C(0x0004) MISSED OFFSET
	TArray<int>                                        Tick_Interval_LOD_Distances;                              // 0x0480(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TArray<float>                                      Tick_Actor_Intervals;                                     // 0x0490(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	int                                                LOD_Array_Index;                                          // 0x04A0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               Use_Recently_Rendered_LOD;                                // 0x04A4(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData10[0x3];                                       // 0x04A5(0x0003) MISSED OFFSET
	float                                              Recently_Rendered_Check_Rate;                             // 0x04A8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData11[0x4];                                       // 0x04AC(0x0004) MISSED OFFSET
	struct FTimerHandle                                Recently_Rendered_Event_Handle;                           // 0x04B0(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                               RecentlyRendered;                                         // 0x04B8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData12[0x3];                                       // 0x04B9(0x0003) MISSED OFFSET
	float                                              Recently_Rendered_Tolerance;                              // 0x04BC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FVector                                     SplineDefaultUpVector;                                    // 0x04C0(0x000C) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               SplineDefaultUpVectorInWorldSpace;                        // 0x04CC(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<En_SplineForwardAxes>                  SplineMeshForwardAxis;                                    // 0x04CD(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               CeaseAndDetachSplineUponCompletion;                       // 0x04CE(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               CanNewSplinePointsBeCreated;                              // 0x04CF(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               LinearColorOverLengthOfSpline;                            // 0x04D0(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData13[0x7];                                       // 0x04D1(0x0007) MISSED OFFSET
	TArray<int>                                        IndiciesToDelete;                                         // 0x04D8(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	bool                                               RedistributePointsAlongSplineWhenCreated;                 // 0x04E8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData14[0x7];                                       // 0x04E9(0x0007) MISSED OFFSET
	class UMaterialInstanceDynamic*                    CurveBakeMID;                                             // 0x04F0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UTextureRenderTarget2D*                      RenderTarget;                                             // 0x04F8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   RenderTextureResolution;                                  // 0x0500(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<class UCurveLinearColor*>                   LinearColorCurvesToBake;                                  // 0x0508(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	bool                                               WriteBakedCurveDataToDisk;                                // 0x0518(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData15[0x7];                                       // 0x0519(0x0007) MISSED OFFSET
	struct FString                                     File_Path;                                                // 0x0520(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	struct FString                                     File_Name;                                                // 0x0530(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TArray<struct FLinearColor>                        LinearColorArray;                                         // 0x0540(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	bool                                               UseCheapSplines;                                          // 0x0550(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData16[0x7];                                       // 0x0551(0x0007) MISSED OFFSET
	class UTexture*                                    LinearColorTexture;                                       // 0x0558(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass BP_SplineVolumeTrail_v1b.BP_SplineVolumeTrail_v1b_C");
		return ptr;
	}


	void UpdateCheapSplinesWPOVectors();
	void GetSocketLocationWS(struct FName Socket_Name, struct FVector* Location_WS);
	void SetStartAndEndAllSplineMeshes(bool Update_All_Spline_Meshes);
	void DestroyAllSplineMeshes();
	void BakeLinearColor(class UCurveLinearColor* Curve_Linear_Color, int Pixel__X_, struct FLinearColor* LinearColorOut);
	void ReturnSplineMeshToPool(class USplineMeshComponent* SplineMesh, int IndexToRemove);
	void SplineUpdateOnTick();
	void RedistributePointsAlongSpline();
	void GetLinearColorFromCurveAtTime(class UCurveLinearColor* Curve_Linear_Color, int Index, struct FLinearColor* LinearColorOut);
	void TickIntervalLODCheck();
	void SetWasRecentlyRendered();
	bool AddSplineDistanceCheck();
	void SetNewSplinePointsBool();
	void SetForwardAxisOnSplineMesh(class USplineMeshComponent* SplineMesh);
	void RollSplineMesh();
	void UpdateParticleSystemPosition();
	void UpdateMID();
	void ScaleSplineMesh();
	void SplineTimestampManagement();
	void UpdateSplinePointPosition();
	void AddSplinePoint();
	void SetStartAndEndSplineMesh(bool Update_Spline_Mesh);
	void AddSplineMesh();
	void UserConstructionScript();
	void DebugRotateTimeline__FinishedFunc();
	void DebugRotateTimeline__UpdateFunc();
	void ReceiveTick(float DeltaSeconds);
	void ReceiveBeginPlay();
	void SplineSystemDurationReached();
	void DebugMode_Rotate();
	void ManuallyStopSplineSystem();
	void Tick_Interval_LOD_Check();
	void Recently_Rendered_Check();
	void ClearRenderTarget();
	void GenerateCurveTextures();
	void ExecuteUbergraph_BP_SplineVolumeTrail_v1b(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
