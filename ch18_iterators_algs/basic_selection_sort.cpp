#include <array>
#include <iostream>
#include <iterator>
#include <utility>

template <typename T, std::size_t N>
void printArray(std::array<T, N>& arr) {
    for (std::size_t i{0}; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template <typename T, std::size_t N>
void selectionSort(std::array<T, N>& arr) {
    for (std::size_t i{0}; i < N - 1; ++i) {
        std::size_t smallestIndex{i};
        for (std::size_t j{i + 1}; j < N; ++j) {
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        std::swap(arr[i], arr[smallestIndex]);
        printArray(arr);
    }
}

template <typename T, std::size_t N>
void selectionSortDescending(std::array<T, N>& arr) {
    for (std::size_t i{0}; i < N - 1; ++i) {
        std::size_t smallestIndex{i};
        for (std::size_t j{i + 1}; j < N; ++j) {
            if (arr[j] > arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        std::swap(arr[i], arr[smallestIndex]);
        printArray(arr);
    }
}

int main() {
    std::array<std::size_t, 6> arr{30, 60, 20, 50, 40, 10};
    printArray(arr);
    selectionSortDescending(arr);
    return 0;
}