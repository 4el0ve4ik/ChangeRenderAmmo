#include <Windows.h>
#include <process.h>

//меняем аргументы sprintf местами
void Thread(void*) {
	unsigned long oldProt;
	VirtualProtect((void*)0x589477, 2, PAGE_EXECUTE_READWRITE, &oldProt);
	*reinterpret_cast<unsigned char*>(0x589477) = 0x50;// push eax
	*reinterpret_cast<unsigned char*>(0x589478) = 0x51;// push ecx
	VirtualProtect((void*)0x589477, 2, oldProt, NULL);
}

BOOL APIENTRY DllMain(HMODULE, DWORD  fdwReason, LPVOID) {
	if (fdwReason == DLL_PROCESS_ATTACH)
		_beginthread(Thread, NULL, NULL);

	return TRUE;
}
