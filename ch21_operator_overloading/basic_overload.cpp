#include <iostream>
#include <numeric>

class Cents {
   private:
    int m_cents{};

   public:
    Cents(int cents) : m_cents{cents} {}
    friend Cents operator+(const Cents& c1, const Cents& c2);
    int getCents() const { return m_cents; }
};

Cents operator+(const Cents& c1, const Cents& c2) {
    return c1.m_cents + c2.m_cents;
}

class Fraction {
   private:
    int m_numerator{};
    int m_denominator{};

   public:
    Fraction(int num, int den = 1) : m_numerator{num}, m_denominator(den) {};

    friend Fraction operator*(const Fraction& f1, const Fraction& f2) {
        return Fraction{f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator};
    }  // implicit conversion so don't need to create overloads for int variants

    void reduce() {
        auto divisor{std::gcd(m_numerator, m_denominator)};
        if (divisor) {
            m_numerator /= divisor;
            m_denominator /= divisor;
        }
    }

    void print() {
        reduce();
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }
};

int main() {
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{f1 * f2};
    f3.print();

    Fraction f4{f1 * 2};
    f4.print();

    Fraction f5{2 * f2};
    f5.print();

    Fraction f6{Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4}};
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}