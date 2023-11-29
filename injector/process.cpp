#include <Windows.h>
#include <string>
#include <TlHelp32.h>
#include "process.h"

std::uint32_t find_process(const std::string& name)
{
    const auto snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) {
        return 0;
    }

    PROCESSENTRY32 proc_entry{};
    proc_entry.dwSize = sizeof proc_entry;

    auto found_process = false;
    if (!!Process32First(snap, &proc_entry)) {
        do {
            if (name == proc_entry.szExeFile) {
                found_process = true;
                break;
            }
        } while (!!Process32Next(snap, &proc_entry));
    }

    CloseHandle(snap);
    return found_process
        ? proc_entry.th32ProcessID
        : 0;
}
