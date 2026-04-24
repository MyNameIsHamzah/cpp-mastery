#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <optional>
#include <string_view>

namespace Animal {
enum Animal { chicken, dog, cat, elephant, duck, snake, maxAnimals };

struct Data {
    std::string_view animalName{};
    int numOfLegs{};
    std::string_view sound{};
};
using namespace std::string_view_literals;
constexpr std::array animalName{
    "chicken"sv, "dog"sv, "cat"sv, "elephant"sv, "duck"sv, "snake"sv,
};

[[maybe_unused]] constexpr std::array<Data, Animal::maxAnimals> animals{{{"chicken", 2, "cluck"},
                                                                         {"dog", 4, "woof"},
                                                                         {"cat", 4, "meow"},
                                                                         {"elephant", 4, "pawoo"},
                                                                         {"duck", 2, "quack"},
                                                                         {"snake", 0, "hissss"}}};

}  // namespace Animal

const Animal::Data& getAnimal(std::size_t name) {
    return Animal::animals[name];
}

std::string enterAnimal() {
    std::cout << "Enter an animal: ";
    std::string x;
    std::cin >> x;
    return x;
}

std::optional<std::size_t> findAnimal(std::string_view userInput) {
    auto it = std::find(Animal::animalName.begin(), Animal::animalName.end(), userInput);
    if (it != Animal::animalName.end()) {
        auto index{std::distance(Animal::animalName.begin(), it)};
        return index;
    }
    return std::nullopt;
}

void displayAnimal(const Animal::Data& animal) {
    std::cout << "A " << animal.animalName << " has " << animal.numOfLegs << " legs and says "
              << animal.sound << ".\n";
}

void displayOtherAnimals(std::size_t value = Animal::animalName.size() + 99) {
    std::cout << "\nHere is the data for the rest of the animals:\n";
    for (std::size_t i{0}; i < Animal::animalName.size(); i++) {
        if (i != value) {
            displayAnimal(getAnimal(i));
        }
    }
}

int main() {
    auto result = findAnimal(enterAnimal());
    if (result.has_value()) {
        const auto animal{getAnimal(result.value())};
        displayAnimal(animal);
        displayOtherAnimals(result.value());
    } else {
        std::cout << "That animal couldn't be found.\n";
        displayOtherAnimals();
    }
    return 0;
}