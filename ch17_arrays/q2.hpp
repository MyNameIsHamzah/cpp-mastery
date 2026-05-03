#pragma once
#include <array>
#include <iostream>
#include <string>

namespace Potion {
enum Type { healing, mana, speed, invisibility, max_type };
constexpr std::array<int, 4> prices{20, 30, 12, 50};
constexpr std::array<std::string_view, 4> names{"healing", "mana", "speed", "invisibility"};

void shop() {
    std::cout << "Here is our selection for today:\n";
    for (std::size_t i{0}; i < static_cast<size_t>(max_type); ++i) {
        std::cout << i << ") " << names[i] << " costs " << prices[i] << "\n";
    }
    std::cout << "\n";
}
};  // namespace Potion