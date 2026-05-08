#include <iostream>
#include <limits>

#include "deck.hpp"
#include "settings.hpp"

struct Player {
    int score{0};
    int numOfHighAces{0};
};

Card dealCard(Player& player, Deck& deck) {
    auto randomCard{deck.dealCard()};
    player.score += randomCard.rankValue[randomCard.rank];
    if (randomCard.rank == Card::rank_ace) {
        player.numOfHighAces += 1;
    }
    if (player.score > settings::blackjack && player.numOfHighAces > 0) {
        player.score -= 10;
        player.numOfHighAces--;
    }
    return randomCard;
}

void dealAndDisplayInitialCards(Player& dealer, Player& player, Deck& deck) {
    Card d1{dealCard(dealer, deck)};
    Card c1{dealCard(player, deck)};
    Card c2{dealCard(player, deck)};

    std::cout << "The dealer is showing " << d1 << " (" << dealer.score << ")\n";

    std::cout << "You are showing " << c1 << " " << c2 << " (" << player.score << ")\n";
}

bool hasGoneBust(const Player& player) {
    return player.score > settings::blackjack;
}

bool hasPlayerWon(const Player& dealer, const Player& player) {
    if ((player.score > dealer.score && player.score <= settings::blackjack) ||
        (hasGoneBust(dealer) && !hasGoneBust(player))) {
        return true;
    }
    return false;
}

void handleDealersTurn(Player& dealer, Deck& deck) {
    auto card{dealCard(dealer, deck)};
    std::cout << "The dealer flips a " << card << ". They now have: " << dealer.score << "\n";
}

void handlePlayerTurn(Player& player, Deck& deck) {
    auto card{dealCard(player, deck)};
    std::cout << "You were dealt " << card << ". You now have: " << player.score << "\n";
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
        handlePlayerTurn(player, deck);

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