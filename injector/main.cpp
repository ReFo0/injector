#include <Windows.h>
#include <string>
#include <iostream>
#include "process.h"





int main()
{
    char path[MAX_PATH];
    GetFullPathName("example.dll", MAX_PATH, path, NULL);
    auto process = find_process("notepad.exe");
    if (!process)
    {
     std::cout << "process not found." << std::endl;
     std::cin.get();
     return 0;
    }
    else {
        std::cout << "process found." << std::endl;
        Sleep(2000);
        auto handle = OpenProcess(PROCESS_ALL_ACCESS, 0, process);
        if (handle && handle != INVALID_HANDLE_VALUE)
        {
            auto module = LoadLibraryA("ntdll.dll");
            const auto entry = GetProcAddress(module, "NtSetSystemTime");
            if (entry)
            {
                char byte[5];
                memcpy(byte, entry, 5);
                WriteProcessMemory(handle, entry, byte, 5, nullptr);
            }

            auto* alls = VirtualAllocEx(handle, nullptr, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
            WriteProcessMemory(handle, alls, path, strlen(path) + 1, nullptr);
            auto thread = CreateRemoteThread(handle, nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(LoadLibraryA), alls, 0, nullptr);
            Sleep(5);
            CloseHandle(thread);
            CloseHandle(handle);
            Sleep(5);
        }
    }
    return 0;
}