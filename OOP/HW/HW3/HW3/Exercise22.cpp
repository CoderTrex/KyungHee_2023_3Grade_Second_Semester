#include <iostream>

class Base {
private:
    int m_Num1;
    int m_Num2;
public:
    Base(int num1, int num2);
    void printSum();
};

Base::Base(int num1, int num2) {
    m_Num1 = num1;
    m_Num2 = num2;
}

void Base::printSum() {
    std::cout << "[Base Class] " << this->m_Num1 << " + " << this->m_Num2 
                << " = " << this->m_Num1 + this->m_Num2 << std::endl;
}

class Derived :public Base {
private:
    int m_val3;
    int m_val4;
public:
    Derived(int num1, int num2, int val3, int val4);
    void printSum();
};

Derived::Derived(int num1, int num2, int val3, int val4) : Base(num1, num2) {
    m_val3 = val3;
    m_val4 = val4;
}

void Derived::printSum() {
    std::cout << "[Derived Class] " << this->m_val3 << " + " << this->m_val4 
                << " = " << this->m_val3 + this->m_val4 << std::endl;
}

int main() {
    Base baseObj(10, 20);
    Derived derObj(30, 50, 70, 90);
    baseObj.printSum();
    derObj.printSum();
    
    //Derived 클래스의 객체를 Base 클래스의 객체에 대입하는 코드 작성 (업케스팅)
    // derObj = baseObj;  -> 업스케일링은 불가능
    /* 해당 라인에서 어떤 오류가 발생하는지 관찰하고 생각해봄 완료하면 지우고 다시 수행 */
    
    baseObj = derObj;  // 다운스케일링은 가능
    std::cout << std::endl << "After assign derived object to base object.." << std::endl << std::endl;
    baseObj.printSum();
    derObj.printSum();
    return 0;
}