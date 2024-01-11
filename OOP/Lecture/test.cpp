#include <stdio.h>

class Base {
    public:
        void print() {
            printf("Base\n");
        }
};

class Derived : public Base {
    public:
        void print() {
            printf("Derived\n");
        }
};


int main() {
    Base b;
    Derived d;

    // b.print();
    d.Base::print();
    d.print();
    return 0;
}
