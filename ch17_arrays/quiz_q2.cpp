#include <array>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>

#include "q2.hpp"
#include "random.hpp"

class Player {
   private:
    std::string m_playerName{};
    int m_gold{};
    int generateInitialGold() { return Random::get(80, 120); };
    std::array<int, Potion::max_type> m_player_inventory{};

    void setName() {
        while (true) {
            std::cout << "Enter your name: ";
            std::cin >> m_playerName;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            break;
        }
    }

    void welcomePlayer() {
        std::cout << "Welcome to Roscoe's potion emporium!\n";
        setName();
        std::cout << "Hello, " << m_playerName << " you have " << m_gold << " gold.\n\n";
    }

    void farewell() { std::cout << "Thanks for shopping at Roscoe's potion emporium!\n"; }

    char takeChoice() {
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        char choice{};
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || ((choice < '0' || choice > '3') && choice != 'q') ||
                std::cin.peek() != '\n') {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "This is an invalid input. Try again: ";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        return choice;
    }

    Potion::Type charToPotionType(char choice) { return static_cast<Potion::Type>(choice - '0'); }

    void handleChoice(char choice) {
        auto choiceAsEnum{charToPotionType(choice)};
        int price{Potion::prices[choiceAsEnum]};
        std::string_view name{Potion::names[choiceAsEnum]};

        if (price > m_gold) {
            std::cout << "You can not afford that.\n";
            return;
        }
        m_gold -= price;
        m_player_inventory[choiceAsEnum] += 1;
        std::cout << "You purchased a potion of " << name << ". You have " << m_gold
                  << " gold left.\n\n";
    }
    void displayInventory() {
        std::cout << "Your inventory contains: \n";
        for (std::size_t i{0}; i < Potion::max_type; ++i) {
            if (m_player_inventory[i] > 0) {
                std::cout << m_player_inventory[i] << "x potion of " << Potion::names[i] << "\n";
            }
        }
        std::cout << "You escaped with " << m_gold << " gold remaining.\n\n";
    }

   public:
    Player() : m_gold(generateInitialGold()) {}

    void startGame() {
        welcomePlayer();
        while (true) {
            Potion::shop();
            char input{takeChoice()};
            if (input == 'q') {
                break;
            }
            handleChoice(input);
        }
        displayInventory();
        farewell();
    }
};

int main() {
    Player player;
    player.startGame();
}