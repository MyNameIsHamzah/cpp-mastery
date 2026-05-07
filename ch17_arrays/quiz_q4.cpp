#include <iostream>
#include <limits>

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

bool hasGoneBust(Player& player) {
    if (player.score > settings::blackjack) {
        return true;
    }
    return false;
}

void handleDealersTurn(Player& dealer, Deck& deck) {
    do {
        auto& card{dealCard(dealer, deck)};
        std::cout << "The dealer flips a " << card << ". They now have: " << dealer.score << "\n";
    } while ((dealer.score < settings::dealerLimit) &&
             !hasGoneBust(dealer));  // handle dealer going bust!
    if (hasGoneBust(dealer)) {
        std::cout << "The dealer went bust!\n";
    }
}

void handlePlayerTurn(Player& player, Deck& deck, char input) {
    auto& card{dealCard(player, deck)};
    std::cout << "You were dealt " << card << ". You now have: " << player.score << "\n";
}

char handlePlayerInput() {
    char input{};
    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";
        std::cin >> input;
        if (std::cin.fail() || std::cin.peek() != '\n' || (input != 'h' || input != 's')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
    return input;
}

void playBlackjack(Player& dealer, Player& player, Deck& deck) {
    deck.shuffle();

    dealInitialCards(dealer, player, deck);
    displayScores(dealer, player);

    while (true) {
        char input{handlePlayerInput()};
        if (input == 's') {
            break;
        }
        handlePlayerTurn(player, deck, input);
        if (hasGoneBust(player)) {
            std::cout << "You went bust!\n";
            break;
        }
    }

    handleDealersTurn(dealer, deck);

    if (hasPlayerWon(dealer, player)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose!\n";
    }
}

int main() {
    Player dealer;
    Player player;
    Deck deck;
    playBlackjack(dealer, player, deck);
}

// this logic is all fucked up. need to think about this properly.