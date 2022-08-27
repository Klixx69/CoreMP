#pragma once

std::fstream LogFile;

#define CORE_LOG(Category, Msg, ...) \
Util::Log(#Category, std::format(Msg, __VA_ARGS__));

#define CREATE_HOOK(Address, Hook, Og) \
MH_CreateHook((void*)(Address), Hook, (void**)(Og)); \
MH_EnableHook((void*)(Address));

#define DISABLE_HOOK(Address) \
MH_DisableHook((void*)(Address));

#define ENABLE_HOOK(Address) \
MH_EnableHook((void*)(Address));

class Util
{
public:
	static __forceinline VOID InitConsole()
	{
		FILE* fDummy;
		AllocConsole();
		freopen_s(&fDummy, "CONIN$", "r", stdin);
		freopen_s(&fDummy, "CONOUT$", "w", stdout);

		LogFile.open("Core.log");
	}

	static __forceinline uintptr_t BaseAddress()
	{
		return reinterpret_cast<uintptr_t>(GetModuleHandle(0));
	}

	static __forceinline void Log(std::string Category, std::string Msg)
	{
		std::cout << "LogCore: " << Category << ": " << Msg << std::endl;
		LogFile << "LogCore: " << Category << ": " << Msg << std::endl;
	}
};