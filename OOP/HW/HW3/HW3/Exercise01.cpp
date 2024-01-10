#include <iostream>


class CFraction {
private:
    int m_numerator;
    int m_denominator;
public:
    CFraction(void);
};


CFraction::CFraction(void) {
    this->m_numerator = 0;
    this->m_denominator = 1;
}


int main() {
    CFraction fraction;
    std::cout << "The fraction object was created successfully " << std::endl;

}