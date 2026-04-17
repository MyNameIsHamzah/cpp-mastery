#include "q5.hpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <limits>
#include <string>

class Session
{
private:
    std::string_view m_word{};
    int m_pluses{6};
    std::vector<char> m_obfuscated_word{};
    std::vector<char> m_guessed_letters{};
    std::vector<char> m_incorrect_letters{};

public:
    Session() : m_word{WordList::getRandomWord()} {};

    void createObfuscatedWord()
    {
        for (std::size_t i{0}; i < m_word.length(); i++)
        {
            m_obfuscated_word.push_back('_');
        }
        assert(m_obfuscated_word.size() == m_word.length());
    }

    void displayObfuscatedWord()
    {
        std::cout << "\nThe word is: ";
        for (const auto &x : m_obfuscated_word)
        {
            std::cout << x << " ";
        }
        displayLives();
    }

    void displayLives()
    { // refactor to have a vector of plusses then push back the wrong char to it
        std::cout << "\t Lives left " << m_pluses << "\n";
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
        if (hasLetterBeenGuessed(x))
        {
            std::cout << "You already guessed that. Try again.\n";
            return;
        }
        for (std::size_t i{0}; i < secretWord.size(); i++)
        {
            if (secretWord[i] == x) // what if they write a guess for a letter thats already been accounted for??
                                    // add a user guess vector of chars thats been guessed already. and just check that
            {
                m_obfuscated_word[i] = x;
                m_guessed_letters.push_back(x);
                found = true;
                std::cout << "Yes, " << "'" << x << "'" << "is in the word!\n";
            }
        }
        if (found)
            return;

        std::cout << "No " << "'" << x << "'" << "is not in the word!\n";
        m_pluses--;
        return;
    }

    bool hasWon(std::vector<char>& v){
        if (v.size() == m_guessed_letters.size()){
        bool noUnderscore{true};
        for (std::size_t i{0}; i < v.size(); i++){
            if (m_obfuscated_word[i] == '_'){
                noUnderscore = false;
            }
        }
        if (noUnderscore){
            return true;
        }
        }   
        return false;
    }

    bool hasLetterBeenGuessed(char x)
    {
        for (char i : m_guessed_letters)
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

    void startGame() // add logic for if the uesr gets the game correct
                     //  mesmssages like yes the letter is in the word and the same for if its not in the word,
                     // do not deduct lives for invalid inputs.
    {
        std::cout << "Welcone to C++man (a variant of Hangman)\n";
        std::cout << "To win: guess the word. To lose: run out of pluses.\n\n";

        std::vector<char> wordAsVector(m_word.begin(), m_word.end());
        createObfuscatedWord();

        do
        {
            displayObfuscatedWord();
            char guess{enterGuess()};
            checkLetter(guess, wordAsVector);
            if(hasWon(wordAsVector)){
                std::cout << "You won! the word was " << m_word << "\n";
                break;
            }
        } while (m_pluses > 0);

        if (m_pluses == 0){
        std::cout << "You lost! The word was: " << m_word;
        }
    }
};

int main()
{
    Session session{};
    session.startGame();
}