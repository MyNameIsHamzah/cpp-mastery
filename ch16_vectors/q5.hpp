#pragma once
#include "random.hpp"

#include <iostream>

namespace WordList
{
    std::vector<std::string_view> words{"mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

    std::string_view getRandomWord()
    {
        std::size_t index{Random::get(static_cast<std::size_t>(0), words.size())};
        return words[index];
    }
}
