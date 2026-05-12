#include <cstddef>
#include <iostream>
#include <limits>

void scalar() {
    int* ptr{new int{5}};  // pointer to int 5 on the heap
    std::cout << *ptr << "\n";

    delete ptr;         // delete the contents in the heap
    ptr = new int{20};  // assign new int on the heap and point to it
    std::cout << *ptr << "\n";

    delete ptr;  // deletes
    ptr = nullptr;

    std::cout << *ptr << "\n";
}

void printCStyleNewArray(int* array, std::size_t length) {
    std::cout << "here are the contents: ";
    for (std::size_t i{0}; i < length; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void nonScalar() {
    std::size_t length{5};
    int* array{new int[length]{1, 2, 3, 4, 5}};
    std::cout << "allocated an array of integers wiith length " << length << "\n";
    printCStyleNewArray(array, length);
    delete[] array;
    array = nullptr;
}

void quiz() {
    std::size_t x;
    while (true) {
        std::cout << "How many names would you like to enter? ";
        std::cin >> x;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
}

int main() {
    nonScalar();
    return 0;
}