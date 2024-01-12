#include <iostream>

class InitTest {
private:
    int nFirst;
    int nSecond;
public:
    InitTest(int nFirst, int nSecond);
    void print();
};

// 초기화 리스트는 선언과 동시에 초기화를 해주는 것이다.
InitTest::InitTest(int nFirst, int nSecond) : nFirst(nFirst), nSecond(nSecond) {}

class Test {
    int &score1;
    const int score2;
public:
    Test(int &s) : score1(s), score2(10) {
        // score = s; // compile error!
    }
};

void InitTest::print() {
    std::cout << "nFirst: " << nFirst << std::endl;
    std::cout << "nSecond: " << nSecond << std::endl;
}
int main() {
    InitTest test(10, 20);
    test.print();
    return 0;
}