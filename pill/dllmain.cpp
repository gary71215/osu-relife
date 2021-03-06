#include "hooks.h"
#include "factory.h";
#include "ui.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{

	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {

		srand(time(NULL));

		/*AllocConsole();
		FILE* fout = NULL;
		freopen_s(&fout, "CONOUT$", "w", stdout);*/

		Initialize_Factory();
		Initialize_UI(hModule);


		Initialize_Hooks();
		MAC_Hook();
		WMIGet_Hook();
		RegQuery_Hook();
		AddrInfoW_Hook();
		Hook_CertGetCertificateChain();
	}

    return TRUE;
}

