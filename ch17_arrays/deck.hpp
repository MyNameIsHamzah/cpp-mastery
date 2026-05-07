#pragma once
#include <algorithm>
#include <array>
#include <cassert>

#include "q3.hpp"
#include "random.hpp"

class Deck {
   private:
    std::array<Card, 52> m_deck;
    std::size_t currentIndex{0};

   public:
    Deck();
    Card dealCard();
    void shuffle();
};