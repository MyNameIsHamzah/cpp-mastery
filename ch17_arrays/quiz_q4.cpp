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
    if (randomCard.rank == Card::rank_ace && player.score > settings::blackjack) {
        player.score -= 10;
    }
    return randomCard;
}

void dealAndDisplayInitialCards(Player& dealer, Player& player, Deck& deck) {
    std::cout << "The dealer is showing " << dealCard(dealer, deck) << " (" << dealer.score
              << ")\n";

    std::cout << "You are showing " << dealCard(player, deck) << " " << dealCard(player, deck)
              << " (" << player.score << ")\n";
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
        if (player.score == dealer.score) {
            std::cout << "It's a draw!\n";
        } else {
            std::cout << "You lose!\n";
        }
    }
}

void playBlackjack(Player& dealer, Player& player, Deck& deck) {
    deck.shuffle();
    dealAndDisplayInitialCards(dealer, player, deck);

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