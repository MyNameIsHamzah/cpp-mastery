#include <algorithm>
#include <array>
#include <iostream>

template <typename T, std::size_t N>

void find(std::array<T, N>& arr, const T predicate) {
    auto found{std::find_if(arr.begin(), arr.end(), [=](T n) { return n == predicate; })};

    if (found == arr.end()) {
        std::cout << "not found\n";

    } else {
        std::cout << "found\n";
    }
}

int main() {
    const std::size_t length{5};

    std::array<int, length> arr{1, 2, 3, 4, 5};

    find<int>(arr, 5);
}