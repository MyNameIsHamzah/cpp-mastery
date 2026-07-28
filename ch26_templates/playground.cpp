#include <iostream>
#include <string>
template <typename T>
class specialObject {
   private:
    T m_object;

   public:
    specialObject(T obj) : m_object{obj} {}
    const T& get() { return m_object; }
    void print() const { std::cout << m_object; }
};

template <>
class specialObject<bool> {
   private:
    bool m_object;

   public:
    specialObject(bool obj) : m_object{obj} {}
    bool get() { return m_object; }
    void print() const { std::cout << m_object; }
};

int main() {
    specialObject obj{5};
    obj.print();

    specialObject obj2{true};
    obj2.print();

    u_int8_t i{0b0000'0011};
    std::cout << static_cast<int>(i);
    return 0;
}