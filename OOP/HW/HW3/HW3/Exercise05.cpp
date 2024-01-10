#include <iostream>

class CFunny {
private:
    int m_nNum;
public:
    CFunny(void);
    CFunny(int nNum);
    ~CFunny(void);
    void Print() const;
};

CFunny::CFunny(void) {
    m_nNum = 0;
}

CFunny::CFunny(int nNum) {
        m_nNum = nNum;
}


CFunny::~CFunny(void){
    std::cout << "Destructor called" << std::endl; 
}

void CFunny::Print() const {
    // this->m_nNum = 1; // Error : m_nNum is const
    std::cout << this->m_nNum << std::endl;
}

// main.cpp
int main() {
    CFunny fn1(4);
    fn1.Print();
    CFunny fn2;
    // std::cin >> fn2.m_nNum; // Error : m_nNum is private
    fn2.Print();
    CFunny fn3(fn2);
    fn3.Print();
    return 0;
}