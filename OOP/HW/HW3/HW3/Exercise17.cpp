#include <iostream>

class A {
private:
    int m_id;

public:
    A(int id) : m_id(id){ std:: cout <<  "클래스 A 생성자 실행" << std::endl; }
    ~A() { std::cout << "클래스 A 소멸자 실행" << std::endl; }
};


class B : public A {
public:
    B(int id) : A(id) { std::cout << "클래스 B 생성자 실행" << std::endl; }
    ~B() { std::cout << "클래스 B 소멸자 실행" << std::endl;}
};

int main() {
    std::cout << "## 클래스의 생성자와 소멸자 실행순서 ##" << std::endl;
    B b(10);

    // 클래스 A와 B의 생성자와 소멸자 수행순서를 기술하시오
    // 클래스 A 생성자 실행
    // 클래스 B 생성자 실행
    // 클래스 B 소멸자 실행
    // 클래스 A 소멸자 실행
}