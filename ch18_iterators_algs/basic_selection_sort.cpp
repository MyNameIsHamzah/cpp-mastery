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

template <typename T, std::size_t N>
void bubbleSort(std::array<T, N>& arr) {
    auto iteration{0};
    while (true) {
        bool swapHappened{false};
        for (std::size_t i{0}; i < N - 1; ++i) {
            if (arr[i + 1] < arr[i]) {
                std::swap(arr[i + 1], arr[i]);
                swapHappened = true;
            }
        }
        iteration++;
        if (!swapHappened) {
            break;
        }
    }
    std::cout << "Early termination on iteration " << iteration << "\n";
}

int main() {
    std::array<std::size_t, 9> arr{6, 3, 2, 9, 7, 1, 5, 4, 8};
    printArray(arr);
    bubbleSort(arr);
    printArray(arr);
    return 0;
}