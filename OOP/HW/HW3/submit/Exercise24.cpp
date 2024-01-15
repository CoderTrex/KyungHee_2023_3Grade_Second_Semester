#include <iostream>



class Add {
private:
    double result;
public:
    Add(double a, double b);
    virtual void add_result(void);
};

Add::Add(double a, double b){
    result = a + b;
}

void Add::add_result(void){
    std::cout << "Add result is : " << result << std::endl;
}

class Sub {
private:
    double result;
public:
    Sub(double a, double b);
    virtual void sub_result(void);
};

Sub::Sub(double a, double b){
    result = a - b;
}

void Sub::sub_result(void){
    std::cout << "Subtract result is : " << result << std::endl;
}

// 다중 상속은 아래와 같은 방식으로 [접근제어지시자 + 기초 클래스 이름] 형식의 값이 계속해서 사용함으로 사용할 수 있다.
// 문제점
// 1. 상속 받는 여러 기초 클래스에 같은 이름의 맴버가 존재할 경우
// 2. 하나의 클래스를 간접적으로 두 번이상 상속 받을 가능성도 존재함.
// 3. 가상 클래스가 아닌 기초 클래스를 다중 상속하면, 기초 클래스 타입의 포인터로 파생 클래스를 가리킬 수 없다.
class Calculator : public Add, public Sub {
private:
    double result;
public:
    Calculator(double a, double b);
};

Calculator::Calculator(double a, double b) : Add(a, b), Sub(a, b){
    std::cout << "Calculator is perpared" << std::endl;
}

int main(){
    Calculator calc(12.34, 56.78);

    calc.add_result();
    calc.sub_result();
    return 0;
}
