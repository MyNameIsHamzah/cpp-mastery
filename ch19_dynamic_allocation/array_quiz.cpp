#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>

std::size_t numOfNames() {
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
    return x;
}

std::string* createArray(const std::size_t numOfNames) {
    try {
        std::string* array{new std::string[numOfNames]};
        return array;
    } catch (const std::bad_alloc& e) {
        std::cerr << "allocation  failed: " << e.what() << "\n";
        return nullptr;
    }
}

void enterNames(std::string* arr, std::size_t length) {
    for (std::size_t i{0}; i < length; ++i) {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin, arr[i]);
    }
    std::cout << "\n";
}

void displayNames(std::string* arr, std::size_t length) {
    for (std::size_t i{0}; i < length; ++i) {
        std::cout << "Name #" << i + 1 << ": " << arr[i] << "\n";
    }
}

void sortNames(std::string* arr, std::size_t length) {
    std::sort(arr, arr + length);
}
void quiz() {
    const auto length{numOfNames()};
    std::string* names{createArray(length)};
    if (names == nullptr) {
        std::cout << "buy more RAM :(\n";
        return;
    }

    enterNames(names, length);
    sortNames(names, length);

    std::cout << "Here is your sorted list: \n";
    displayNames(names, length);

    delete[] names;  // going out of scocpe anyway no need to nullptr
}

int main() {
    quiz();
    return 0;
}