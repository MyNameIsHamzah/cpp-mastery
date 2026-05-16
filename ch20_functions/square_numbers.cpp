#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>

#include "random.hpp"

int promptInt(std::string_view prompt) {
    int num{};
    while (true) {
        std::cout << prompt;
        std::cin >> num;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        break;
    }
    return num;
}

std::vector<int> generateSquares(const int start, const int amount, const int multiplier) {
    std::vector<int> generatedNums;
    for (int i{start}; i < start + amount; ++i) {
        auto val{(i * i) * multiplier};
        generatedNums.push_back(val);
    }
    return generatedNums;
}

bool checkAnswer(std::vector<int>& vec, const int ans) {
    auto found{std::find(vec.begin(), vec.end(), ans)};
    if (found == vec.end()) {
        return false;
    } else {
        *found = vec.back();  // overwrite target with last element and pop - O(1) unordered remove
        vec.pop_back();
        return true;
    }
}

int main() {
    std::string_view startMessage{"Start where? "};
    std::string_view amountMessage{"How many? "};
    std::string_view enterAnsMessage{"> "};

    const int start{promptInt(startMessage)};
    const int amount{promptInt(amountMessage)};
    const int multiplier{Random::get(2, 4)};

    std::vector<int> vec{generateSquares(start, amount, multiplier)};

    std::cout << "I generated " << amount
              << " square numbers. Do you know what each number is after multiplying it by "
              << multiplier << "?\n";

    while (!vec.empty()) {
        int ans{promptInt(enterAnsMessage)};
        if (checkAnswer(vec, ans)) {
            if (vec.empty()) {
                std::cout << "Nice! You found all numbers, good job!\n";
            } else {
                std::cout << "Nice! " << vec.size() << " number(s) left.\n";
            }
        } else {
            auto smallestRange{std::min_element(vec.begin(), vec.end(), [&ans](int a, int b) {
                return std::abs(a - ans) < std::abs(b - ans);
            })};
            std::cout << ans << " is wrong! Try " << *smallestRange << " next time.\n";
        }
    }
    return 0;
}