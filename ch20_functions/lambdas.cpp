#include <algorithm>
#include <array>
#include <iostream>

template <typename T>

bool isGreaterThanTwo(T n) {
    return n > 2;
}

template <typename T, std::size_t N>

void findIfUsingFunction(std::array<T, N>& arr) {
    auto found{std::find_if(arr.begin(), arr.end(), isGreaterThanTwo<T>)};

    if (found == arr.end()) {
        std::cout << "Could not find number greater than 2\n";

    } else {
        std::cout << "first value found that meets the predicate: " << *found;
    }
}

template <typename T, std::size_t N>

void findIfUsingLambda(std::array<T, N>& arr) {
    auto found{std::find_if(arr.begin(), arr.end(), [](T n) { return n > 2; })};

    if (found == arr.end()) {
        std::cout << "Could not find number greater than 2\n";

    } else {
        std::cout << "first value found that meets the predicate: " << *found << "\n";
    }
}

struct Student {
    std::string_view name;

    int points;
};

void question1() {
    std::array<Student, 8> arr{{{"Albert", 3},

                                {"Ben", 5},

                                {"Christine", 2},

                                {"Dan", 8},  // Dan has the most points (8).

                                {"Enchilada", 4},

                                {"Francis", 1},

                                {"Greg", 3},

                                {"Hagrid", 5}}};

    const auto highest_points{

        std::max_element(arr.begin(), arr.end(),

                         [](const Student& a, const Student& b) { return a.points < b.points; })};

    std::cout << highest_points->name << " is the best student\n";
}

struct Season {
    std::string_view name{};

    double averageTemperature{};
};

void question2() {
    std::array<Season, 4> seasons{

        {{"Spring", 285.0}, {"Summer", 296.0}, {"Fall", 288.0}, {"Winter", 263.0}}};

    std::sort(seasons.begin(), seasons.end(), [](const Season& a, const Season& b) {
        return a.averageTemperature < b.averageTemperature;
    });

    for (const auto& season : seasons) {
        std::cout << season.name << '\n';
    }
}

int main() {
    const std::size_t length{5};

    std::array<int, length> arr{1, 2, 3, 4, 5};

    findIfUsingLambda(arr);

    question1();

    question2();

    return 0;
}