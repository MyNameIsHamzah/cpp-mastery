#include "q5.hpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <limits>
#include <string>
#include <algorithm>

class Session
{
private:
    std::string_view m_word{};
    std::vector<char> m_wordAsVector = std::vector<char>(m_word.begin(), m_word.end());
    std::size_t m_pluses{6};
    std::vector<char> m_obfuscated_word = std::vector<char>(m_word.length(), '_');
    std::vector<char> m_guessed_letters{};
    std::vector<char> m_incorrect_letters{};

public:
    Session() : m_word{WordList::getRandomWord()} {};

    void displayObfuscatedWord()
    {
        std::cout << "\nThe word is: ";
        for (const auto &x : m_obfuscated_word)
        {
            std::cout << x << " ";
        }
    }

    void displayLives()
    {
        std::cout << "\tWrong guesses: ";
        for (std::size_t i{0}; i < m_pluses; i++)
        {
            std::cout << '+' << " ";
        }
        if (m_incorrect_letters.size() > 0)
        {
            for (auto i : m_incorrect_letters)
            {
                std::cout << i << " ";
            }
        }
        std::cout << "\n";
    }

    char enterGuess()
    {
        char x;
        while (true)
        {
            std::cout << "Enter your next letter: ";
            std::cin >> x;

            if (((x > 'z') || (x < 'a')) || std::cin.fail())
            {
                std::cin.clear();
                clearErroneousInput();
                std::cout << "That wasn't a valid input. Try again.\n";
                continue;
            }
            clearErroneousInput();
            return x;
        }
    }

    void checkLetter(char x, std::vector<char> &secretWord)
    {
        bool found{false};
        if (hasLetterBeenGuessed(x, m_guessed_letters) || hasLetterBeenGuessed(x, m_incorrect_letters))
        {
            std::cout << "You already guessed that. Try again.\n";
            return;
        }
        for (std::size_t i{0}; i < secretWord.size(); i++)
        {
            if (secretWord[i] == x)
            {
                m_obfuscated_word[i] = x;
                m_guessed_letters.push_back(x);
                found = true;
            }
        }
        if (found)
        {
            std::cout << "Yes, " << "'" << x << "'" << " is in the word!\n";
            return;
        }
        m_pluses--;
        m_incorrect_letters.push_back(x);
        if (m_incorrect_letters.size() > 1)
        {
            std::sort(m_incorrect_letters.begin(), m_incorrect_letters.end());
        }
        std::cout << "No " << "'" << x << "'" << " is not in the word!\n";
        return;
    }

    bool hasWon(std::vector<char> &v)
    {
        if (v.size() == m_guessed_letters.size())
        {
            bool noUnderscore{true};
            for (std::size_t i{0}; i < v.size(); i++)
            {
                if (m_obfuscated_word[i] == '_')
                {
                    noUnderscore = false;
                }
            }
            if (noUnderscore)
            {
                return true;
            }
        }
        return false;
    }

    bool hasLetterBeenGuessed(char x, std::vector<char> &v)
    {
        for (char i : v)
        {
            if (i == x)
            {
                return true;
            }
        }
        return false;
    }

    void clearErroneousInput()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void startGame()
    {
        std::cout << "Welcone to C++man (a variant of Hangman)\n";
        std::cout << "To win: guess the word. To lose: run out of pluses.\n\n";
        do
        {
            displayObfuscatedWord();
            displayLives();
            checkLetter(enterGuess(), m_wordAsVector);
            if (hasWon(m_wordAsVector))
            {
                std::cout << "\nYou won! The word was: " << m_word << "\n";
                break;
            }
        } while (m_pluses > 0);
        if (m_pluses == 0)
        {
            displayObfuscatedWord();
            displayLives();
            std::cout << "You lost! The word was: " << m_word << "\n";
        }
    }
};

int main()
{
    Session session{};
    session.startGame();
}