#ifndef INTERNSHIP_TEST_UTILS_H
#define INTERNSHIP_TEST_UTILS_H

#include <fstream>

#ifdef _WIN32
#include <windows.h>
std::ifstream GetInputStream(char*) {
    int n_args;
    wchar_t** p_args = CommandLineToArgvW(GetCommandLineW(), &n_args);
    if (p_args == nullptr) {
        exit(1);
    }

    return {p_args[n_args - 1]};
}
#else
std::ifstream GetInputStream(char* path) { return std::ifstream(path); }
#endif

#endif  // INTERNSHIP_TEST_UTILS_H
