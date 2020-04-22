#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE, DWORD  fdwReason, LPVOID) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		unsigned long oldProt;
		VirtualProtect((void*)0x589477, 2, PAGE_EXECUTE_READWRITE, &oldProt);
		*reinterpret_cast<unsigned char*>(0x589477) = 0x50;// push eax
		*reinterpret_cast<unsigned char*>(0x589478) = 0x51;// push ecx
		VirtualProtect((void*)0x589477, 2, oldProt, NULL);
	}
	
	return TRUE;
}
