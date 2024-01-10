#include <iostream>

class CFraction {
private:
    int m_numerator;
    int m_denominator;
public:
    CFraction(void);
    void store(int nNumber, int nDenom);
    void print(void);
};

CFraction::CFraction(void) {
    this->m_numerator = 0;
    this->m_denominator = 1;
}

void CFraction::store(int nNumber, int nDenom) {
    this->m_numerator = nNumber;
    this->m_denominator = nDenom;
}

void CFraction::print(void) {
    std::cout << this->m_numerator << "/" << this->m_denominator << std::endl;
}

void getData(int*pnNumer, int* pnDenom);
int main() {
    std::cout << "This program creates a fraction.\n\n";
    int nNumer = 0;
    int nDenom = 0;
    getData(&nNumer, &nDenom);
    //Fraction 타입의 객체 선언
    //위의 getData()를 통해 입력받은 분자, 분모 데이터를 클래스 멤버 함수를 통해 객체에 저장
    CFraction fraction;
    fraction.store(nNumer, nDenom);

    std::cout << "\n Your fraction contains: ";
    //분수 클래스의 함수를 통해 화면 출력
    fraction.print();
    return 0;
}
void getData(int* pnNumer, int* pnDenom) {
//사용자로부터 분자, 분모값을 입력받는 코드 작성
    std::cout << "Enter the numerator and denominator of the fraction: ";
    std::cin >> *pnNumer;
    std::cin >> *pnDenom;
}