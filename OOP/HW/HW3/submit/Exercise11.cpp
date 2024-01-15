#include <iostream>


class Fraction {
private:
    int m_numerator;
    int m_denominator;
    int nSubCount = 0;          // sub() 호출시 1씩 감소
    static int nAddCount;   // add() 호출시 1씩 증가

public:
    Fraction(void);
    Fraction(int nNumer);
    Fraction(int nNumer, int nDenom);
    Fraction(const Fraction& fr);

    void add(const Fraction& fr);
    void sub(const Fraction& fr);
    void store(int nNumber, int nDenom);
    void print(void);
    void print_Sub();

    static void printStatic_Add();
    static void printStatic_Sub();

    Fraction operator=(const Fraction& fr); 
    Fraction operator++(void); 
    Fraction operator++(int); 
    Fraction operator+=(const Fraction& fr); 
    Fraction operator+(const Fraction& fr);
    Fraction operator-(const Fraction& fr);
    Fraction operator*(const Fraction& fr);
    Fraction operator/(const Fraction& fr);
};
int Fraction::nAddCount = 0;

void Fraction::add(const Fraction& fr) {
    this->m_numerator = this->m_numerator * fr.m_denominator + fr.m_numerator * this->m_denominator;
    this->m_denominator = this->m_denominator * fr.m_denominator;
    nAddCount++;
}

void Fraction::sub(const Fraction& fr) {
    this->m_numerator = this->m_numerator * fr.m_denominator - fr.m_numerator * this->m_denominator;
    this->m_denominator = this->m_denominator * fr.m_denominator;
    nSubCount--;
}

void Fraction::print_Sub() {
    std::cout << "nSubCount: " << nSubCount << std::endl;
}

void Fraction::printStatic_Add() {
    std::cout << "nAddCount: " << nAddCount << std::endl;
}

void Fraction::printStatic_Sub() {
    std::cout << "아래 코드는 컴파일 오류를 발생시킨다. 이유는 아래에..." << std::endl;
    std::endl(std::cout);
    // std::cout << "nSubCount: " << nSubCount << std::endl;

}

int main() {
    Fraction fr1(1, 5);
    Fraction fr2(2, 5);
    fr1.add(fr2);
    fr2.sub(fr1);
    fr2.add(fr1);
    fr1.sub(fr2);

    std::cout << "객체 f1 nAddCount     : ";
    fr1.printStatic_Add();          // 호출- 객체 fr1을 이용한 정적 멤버 함수 호출
    std::cout << std::endl;

    std::cout << "이름 공간 nAddCount   : ";
    Fraction::printStatic_Add();    // 호출- 이름공간을 활용한 정적 멤버 함수 호출
    std::cout << std::endl;

    // std::cout << "객체 f2 nAddCount     : ";
    // fr2.printStatic_Add();          // 호출- 객체 fr2를 이용한 정적 멤버 함수 호출 
    // std::cout << std::endl;         // 출력값: 2


    // 특정 값이 안나오는 이유는 초기화를 안한 값을 연산했기 때문에 이상한 값이 나온다.
    std::cout << "객체 f2 nSubCount     : "; 
    fr2.print_Sub();                // 호출- fr2를 이용한 멤버 함수 호출
    std::cout << std::endl;
    
    // static 멤버 함수는 static 멤버 변수만 접근할 수 있다.
    fr2.printStatic_Sub(); // 호출- 컴파일 오류의 이유를 쓰시오 


    std::cout << "정리: static value인 nAddCount는 모든 객체들이 공유하는 변수이다." << std::endl;
    std::cout << "      static value인 nSubCount는 단순한 int 변수로 객체들이 공유하지 않는다." << std::endl;
    std::cout << "      때문에 nSubCount는 객체마다 고유한 값이므로 fr2가 호출된 횟수인 1번에 의해 초기화된 0보다 1 작은 값인 -1이 출력된다. " << std::endl;
    std::cout << "      또한 static 변수는 초기화를 따로 지정하지 않으면 0이된다. 하지만 일반변수는 지정하지 않으면 임의의 쓰레기 값이 들어가는 차이점도 있다." << std::endl;
    std::cout << "      fr2.print_Sub()의 에러는 static 맴버 함수인 print_Sub()함수가 static 맴버가 아닌 변수에 대해서 접근하기 때문에 에러가 난다." << std::endl;
    std::cout << "      static 맴버 함수는 static 맴버 변수만 접근할 수 있다." << std::endl;
    return 0;
}

Fraction Fraction::operator=(const Fraction& fr) {
    this->m_numerator = fr.m_numerator;
    this->m_denominator = fr.m_denominator;
    return *this;
}

// 전위 증가 연산자
Fraction Fraction::operator++(void) {
    this->m_numerator += this->m_denominator;
    return *this;
}
// 후위 증가 연산자 ->  int를 인자로 받는다
Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    this->m_numerator += this->m_denominator;
    return temp;
}

Fraction Fraction::operator+=(const Fraction& fr) {
    this->m_numerator = this->m_numerator * fr.m_denominator + fr.m_numerator * this->m_denominator;
    this->m_denominator = this->m_denominator * fr.m_denominator;
    return *this; // 포인터로 반환하는 이유는 객체 자체를 반환하기 위해서
}

Fraction Fraction::operator+(const Fraction& fr) {
    Fraction temp;
    temp.m_numerator    = this->m_numerator * fr.m_denominator + fr.m_numerator * this->m_denominator;
    temp.m_denominator  = this->m_denominator * fr.m_denominator;
    return temp;
}

Fraction Fraction::operator-(const Fraction& fr) {
    Fraction temp;
    temp.m_numerator    = this->m_numerator * fr.m_denominator - fr.m_numerator * this->m_denominator;
    temp.m_denominator  = this->m_denominator * fr.m_denominator;
    return temp;
}

Fraction Fraction::operator*(const Fraction& fr) {
    Fraction temp;

    temp.m_numerator    = this->m_numerator * fr.m_numerator;
    temp.m_denominator  = this->m_denominator * fr.m_denominator;
    return temp;
}

Fraction Fraction::operator/(const Fraction& fr) {
    Fraction temp;

    temp.m_numerator    = this->m_numerator * fr.m_denominator;
    temp.m_denominator  = this->m_denominator * fr.m_numerator;
    return temp;
}

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