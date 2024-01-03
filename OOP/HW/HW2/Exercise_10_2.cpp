#include <iostream>


int main() {
    int a, b = 3, c = 7;
    int *p = &b, *q, *r;

    // Step1 code
    q = &b;
    r = &b;

    std::cout << "CHECK step1\n";
    std::cout << "p: " << *p << " q: " << *q << " r: " << *r << "\n";

    // Step2 code
    a = 5;
    c = 6;
    p = &a;

    std::cout << "CHECK step2\n";
    std::cout << "p: " << *p << " q: " << *q << " r: " << *r << "\n";

    // Step3 code
    c = 15;
    r = &c;

    std::cout << "CHECK step3\n";
    std::cout << "p: " << *p << " q: " << *q << " r: " << *r << "\n";
}

