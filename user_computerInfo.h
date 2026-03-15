#include <cstdio>
#include <lib/windows.h>
#include <lib/cstdlib>
#include <lib/iphlpapi.h>
#include <lib/winsock2.h>
#include <lib/stdlib.h>
#include <lib/string.h>
// #pragma comment(lib, "iphlpapi.lib")

// void getMemory() {
//     MEMORYSTATUSEX statex;
//     statex.dwLength = sizeof(statex);
//     if (GlobalMemoryStatusEx(&statex)) {
//         printf("Всего RAM: %llu MB\n", statex.ullTotalPhys / (1024 * 1024));
//         printf("Свободно RAM: %llu MB\n", statex.ullAvailPhys / (1024 * 1024));
//     }
// }

// void getCpuName() {
//     HKEY hKey;
//     char cpuName[255];
//     DWORD bufferSize = sizeof(cpuName);
    
//     // Путь в реестре, где хранится название процессора
//     if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
//         RegQueryValueExA(hKey, "ProcessorNameString", NULL, NULL, (LPBYTE)cpuName, &bufferSize);
//         printf("Процессор: %s\n", cpuName);
//         RegCloseKey(hKey);
//     }
// }

// void getOSVersion() {
//     OSVERSIONINFO osvi;
//     ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
//     osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
//     GetVersionEx(&osvi);
//     printf("Версия Windows: %d.%d\n", osvi.dwMajorVersion, osvi.dwMinorVersion);
// }

// void getNetworkInfo() {
//     // Выделение памяти для структуры (упрощенный пример)
//     ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
//     PIP_ADAPTER_INFO pAdapterInfo = (PIP_ADAPTER_INFO)malloc(ulOutBufLen);
    
//     // Получение информации
//     if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
//         free(pAdapterInfo);
//         pAdapterInfo = (PIP_ADAPTER_INFO)malloc(ulOutBufLen);
//     }

//     if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == NO_ERROR) {
//         for (PIP_ADAPTER_INFO pAdapter = pAdapterInfo; pAdapter; pAdapter = pAdapter->Next) {
//             printf("Адаптер: %s | IP: %s | MAC: ", pAdapter->Description, pAdapter->IpAddressList.IpAddress.String);
//             for (UINT i = 0; i < pAdapter->AddressLength; i++)
//                 printf("%.2X%c", pAdapter->Address[i], (i == pAdapter->AddressLength - 1) ? '\n' : '-');
//         }
//     }
//     if (pAdapterInfo) free(pAdapterInfo);
// }

void print_system () {
    printf ("================== Info about system ===============");
    system("systeminfo");
    system ("ipconfig");
    printf ("================== Processor ===============");
    system("wmic cpu get name");
    system("numberofcores");
    system("maxclockspeed");
    printf ("================== RAM ===============");
    system("wmic memorychip get capacity");
    system("speed");
    printf ("================== Net ===============");
    system("ipconfig /all");
    system("getmac");
    printf ("================== Other data ===============");
    system("tasklist");
    system("wmic diskdrive get model");
    system("./System_Report.bat");
}