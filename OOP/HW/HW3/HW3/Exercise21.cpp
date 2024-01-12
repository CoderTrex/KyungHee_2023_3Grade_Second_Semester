#include <iostream>
#include <cmath>


class Polygon {
protected:
    double area;
    double  perimeter;
public:
    virtual void printArea() = 0;
    virtual void printPerimeter() = 0;
};

class Triangle: public Polygon {
private:
    double width;
    double height;
public:
    Triangle(double width, double height);
    void printArea() override;
    void printPerimeter() override;
    void calcArea();
    void calcPerimeter();
};

class Rectangle: public Polygon {
private:
    double sideA;
    double sideB;
public:
    Rectangle(double sideA, double sideB);
    void printArea() override;
    void printPerimeter() override;
    void calcArea();
    void calcPerimeter();
};

// 직사각형 클래스 정의
Triangle::Triangle(double width, double height) {
    this->width = width;
    this->height = height;
}

void Triangle::printArea() {
    std::cout << "삼각형의 넓이는 " << area << "입니다." << std::endl;
}

void Triangle::printPerimeter() {
    std::cout << "삼각형의 둘레는 " << perimeter << "입니다." << std::endl;
}

void Triangle::calcArea() {
    area = this->width * this->height / 2;
}

void Triangle::calcPerimeter() {
    perimeter  = this->width + this->height + sqrt(pow(this->width, 2) + pow(this->height, 2));
}


// 직사각형 클래스 정의
Rectangle::Rectangle(double sideA, double sideB) {
    this->sideA = sideA;
    this->sideB = sideB;
}

void Rectangle::printArea() {
    std::cout << "직사각형의 넓이는 " << area << "입니다." << std::endl;
}

void Rectangle::printPerimeter() {
    std::cout << "직사각형의 둘레는 " << perimeter << "입니다." << std::endl;
}

void Rectangle::calcArea() {
    area = this->sideA * this->sideB;
}

void Rectangle::calcPerimeter() {
    perimeter = 2 * (this->sideA + this->sideB);
}

int main() {
    std::cout << "## 도형의 넓이와 둘레 구하기 ##" << std::endl;
    
    // 직각삼각형의 넓이 및 둘레 구하는 코드 삽입
    Triangle tri(5, 12);
    tri.calcArea();
    tri.calcPerimeter();

    // 직사각형의 넓이 및 둘레 구하는 코드 삽입
    std::cout << std::endl << "[직각삼각형]" << std::endl;
    tri.printArea();
    tri.printPerimeter();


    // 직각삼각형의 넓이 및 둘레를 출력하는 코드 삽입
    std::cout << std::endl << "[직사각형]" << std::endl;
    Rectangle rect(10, 20);
    rect.calcArea();
    rect.calcPerimeter();

    rect.printArea();
    rect.printPerimeter();
    
    // 직사각형의 넓이 및 둘레를 출력하는 코드 삽입
    return 0;
}
