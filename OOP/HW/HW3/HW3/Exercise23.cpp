#include <iostream>

class Base {
private:
    int m_Num1;
    int m_Num2;
public:
    Base(int num1, int num2);
    virtual void printSum();
};

Base::Base(int num1, int num2) {
    m_Num1 = num1;
    m_Num2 = num2;
}

void Base::printSum() {
    std::cout << "[Base Class]    " << this->m_Num1 << " + " << this->m_Num2 
                << " = " << this->m_Num1 + this->m_Num2 << std::endl;
}

class Derived :public Base {
private:
    int m_val3;
    int m_val4;
public:
    Derived(int num1, int num2, int val3, int val4);
    void printSum() override;
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
    
    std::cout << "[Upcasting Example]" << std::endl << std::endl;
    Base* basePtr = new Base(10, 20);
    Derived* derPtr = new Derived(10, 20, 30, 50);


    // 두 객체에 대해, 각각 printSum()을 호출하는 코드 작성
    // Derived 클래스의 객체 포인터를 Base 클래스 객체 포인터에 대입 코드 작성 (업케스팅)
    // 두 객체에 대해, 각각 printSum()을 호출하는 코드 작성
    basePtr->printSum();
    derPtr->printSum();
    basePtr = derPtr;
    std::cout << "After Upcasting / Derived -> Base.." << std::endl;
    basePtr->printSum();
    derPtr->printSum();
    std::endl(std::cout);


    std::cout << "[Downcasting Example1]" << std::endl << std::endl;
    Base* basePtr2 = new Derived(10, 20, 30, 50);
    Derived* derPtr2 = new Derived(10, 20, 30, 50);
    // 두 객체에 대해, 각각 printSum()을 호출하는 코드 작성
    // Base를 Derived에 대입하는 코드 작성 (다운케스팅)
    // 두 객체에 대해, 각각 printSum()을 호출하는 코드 작성
    
    basePtr2->printSum();
    derPtr2->printSum();
    derPtr2 = static_cast<Derived*>(basePtr2);
    std::cout << "After Downcasting / Base -> Derived.." << std::endl;
    basePtr2->printSum();
    derPtr2->printSum();
    std::endl(std::cout);
    
    
    std::cout << "[Downcasting Example2]" << std::endl << std::endl;
    Base* basePtr3 = new Base(10, 20);
    Derived* derPtr3 = new Derived(10, 20, 30, 50);
    // 두 객체에 대해, 각각 printSum()을 호출하는 코드 작성
    // Base를 Derived에 대입하는 코드 작성 (다운케스팅)
    // 두 객체에 대해, 각각 printSum()을 호출하는 코드 작성

    basePtr3->printSum();
    derPtr3->printSum();
    derPtr3 = static_cast<Derived*>(basePtr3);
    std::cout << "After Downcasting / Base -> Derived.." << std::endl;
    basePtr3->printSum();
    derPtr3->printSum();
    
    return 0;
}