#include <iostream>
#include <limits>
#include <string>

#include "q2.hpp"
#include "random.hpp"

class Player {
   private:
    std::string m_playerName{};
    int m_gold{};

   public:
    Player() : m_gold(generateInitialGold()) {};

    int generateInitialGold() { return Random::get(80, 120); };

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

    void farewell() { std::cout << "Thanks for shopping at Roscoe's potion emporium!"; }

    void startGame() {
        welcomePlayer();
        Potion::shop();
        farewell();
    }
};

int main() {
    Player player;
    player.startGame();
}