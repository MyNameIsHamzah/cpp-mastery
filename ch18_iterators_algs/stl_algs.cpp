#include <algorithm>
#include <array>
#include <iostream>

template <typename T, std::size_t N>
void find(std::array<T, N>& arr, T search) {
    auto found{std::find(arr.begin(), arr.end(), search)};
    if (found == arr.end()) {
        std::cout << "Could not find " << search << "\n";
    } else {
        std::cout << "found: " << *found;
    }
}

template <typename T>
bool isGreaterThanTwo(T n) {
    return n > 2;
}

template <typename T>
bool containsTwo(T n) {
    return n == 2;
}

template <typename T, std::size_t N>
void findIf(std::array<T, N>& arr) {
    auto found{std::find_if(arr.begin(), arr.end(), isGreaterThanTwo<T>)};
    if (found == arr.end()) {
        std::cout << "Could not find number greater than 2\n";
    } else {
        std::cout << "first value found that meets the predicate: " << *found;
    }
}

template <typename T, std::size_t N>
void count(std::array<T, N>& arr) {
    auto instances{std::count(arr.begin(), arr.end(), 2)};
    std::cout << "Counted " << instances << " instances of 2";
}

template <typename T, std::size_t N>
void countIf(std::array<T, N>& arr) {
    auto instances{std::count_if(arr.begin(), arr.end(), containsTwo<T>)};
    std::cout << "Counted " << instances << " instances of 2";
}
template <typename T, std::size_t N>
void sort(std::array<T, N>& arr) {
    std::sort(arr.begin(),
              arr.end());  // by default is ascending sort but can make desc by std::greater{}

    for (T i : arr) {
        std::cout << i << " ";
    }
}

int main() {
    std::array<int, 5> arr{3, 2, 1, 4, 5};

    // find(arr, 2);
    // findIf(arr);
    // count(arr);
    // countIf(arr);
    sort(arr);
    return 0;
}