#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;
public:
    inline void print() {
        std::cout << numerator << "/" << denominator << std::endl;
    }
    void store(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }
};


int main( ) {
    Fraction frac1;
    frac1.store(2, 3);
    frac1.print();
    return 0;
}