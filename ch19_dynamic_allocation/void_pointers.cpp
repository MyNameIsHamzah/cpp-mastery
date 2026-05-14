#include <iostream>

int main() {
    void* ptr{new int{5}};  // to deref this pointer you have to cast to a typed pointer :(
    int* intPtr{static_cast<int*>(ptr)};
    std::cout << "int ptr address " << intPtr << "\n";
    std::cout << "int ptr deref value " << *intPtr << "\n";

    delete intPtr;
    intPtr = nullptr;
    std::cout << "int ptr address post nullptr " << intPtr << "\n";  // now at 0
    std::cout << "void ptr address " << ptr
              << "\n";  // still holds the former heap allocation address

    ptr = nullptr;  // ptr was dangling after delete! assign to nullptr
    std::cout << "void ptr address post nullptr " << ptr << "\n";  // now at 0

    return 0;
}