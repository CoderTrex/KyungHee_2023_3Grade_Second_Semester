#include <iostream>


class Fraction {
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(void);
    Fraction(int nNumer);
    Fraction(int nNumer, int nDenom);
    Fraction(const Fraction& fr);
    void store(int nNumber, int nDenom);
    void print(void);

    Fraction operator=(const Fraction& fr) {
        this->m_numerator = fr.m_numerator;
        this->m_denominator = fr.m_denominator;
        return *this;
    }
    // 전위 증가 연산자
    Fraction operator++(void) {
        this->m_numerator += this->m_denominator;
        return *this;
    }
    // 후위 증가 연산자 ->  int를 인자로 받는다
    Fraction operator++(int) {
        Fraction temp = *this;
        this->m_numerator += this->m_denominator;
        return temp;
    }
    Fraction operator+=(const Fraction& fr) {
        this->m_numerator = this->m_numerator * fr.m_denominator + fr.m_numerator * this->m_denominator;
        this->m_denominator = this->m_denominator * fr.m_denominator;
        return *this; // 포인터로 반환하는 이유는 객체 자체를 반환하기 위해서
    }
};

Fraction::Fraction(void) {
    this->m_numerator = 0;
    this->m_denominator = 1;
}

Fraction::Fraction(int nNumer) {
    this->m_numerator = nNumer;
    this->m_denominator = 1;
}

Fraction::Fraction(int nNumer, int nDenom) {
    this->m_numerator = nNumer;
    this->m_denominator = nDenom;
}

Fraction::Fraction(const Fraction& fr) {
    this->m_numerator = fr.m_numerator;
    this->m_denominator = fr.m_denominator;
}

void Fraction::store(int nNumber, int nDenom) {
    this->m_numerator = nNumber;
    this->m_denominator = nDenom;
}

void Fraction::print(void) {
    std::cout << this->m_numerator << "/" << this->m_denominator << std::endl;
}


int main() {
    Fraction fr1(3, 5);
    Fraction fr2;
    
    fr2 = fr1;
    std::cout << "After fr2 = fr1" << std::endl;
    fr2.print();
    

    fr2 += fr1;
    std::cout << "After f2 += f1" << std::endl;
    fr2.print();

    fr2++;
    std::cout << "After f2++" << std::endl;
    fr2.print();

    ++fr2;
    std::cout << "After ++f2" << std::endl;
    fr2.print();

    return 0;
}