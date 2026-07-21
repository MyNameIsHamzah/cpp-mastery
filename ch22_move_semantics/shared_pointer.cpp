#include <iostream>
#include <memory>

class Resource {
   public:
    Resource() { std::cout << "Acquired\n"; }
    ~Resource() { std::cout << "Destroyed\n"; }
};

void sharedPointer() {
    Resource* res{new Resource};
    std::shared_ptr<Resource> ptr1{res};
    {
        std::shared_ptr<Resource> ptr2{ptr1};
        std::cout << "Killing shared pointer 2\n";
    }
    std::cout << "Killing shared pointer 1\n";
}

void makeShared() {
    auto ptr1{std::make_shared<Resource>()};
    {
        auto ptr2{ptr1};
        std::cout << "Killing shared pointer 2\n";
    }
    std::cout << "Killing shared pointer 1\n";
}

int main() {
    makeShared();
    return 0;
}