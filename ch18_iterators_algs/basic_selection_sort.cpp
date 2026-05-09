#include <array>
#include <iostream>
#include <iterator>
#include <utility>

template <typename T, std::size_t N>
void selectionSort(std::array<T, N>& arr) {
    for (std::size_t i{0}; i < N - 1; ++i) {
        std::size_t smallestIndex{i};
        for (std::size_t j{i + 1}; j < N; ++j) {
            if (arr[j] < arr[i]) {
                smallestIndex = j;
            }
        }
        std::swap(arr[i], arr[smallestIndex]);
    }
}

template <typename T, std::size_t N>
void printArray(std::array<T, N>& arr) {
    for (std::size_t i{0}; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
int main() {
    std::array<std::size_t, 6> arr{30, 60, 20, 50, 40, 10};
    printArray(arr);
    selectionSort(arr);
    printArray(arr);

    return 0;
}