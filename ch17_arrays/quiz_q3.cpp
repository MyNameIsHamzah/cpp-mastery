#include <algorithm>
#include <cassert>
#include <iostream>

#include "q3.hpp"
#include "random.hpp"

class Deck {
   private:
    std::array<Card, 52> m_deck;
    std::size_t currentIndex{0};

   public:
    Deck() {  // could use a lambda here to avoid copies
        std::size_t index{0};
        for (auto suit : Card::allSuits) {
            for (auto rank : Card::allRanks) {
                m_deck[index] = Card{rank, suit};
                index++;
            }
        }
    }
    Card dealCard() {
        assert(currentIndex != std::size(m_deck));
        auto currentCard{m_deck[currentIndex]};
        currentIndex++;
        return currentCard;
    }
    void shuffle() {
        currentIndex = 0;
        std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
    }
};

int main() {
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}