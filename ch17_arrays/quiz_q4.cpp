#include <iostream>

#include "deck.hpp"
#include "settings.hpp"

struct Player {
    int score{0};
};

Card& dealCard(Player& player, Deck& deck) {
    auto& randomCard{deck.dealCard()};
    player.score +=
        randomCard.rankValue[randomCard.rank];  // need to find a clean way to handle the rank
                                                // values. Ace is 11, Face cards as 10.
    return randomCard;
}

void dealInitialCards(Player& dealer, Player& player, Deck& deck) {
    dealCard(dealer, deck);
    dealCard(player, deck);
    dealCard(player, deck);
}

void displayScores(Player& dealer, Player& player) {
    std::cout << "The dealer is showing: " << dealer.score << "\n";
    std::cout << "You have score: " << player.score << "\n";
}

bool hasPlayerWon(Player& dealer, Player& player) {
    if (player.score > dealer.score) {
        return true;
    }
    return false;
}

void handleDealersTurn(Player& dealer, Deck& deck) {
    do {
        auto& card{dealCard(dealer, deck)};
        std::cout << "The dealer flips a " << card << ". They now have: " << dealer.score << "\n";
    } while (dealer.score < settings::dealerLimit);  // handle dealer going bust!
}

void playBlackjack(Player& dealer, Player& player, Deck& deck) {
    deck.shuffle();

    dealInitialCards(dealer, player, deck);
    displayScores(dealer, player);

    handleDealersTurn(dealer, deck);

    if (hasPlayerWon(dealer, player)) {
        std::cout << "You win!";
    } else {
        std::cout << "You lose!";
    }
}

int main() {
    Player dealer;
    Player player;
    Deck deck;
    playBlackjack(dealer, player, deck);
}
