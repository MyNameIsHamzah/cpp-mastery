#include <cstring>
#include <iostream>
#include <utility>
class stringBox {
   private:
    char* m_box;

   public:
    stringBox(const char* str) {
        if (str != nullptr) {
            m_box = new char[std::strlen(str) + 1];
            std::strcpy(m_box, str);
        } else {
            m_box = nullptr;
        }
    }
    ~stringBox() { delete[] m_box; }
    stringBox(const stringBox& other) = delete;
    stringBox& operator=(const stringBox& other) = delete;
    stringBox(stringBox&& other) noexcept : m_box{other.m_box} { other.m_box = nullptr; }
    stringBox& operator=(stringBox&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] m_box;
        m_box = other.m_box;
        other.m_box = nullptr;
        return *this;
    }
    void print() {
        if (m_box == nullptr) {
            std::cout << "nullptr\n";
            return;
        }
        std::cout << m_box << "\n";
    }
};

int main() {
    stringBox str("hello");
    stringBox str2("hamzah");
    std::cout << "str: ";
    str.print();
    std::cout << "str2: ";
    str2.print();

    // moving str and str 2 into vec
    std::cout << "moving strs into vector indexs\n";

    std::vector<stringBox> arr;
    arr.push_back(std::move(str));
    arr.push_back(std::move(str2));

    std::cout << "vec 0: ";
    arr[0].print();
    std::cout << "vec 1: ";
    arr[1].print();

    std::cout << "str: ";
    str.print();
    std::cout << "str2: ";
    str2.print();
    // arr.push_back(str2); wont work because copy constructor is deleted.

    return 0;
}