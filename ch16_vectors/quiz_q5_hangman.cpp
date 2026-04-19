#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "q5.hpp"

class Session {
   private:
    std::string_view m_word{};
    std::size_t m_pluses{6};
    std::vector<char> m_obfuscated_word;
    std::vector<char> m_guessed_letters{};
    std::vector<char> m_incorrect_letters{};

    void displayObfuscatedWord() {
        std::cout << "\nThe word is: ";
        for (const auto& x : m_obfuscated_word) {
            std::cout << x << " ";
        }
    }

    void displayLives() {
        std::cout << "\tWrong guesses: ";
        for (std::size_t i{0}; i < m_pluses; i++) {
            std::cout << '+' << " ";
        }
        if (m_incorrect_letters.size() > 0) {
            for (auto i : m_incorrect_letters) {
                std::cout << i << " ";
            }
        }
        std::cout << "\n";
    }

    char enterGuess() {
        char x;
        while (true) {
            std::cout << "Enter your next letter: ";
            std::cin >> x;

            if (((x > 'z') || (x < 'a')) || std::cin.fail()) {
                std::cin.clear();
                clearErroneousInput();
                std::cout << "That wasn't a valid input. Try again.\n";
                continue;
            }
            clearErroneousInput();
            return x;
        }
    }

    void checkLetter(char x) {
        bool found{false};
        if (contains(m_guessed_letters, x) || contains(m_incorrect_letters, x)) {
            std::cout << "You already guessed that. Try again.\n";
            return;
        }
        for (std::size_t i{0}; i < m_word.size(); i++) {
            if (m_word[i] == x) {
                m_obfuscated_word[i] = x;
                found = true;
            }
        }
        if (found) {
            m_guessed_letters.push_back(x);
            std::cout << "Yes, " << "'" << x << "'" << " is in the word!\n";
            return;
        }
        m_pluses--;
        m_incorrect_letters.push_back(x);
        if (m_incorrect_letters.size() > 1) {
            std::sort(m_incorrect_letters.begin(), m_incorrect_letters.end());
        }
        std::cout << "No " << "'" << x << "'" << " is not in the word!\n";
        return;
    }

    template <typename T, typename U>
    bool contains(const T& container, const U& value) const {
        return std::find(container.begin(), container.end(), value) != container.end();
    }

    bool hasWon() { return !contains(m_obfuscated_word, '_'); }

    bool hasLetterBeenGuessed(char x, const std::vector<char>& v) { return contains(v, x); }

    void clearErroneousInput() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

   public:
    Session() : m_word{WordList::getRandomWord()}, m_obfuscated_word(m_word.length(), '_') {};

    void startGame() {
        std::cout << "Welcome to C++man (a variant of Hangman)\n";
        std::cout << "To win: guess the word. To lose: run out of pluses.\n\n";
        do {
            displayObfuscatedWord();
            displayLives();
            checkLetter(enterGuess());
            if (hasWon()) {
                std::cout << "\nYou won! The word was: " << m_word << "\n";
                break;
            }
        } while (m_pluses > 0);
        if (m_pluses == 0) {
            displayObfuscatedWord();
            displayLives();
            std::cout << "You lost! The word was: " << m_word << "\n";
        }
    }
};

int main() {
    Session session{};
    session.startGame();
}