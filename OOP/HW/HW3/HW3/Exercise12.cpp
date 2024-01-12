#include <iostream>

class Fraction {
private:
    int* m_pNum;
    int* m_pDenom;
public:
    Fraction(void);
    ~Fraction(void);
    void store(int nNumber, int nDenom);
    void print(void);
};

Fraction::Fraction(void) {
    m_pNum = new int;
    m_pDenom = new int;
}

Fraction::~Fraction(void) {
    delete m_pNum;
    delete m_pDenom;
}

void Fraction::store(int nNumber, int nDenom) {
    *m_pNum = nNumber;
    *m_pDenom = nDenom;
}

void Fraction::print(void) {
    std::cout << *m_pNum << "/" << *m_pDenom << std::endl;
}

int main() {
    // Fraction 객체를 가리키는 포인터 pFr 선언
    Fraction *pFr;
    // pFr을 통해 Fraction 객체 동적할당
    pFr = new Fraction;
    // 멤버 연산자를 통한 store() 호출 (매개변수로 2, 3을 차례대로 입력)
    pFr->store(2, 3);
    // 선택 연산자를 이용한 print() 함수 호출
    pFr->print();
return 0;
}
