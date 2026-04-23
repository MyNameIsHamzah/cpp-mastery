#include <array>
#include <iostream>
#include <string_view>

namespace Animal {
enum Animal { dog, cat, elephant, duck, snake, maxAnimals };

struct Data {
    std::string_view animalName{};
    int numOfLegs{};
    std::string_view sound{};
};
using namespace std::string_view_literals;
constexpr std::array animalName{
    "dog"sv, "cat"sv, "elephant"sv, "duck"sv, "snake"sv,
};

[[maybe_unused]] constexpr std::array<Data, Animal::maxAnimals> animals{{{"dog", 4, "woof"},
                                                                         {"cat", 4, "meow"},
                                                                         {"elephant", 4, "pawoo"},
                                                                         {"duck", 2, "quack"},
                                                                         {"snake", 0, "hissss"}}};

}  // namespace Animal

constexpr std::string_view getName(Animal::Animal name) {
    return Animal::animalName[name];
}

void enterAnimal() {
    std::cout << "Enter an animal: ";
    std::string x;
    std::cin >> x;
}

int main() {
    return 0;
}