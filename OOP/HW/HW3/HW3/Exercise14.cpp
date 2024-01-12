# include <iostream>

class Base {
private:
    int m_num1;
    int m_num2;
public:
    Base(void);
    Base(int nNum1, int nNum2);
    ~Base(void);

    void setNum(int val1, int val2) {m_num1 = val1; m_num2 = val2;}
    inline void printSum(void);
};


class Derived: public Base {

};

Base::Base(void) {
    m_num1 = 0;
    m_num2 = 0;
}

Base::Base(int nNum1, int nNum2) {
    m_num1 = nNum1;
    m_num2 = nNum2;
}

Base::~Base(void) {

}

inline void Base::printSum(void) {
    std::cout << "합: " << m_num1 + m_num2 << std::endl;
}

int main() {
    Derived der;
    int num1, num2;
    std::cout << "두 수를 입력하세요: "<< std::endl;
    std::cin >> num1 >> num2;
    //클래스 Derived의 객체를 통해 두 수를 설정하고
    der.setNum(num1, num2);
    //두 수의 합을 출력하는 코드를 입력
    der.printSum();
    return 0;
}
