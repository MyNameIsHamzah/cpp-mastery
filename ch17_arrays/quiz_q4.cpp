#include <iostream>
#include <limits>

#include "deck.hpp"
#include "settings.hpp"

struct Player {
    int score{0};
};

Card dealCard(Player& player, Deck& deck) {
    auto randomCard{deck.dealCard()};
    player.score += randomCard.rankValue[randomCard.rank];
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

bool hasGoneBust(const Player& player) {
    return player.score > settings::blackjack;
}

bool hasPlayerWon(const Player& dealer, const Player& player) {
    if ((player.score > dealer.score && player.score <= settings::blackjack) ||
        hasGoneBust(dealer)) {
        return true;
    }
    return false;
}

void handleDealersTurn(Player& dealer, Deck& deck) {
    auto card{dealCard(dealer, deck)};
    std::cout << "The dealer flips a " << card << ". They now have: " << dealer.score << "\n";
}

void handlePlayerTurn(Player& player, Deck& deck, char input) {
    if (input == 'h') {
        auto card{dealCard(player, deck)};
        std::cout << "You were dealt " << card << ". You now have: " << player.score << "\n";
    }
}

char handlePlayerInput() {
    char input{};
    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";
        std::cin >> input;
        if ((input != 'h' && input != 's') || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
    return input;
}

void handleWinner(Player& dealer, Player& player) {
    if (hasPlayerWon(dealer, player)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose!\n";
    }
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
            return;
        }
    }

    while (true) {
        handleDealersTurn(dealer, deck);
        if (dealer.score >= settings::dealerLimit) {
            if (hasGoneBust(dealer)) {
                std::cout << "The dealer went bust!\n";
                return;
            }
            break;
        }
    }
}

int main() {
    Player dealer;
    Player player;
    Deck deck;
    playBlackjack(dealer, player, deck);
    handleWinner(dealer, player);
}