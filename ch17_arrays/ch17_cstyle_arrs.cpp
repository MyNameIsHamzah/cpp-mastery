#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <optional>

namespace ProgramData {
static constexpr int perfectSquares[]{0, 1, 4, 9};
}
bool isSquare(const int input) {
    for (int i : ProgramData::perfectSquares) {
        if (i == input) {
            return true;
        }
    }
    return false;
}

int takeUserInput() {
    while (true) {
        int x{};
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        std::cin >> x;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return x;
    }
}

int main() {
    while (true) {
        int x{takeUserInput()};
        if (x == -1) {
            break;
        }
        if (isSquare(x)) {
            std::cout << x << " is a perfect square\n";
        } else {
            std::cout << x << " is not a perfect square\n";
        }
    }
    std::cout << "Bye\n";
    return 0;
}