#include <iostream>
#include <string>

template <typename T>
class Pair1 {
   private:
    T m_val1;
    T m_val2;

   public:
    Pair1(T val1, T val2) : m_val1{val1}, m_val2(val2) {}
    T first() const { return m_val1; }
    T second() const { return m_val2; }
};

template <typename T, typename Y>
class Pair {
   private:
    T m_val1;
    Y m_val2;

   public:
    Pair(const T& val1, const Y& val2) : m_val1{val1}, m_val2(val2) {}
    const T& first() const { return m_val1; }
    const Y& second() const { return m_val2; }
};

template <typename T>
class StringValuePair : public Pair<std::string, T> {
   public:
    StringValuePair(std::string val1, T val2) : Pair<std::string, T>(val1, val2) {}
};

int main() {
    StringValuePair<int> svp{"Hello", 5};
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}