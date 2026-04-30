#include <cstring>
#include <iostream>
#include <iterator>

void printCStyle(const char str[]) {
    for (; *str != '\0'; ++str) {
        std::cout << *str;
    }
}

void printCStyleBackwards(const char str[]) {
    for (auto* ptr{str + std::strlen(str)}; ptr != str;) {
        --ptr;
        std::cout << *ptr;
        std::cout << 'a';
    }
    std::cout << "\n";
}

void printCStyleBackwardsWhile(const char str[]) {
    auto* ptr{str + std::strlen(str)};

    while (ptr != str) {
        --ptr;
        std::cout << *ptr;
    }
    std::cout << "\n";
}
int main() {
    printCStyleBackwards("");
    printCStyleBackwardsWhile("Hello World! I'm fruity");

    const char* const color{"Orange"};
    std::cout << color;
    std::cout << static_cast<const void*>(color)
              << "\n";  // we have to cast to const void in order to get the memory address of color
    return 0;
}