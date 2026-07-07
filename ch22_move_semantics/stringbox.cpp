#include <cstring>
#include <iostream>
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
            std::cout << "nullptr";
            return;
        }
        std::cout << m_box << "\n";
    }
};

int main() {
    stringBox str("hello");
    stringBox str2("hamzah");
    str.print();
    str2.print();

    str = std::move(str2);
    str.print();
    str2.print();

    return 0;
}