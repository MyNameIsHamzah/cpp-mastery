#pragma once
#include <array>
#include <iostream>

struct Card {
    enum Rank {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_size
    };

    enum Suit { suit_clubs, suit_diamonds, suit_hearts, suit_spades, suit_size };

    static constexpr std::array allSuits{suit_clubs, suit_diamonds, suit_hearts, suit_spades};
    static constexpr std::array allRanks{rank_ace,  rank_2,     rank_3,   rank_4, rank_5,
                                         rank_6,    rank_7,     rank_8,   rank_9, rank_10,
                                         rank_jack, rank_queen, rank_king};

    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        const std::array<std::string_view, 4> suits{"C", "D", "H", "S"};
        const std::array<std::string_view, 14> ranks{"A", "2", "3",  "4", "5", "6", "7",
                                                     "8", "9", "10", "J", "Q", "K"};
        out << ranks[card.rank] << suits[card.suit];
        return out;
    }

    Rank rank{};
    Suit suit{};
};