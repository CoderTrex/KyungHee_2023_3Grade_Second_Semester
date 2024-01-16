#include <iostream>

class base {
protected:
    int x;  // 변경: private에서 protected로 변경
public:
    base();
    virtual ~base();  // 변경: 가상 소멸자로 변경

    void initialize(int x);
    // 가상함수로 해야하는 이유: base class의 포인터를 통해 derived class의 객체를 가리킬 때, derived class의 printVal() 함수를 호출하기 위해
    virtual void printVal(void);  // 변경: 가상 함수로 변경

};

class derived1 : public base {
protected:
    int y;
public:
    derived1();
    virtual ~derived1();  // 변경: 가상 소멸자로 변경

    void initialize(int x, int y);
    virtual void printVal(void) override;  // 변경: 가상 함수로 재정의
};

class derived2 : public derived1 {
private:
    int z;
public:
    derived2();
    ~derived2();

    void initialize(int x, int y, int z);
    void printVal(void) override;  // 변경: 가상 함수로 재정의
};

// base class
base::base() {
    // std::cout << "base constructor" << std::endl;
}

base::~base() {
    // std::cout << "base destructor" << std::endl;
}

void base::initialize(int x) {
    this->x = x;
}

void base::printVal() {
    std::cout << "입력한 값은 " << this->x << "입니다." << std::endl;
}

// derived1 class
derived1::derived1() {
    // std::cout << "derived1 constructor" << std::endl;
}

derived1::~derived1() {
    // std::cout << "derived1 destructor" << std::endl;
}

void derived1::initialize(int x, int y) {
    base::initialize(x);
    this->y = y;
}

void derived1::printVal() {
    std::cout << "입력한 값은 " << this->x << ", " << this->y << "입니다." << std::endl;
}

// derived2 class
derived2::derived2() {
    // std::cout << "derived2 constructor" << std::endl;
}

derived2::~derived2() {
    // std::cout << "derived2 destructor" << std::endl;
}

// initialize 함수를 통해서 맴버 변수를 초기화 할 수 있다.
void derived2::initialize(int x, int y, int z) {
    derived1::initialize(x, y);
    this->z = z;
}

void derived2::printVal() {
    std::cout << "입력한 값은 " << this->x << ", " << this->y << ", " << this->z << "입니다." << std::endl;
}

int main() {
    derived2 der;
    der.initialize(10, 20, 30);
    der.printVal();
    return 0;
}
