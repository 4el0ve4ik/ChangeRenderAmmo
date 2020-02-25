#include <Windows.h>
#include <process.h>

void Thread(void*) {
	*reinterpret_cast<unsigned char*>(0x589477) = 0x50;
	*reinterpret_cast<unsigned char*>(0x589478) = 0x51;
}

BOOL APIENTRY DllMain(HMODULE, DWORD  fdwReason, LPVOID) {
	if (fdwReason == DLL_PROCESS_ATTACH)
		_beginthread(Thread, NULL, NULL);

	return TRUE;
}