#include <iostream>
#include <iomanip> 
#include <math.h>

void pointerPractice() {
    int a, b, c;
    int *p, *q, *r;
    int number;

    // Allocate memory for pointers
    p = new int;
    q = new int;
    r = new int;

    for (int i = 0; i < 3; i++) {
        std::cin >> number;
        if (i == 0) *p = number;
        if (i == 1) *q = number;
        if (i == 2) *r = number;
    }

    a = *p;
    b = *q;
    c = *r;

    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "value a: " << a << "\n";
        if (i == 1) std::cout << "value b: " << b << "\n";
        if (i == 2) std::cout << "value c: " << c << "\n";
    }
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "address a: " << &a << "\n";
        if (i == 1) std::cout << "address b: " << &b << "\n";
        if (i == 2) std::cout << "address c: " << &c << "\n";
    }
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "value p: " << *p << "\n";
        if (i == 1) std::cout << "value q: " << *q << "\n";
        if (i == 2) std::cout << "value r: " << *r << "\n";
    }
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "address p: " << p << "\n";
        if (i == 1) std::cout << "address q: " << q << "\n";
        if (i == 2) std::cout << "address r: " << r << "\n";
    }

    std::cout << "Swap:\n";

    *p = c;
    *q = a;
    *r = b; 
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "value a: " << a << "\n";
        if (i == 1) std::cout << "value b: " << b << "\n";
        if (i == 2) std::cout << "value c: " << c << "\n";
    }
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "address a: " << &a << "\n";
        if (i == 1) std::cout << "address b: " << &b << "\n";
        if (i == 2) std::cout << "address c: " << &c << "\n";
    }
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "value p: " << *p << "\n";
        if (i == 1) std::cout << "value q: " << *q << "\n";
        if (i == 2) std::cout << "value r: " << *r << "\n";
    }
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "address p: " << p << "\n";
        if (i == 1) std::cout << "address q: " << q << "\n";
        if (i == 2) std::cout << "address r: " << r << "\n";
    }
    delete p;
    delete q;
    delete r;
}

int main(){
    pointerPractice();
    return 0;  
}
