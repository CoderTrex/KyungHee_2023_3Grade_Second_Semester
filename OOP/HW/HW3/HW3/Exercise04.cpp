#include <iostream>

class CFraction {
private:
    int m_numerator;
    int m_denominator;
public:
    CFraction(void);
    CFraction(int nNumer);
    CFraction(int nNumer, int nDenom);
    CFraction(const CFraction& fr);
    void store(int nNumber, int nDenom);
    void print(void);
};

CFraction::CFraction(void) {
    this->m_numerator = 0;
    this->m_denominator = 1;
}

CFraction::CFraction(int nNumer) {
    this->m_numerator = nNumer;
    this->m_denominator = 1;
}

CFraction::CFraction(int nNumer, int nDenom) {
    this->m_numerator = nNumer;
    this->m_denominator = nDenom;
}

CFraction::CFraction(const CFraction& fr) {
    this->m_numerator = fr.m_numerator;
    this->m_denominator = fr.m_denominator;
}

void CFraction::store(int nNumber, int nDenom) {
    this->m_numerator = nNumber;
    this->m_denominator = nDenom;
}

void CFraction::print(void) {
    std::cout << this->m_numerator << "/" << this->m_denominator << std::endl;
}

void getData(int& nNumer);
void getData(int& nNumer, int& nDenom);

int main() {
    std::cout << "This program creates a fraction." << std::endl;
    int nNumer = 0;
    int nDenom = 0;
    
    
    //기본생성자에 의한 fr1 선언
    /*             */
    CFraction fr1;
    std::cout << "fr1 contains: ";
    fr1.print();
    
    
    //분자만 매개변수로 입력받는 생성자에 의한 fr2 선언
    /*             */
    getData(nNumer);
    CFraction fr2(nNumer);
    std::cout << "fr2 contains: ";
    fr2.print();
    
    
    //분자, 분모 모두를 매개변수로 입력받는 생성자에 의한 fr3 선언
    /*             */
    getData(nNumer, nDenom);
    CFraction fr3(nNumer, nDenom);
    std::cout << "fr3 contains: ";
    fr3.print();
    
    
    
    //fr3을 매개변수로 입력받는 생성자에 의한 fr4 선언
    /*             */
    CFraction fr4(fr3);
    std::cout << "fr4 contains: ";
    fr4.print();
    return 0;
}

void getData(int& nNumer) {
//사용자로부터 분자값을 입력받는 코드 작성
    std::cout << "Enter the numerator of the fraction: ";
    std::cin >> nNumer;
}

void getData(int& pnNumer, int& pnDenom) {
//사용자로부터 분자, 분모값을 입력받는 코드 작성
    std::cout << "Enter the numerator and denominator of the fraction: ";
    std::cin >> pnNumer;
    std::cin >> pnDenom;
}