# include <iostream>


class Base {
public:
    int m_Num1;
    int m_Num2;
    virtual void setNum(int num1, int num2) = 0;
    virtual void printSum(void) = 0;
};

class Derived: public Base {
public:
    void setNum(int num1, int num2) override;
    void printSum(void) override;
};

void Derived::setNum(int num1, int num2) {
    m_Num1 = num1;
    m_Num2 = num2;
}

void Derived::printSum(void) {
    std::cout << "두 수의 합은 " << m_Num1 + m_Num2 << "입니다." << std::endl;
}

int main() {
    // ------------------------------------------------------- //
    // 이 라인을 삽입하여 Base 클래스의 객체를 생성하려고 시도할 때
    // 무슨 오류가 발생하는지 관찰하고, 이유를 생각해 봄.
    // 그런 후 이 라인을 제거하고 다시 수행해 봄
    
    // 답: 순수 가상 함수를 포함하는 클래스는 객체를 생성할 수 없음.
    // Base baseObj; 
    // ------------------------------------------------------- //
    
    Derived der; // 순수 가상 함수를 포함하는 파생함수에서 해당 순수 가상 함수를 오버라이딩해서 사용할 수 있음.
    int num1, num2;
    std::cout << "두 수를 입력하세요: " << std::endl;
    std::cin >> num1 >> num2;
    // 클래스 Derived의 객체를 통해 두 수를 설정하고, 합을 출력하는 코드 작성
    der.setNum(num1, num2);
    der.printSum();
    return 0;
}
