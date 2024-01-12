#include <iostream>

class Rectangle {
private:
    int m_nWidth;
    int m_nHeight;
public:
    Rectangle(void);
    ~Rectangle(void);
    Rectangle(int nWidth, int nHeight);
    void store(int nWidth, int nHeight);
    void printArea();
};

Rectangle::Rectangle(void) {
    m_nWidth = 0;
    m_nHeight = 0;
}

Rectangle::~Rectangle(void) {
    std::cout << "소멸자 호출" << std::endl;
}

Rectangle::Rectangle(int nWidth, int nHeight) {
    m_nWidth = nWidth;
    m_nHeight = nHeight;
}

void Rectangle::store(int nWidth, int nHeight) {
    m_nWidth = nWidth;
    m_nHeight = nHeight;
}

void Rectangle::printArea() {
    std::cout << "넓이: " << m_nWidth * m_nHeight << std::endl;
}

int main() {
    // Rectangle의 객체 배열 arrRect[3]을 선언하고, 배열 초기화를 수행
    // -> (가로3, 세로5), (가로2, 세로2), 기본생성자 를 이용한 초기화
    Rectangle arrRect[3] = { Rectangle(3, 5), Rectangle(2, 2), Rectangle() };

    // store 함수를 이용하여 세 번째 객체에 가로 5, 세로 5 값을 저장
    arrRect[2].store(5, 5);
    // arrRect 배열의 각 객체에 대해 printArea() 함수 호출
    for (int i = 0; i < 3; i++){
        arrRect[i].printArea();
    }
    return 0;
}
