#include "deck.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>

Deck::Deck() {  // could use a lambda here to avoid copies
    std::size_t index{0};
    for (auto suit : Card::allSuits) {
        for (auto rank : Card::allRanks) {
            m_deck[index] = Card{rank, suit};
            index++;
        }
    }
}

Card Deck::dealCard() {
    assert(currentIndex != std::size(m_deck));
    Card& currentCard{m_deck[currentIndex]};
    currentIndex++;
    return currentCard;
}

void Deck::shuffle() {
    currentIndex = 0;
    std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
}
