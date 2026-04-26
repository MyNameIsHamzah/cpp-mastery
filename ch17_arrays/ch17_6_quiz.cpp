#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <optional>
#include <string_view>

namespace Animal {
enum Type { chicken, dog, cat, elephant, duck, snake, maxAnimals };

struct Data {
    std::string_view animalName{};
    int numOfLegs{};
    std::string_view sound{};
};

[[maybe_unused]] constexpr std::array<Data, Animal::maxAnimals> animalCollection{
    {{"chicken", 2, "cluck"},
     {"dog", 4, "woof"},
     {"cat", 4, "meow"},
     {"elephant", 4, "pawoo"},
     {"duck", 2, "quack"},
     {"snake", 0, "hissss"}}};

}  // namespace Animal

const Animal::Data& getAnimal(Animal::Type type) {
    return Animal::animalCollection[type];
}

std::string enterAnimal() {
    std::cout << "Enter an animal: ";
    std::string x;
    std::cin >> x;
    return x;
}

std::optional<Animal::Type> findAnimal(std::string_view userInput) {
    for (std::size_t i{0}; i < Animal::animalCollection.size(); ++i) {
        if (userInput == Animal::animalCollection[i].animalName) {
            return static_cast<Animal::Type>(i);
        }
    }
    return std::nullopt;
}

void displayAnimal(const Animal::Data& animal) {
    std::cout << "A " << animal.animalName << " has " << animal.numOfLegs << " legs and says "
              << animal.sound << ".\n";
}

void displayOtherAnimals(Animal::Type x = Animal::Type::maxAnimals) {
    std::cout << "\nHere is the data for the rest of the animals:\n";
    for (std::size_t i{0}; i < Animal::maxAnimals; i++) {
        if (static_cast<Animal::Type>(i) != x) {
            displayAnimal(getAnimal(static_cast<Animal::Type>(i)));
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