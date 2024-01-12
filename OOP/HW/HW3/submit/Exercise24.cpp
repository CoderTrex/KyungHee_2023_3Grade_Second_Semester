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
