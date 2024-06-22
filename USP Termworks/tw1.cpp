#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include <iostream>
#include <unistd.h>
#include <limits.h>
#include<bits/stdc++.h>

int main() {
    int ch;
    long res;

    std::cout << "Enter the choice (1 for runtime limits, 2 for compile-time limits): ";
    std::cin >> ch;

    switch (ch) {
        case 1:
            std::cout << "Runtime configuration limits:\n";

            res = sysconf(_SC_CLK_TCK);
            std::cout << "Number of Clock Ticks: " << (res == -1 ? "System does not support" : std::to_string(res)) << std::endl;

            res = sysconf(_SC_CHILD_MAX);
            std::cout << "Maximum Number of Child Processes: " << (res == -1 ? "System does not support" : std::to_string(res)) << std::endl;

            res = pathconf("/", _PC_PATH_MAX);
            std::cout << "Maximum Path Length: " << (res == -1 ? "System does not support" : std::to_string(res)) << std::endl;

            res = pathconf("/", _PC_NAME_MAX);
            std::cout << "Maximum Characters in Filename: " << (res == -1 ? "System does not support" : std::to_string(res)) << std::endl;

            res = sysconf(_SC_OPEN_MAX);
            std::cout << "Maximum Number of Open Files: " << (res == -1 ? "System does not support" : std::to_string(res)) << std::endl;
            break;

        case 2:
            std::cout << "Compile-time configuration limits:\n";
            std::cout << "Maximum Child Processes: " << _POSIX_CHILD_MAX << std::endl;
            std::cout << "Maximum Open Files: " << _POSIX_OPEN_MAX << std::endl;
            std::cout << "Maximum Path Length: " << _POSIX_PATH_MAX << std::endl;
            std::cout << "Maximum Filename Length: " << _POSIX_NAME_MAX << std::endl;
            break;

        default:
            std::cout << "Invalid choice\n";
    }

    return 0;
}
