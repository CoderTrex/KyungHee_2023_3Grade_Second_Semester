#include <iostream>

class InitTest {
private:
    int nFirst;
    int nSecond;
public:
    InitTest(int nFirst, int nSecond);
    void print();
};

InitTest::InitTest(int nFirst, int nSecond) {
    this->nFirst = nFirst;
    this->nSecond = nSecond;
}

void InitTest::print() {
    std::cout << "nFirst: " << nFirst << std::endl;
    std::cout << "nSecond: " << nSecond << std::endl;
}
int main() {
    InitTest test(10, 20);
    test.print();
    return 0;
}