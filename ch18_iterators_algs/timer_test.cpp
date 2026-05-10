
#include "timer.hpp"

#include <array>
#include <cstddef>
#include <iostream>

#include "random.hpp"

template <typename T, std::size_t N>
void printArray(std::array<T, N>& arr) {
    for (std::size_t i{0}; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

std::array<int, 100000> generateArr() {
    std::array<int, 100000> arr{};
    for (auto i{0}; i < 100000; ++i) {
        arr[i] = Random::get(1, 9);
    }
    return arr;
}

template <typename T, std::size_t N>
void selectionSort(std::array<T, N> arr) {
    Timer t;
    for (std::size_t i{0}; i < N - 1; ++i) {
        std::size_t smallestIndex{i};
        for (std::size_t j{i + 1}; j < N; ++j) {
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        std::swap(arr[i], arr[smallestIndex]);
    }
    std::cout << "selection sort: " << t.nanoseconds() << "ns\n";  // returns 8756306504ns
}

template <typename T, std::size_t N>
void stdSort(std::array<T, N> arr) {
    Timer t;
    std::sort(arr.begin(), arr.end());
    std::cout << "std lib sort: " << t.nanoseconds() << "ns\n";  // returns 5328310ns
}

int main() {
    auto data{generateArr()};
    selectionSort(data);
    stdSort(data);
    return 0;
}