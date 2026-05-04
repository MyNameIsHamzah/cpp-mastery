#include <algorithm>
#include <cassert>
#include <iostream>

#include "deck.hpp"

int main() {
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}