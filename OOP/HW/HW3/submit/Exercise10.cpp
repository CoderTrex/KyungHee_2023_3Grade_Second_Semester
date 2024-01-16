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


    // 전위와 후위 연산자 오버로딩에서는 매개변수로 둘을 구분한다.
    // 전위 증가 연산자는 매개변수를 받지 않는다.
    // 후위 증가 연산자는 매개변수를 받는다.
    // -> 이들의 차이를 구분하기 위한 매개변수 int는 단순히 둘을 구분하기 위해서 사용될 뿐, 특별한 역할은 하지 않는다.

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

    Fraction operator+(const Fraction& fr) {
        Fraction temp;
        temp.m_numerator    = this->m_numerator * fr.m_denominator + fr.m_numerator * this->m_denominator;
        temp.m_denominator  = this->m_denominator * fr.m_denominator;
        return temp;
    }

    Fraction operator-(const Fraction& fr) {
        Fraction temp;
        temp.m_numerator    = this->m_numerator * fr.m_denominator - fr.m_numerator * this->m_denominator;
        temp.m_denominator  = this->m_denominator * fr.m_denominator;
        return temp;
    }

    Fraction operator*(const Fraction& fr) {
        Fraction temp;

        temp.m_numerator    = this->m_numerator * fr.m_numerator;
        temp.m_denominator  = this->m_denominator * fr.m_denominator;
        return temp;
    }

    Fraction operator/(const Fraction& fr) {
        Fraction temp;

        temp.m_numerator    = this->m_numerator * fr.m_denominator;
        temp.m_denominator  = this->m_denominator * fr.m_numerator;
        return temp;
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
    Fraction fr2(7, 10);
    Fraction fr3;

    fr3 = fr2 + fr1;
    std::cout << "연산수행후 fr3의 값: ";
    fr3.print();
    
    fr3 = fr1 - fr2;
    std::cout << "연산수행후 fr3의 값: ";
    fr3.print();
    
    fr3 = fr1 * fr2;
    std::cout << "연산수행후 fr3의 값: ";
    fr3.print();
    
    fr3 = fr1 / fr2;
    std::cout << "연산수행후 fr3의 값: ";
    fr3.print();
    return 0;
}