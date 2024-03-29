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

// Class MRMesh.MeshReconstructorBase
// 0x0000 (0x0028 - 0x0028)
class UMeshReconstructorBase : public UObject
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class MRMesh.MeshReconstructorBase");
		return ptr;
	}


	void StopReconstruction();
	void StartReconstruction();
	void PauseReconstruction();
	bool IsReconstructionStarted();
	bool IsReconstructionPaused();
	void DisconnectMRMesh();
	void ConnectMRMesh(class UMRMeshComponent* Mesh);
};


// Class MRMesh.MRMeshComponent
// 0x0050 (0x05C0 - 0x0570)
class UMRMeshComponent : public UPrimitiveComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0570(0x0008) MISSED OFFSET
	class UMaterialInterface*                          Material;                                                 // 0x0578(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bCreateMeshProxySections;                                 // 0x0580(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bUpdateNavMeshOnMeshUpdate;                               // 0x0581(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x0582(0x0006) MISSED OFFSET
	TArray<class UBodySetup*>                          BodySetups;                                               // 0x0588(0x0010) (ZeroConstructor, Transient)
	unsigned char                                      UnknownData02[0x28];                                      // 0x0598(0x0028) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class MRMesh.MRMeshComponent");
		return ptr;
	}


	bool IsConnected();
	void ForceNavMeshUpdate();
	void Clear();
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
