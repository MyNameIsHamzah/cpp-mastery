#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

int main() {
    const int numRow{10};
    const int numCol{10};
    // int arr[numRow][numCol]{}; //cstyle declaration
    std::array<std::array<int, numCol>, numRow> arr{};
    for (std::size_t row{1}; row < numRow; ++row) {
        for (std::size_t col{1}; col < numCol; col++) {
            arr[row][col] = static_cast<int>(row * col);
        }
    }
    for (std::size_t row{1}; row < numRow; ++row) {
        for (std::size_t col{1}; col < numCol; col++) {
            std::cout << arr[row][col] << '\t';
        }
        std::cout << "\n";
    }
    return 0;
}