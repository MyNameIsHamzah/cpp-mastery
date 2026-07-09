#include <iostream>
#include <memory>
#include <utility>

class Resource {
   public:
    Resource() { std::cout << "constructed\n"; }
    ~Resource() { std::cout << "destroyed\n"; }
};

int main() {
    // std::unique_ptr<Resource> res1{new Resource};
    // std::unique_ptr<Resource> res2{};
    auto res1{std::make_unique<Resource>()};
    std::unique_ptr<Resource> res2;

    std::cout << "res 1 is " << (res1 == nullptr ? "null" : "not null") << "\n";
    std::cout << "res 2 is " << (res2 == nullptr ? "null" : "not null") << "\n";

    std::cout << "Moving!\n";

    res2 = std::move(res1);

    std::cout << "res 1 is " << (res1 == nullptr ? "null" : "not null") << "\n";
    std::cout << "res 2 is " << (res2 == nullptr ? "null" : "not null") << "\n";

    return 0;
}