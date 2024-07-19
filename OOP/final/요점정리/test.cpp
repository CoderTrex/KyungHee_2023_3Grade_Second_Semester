#include <iostream>

class Engine {
public:
    Engine() {
        std::cout << "Engine 생성자 호출" << std::endl;
    }

    ~Engine() {
        std::cout << "Engine 소멸자 호출" << std::endl;
    }
};

class Car {
private:
    Engine carEngine;

public:
    Car() {
        std::cout << "Car 생성자 호출" << std::endl;
    }

    ~Car() {
        std::cout << "Car 소멸자 호출" << std::endl;
    }
};

int main() {
    {
        Car myCar; // Car 객체 생성
    } // Car 객체의 범위를 벗어나면 소멸자 호출

    return 0;
}

