#include <cassert>
#include <cstddef>
#include <iostream>

class IntArray {
   private:
    int* m_array{};
    int m_length{};

   public:
    IntArray(int length) : m_array(new int[static_cast<std::size_t>(length)]), m_length(length) {};
    ~IntArray() { delete[] m_array; }  // delete heap allocated array;
    void setValue(int index, int value) { m_array[static_cast<std::size_t>(index)] = value; }
    int getValue(int index) { return m_array[index]; }
    int getLength() { return m_length; }
};

int main() {
    IntArray arr(10);
    for (auto i{0}; i < arr.getLength(); ++i) {
        arr.setValue(i, i + 1);
    }

    std::cout << "the value of element 3 is: " << arr.getValue(3) << "\n";

    return 0;
}  // destructor called at this point