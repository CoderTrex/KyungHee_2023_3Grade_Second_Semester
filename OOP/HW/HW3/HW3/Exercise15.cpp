# include <iostream>

class Polygons {
protected:
    int Area;
    int Perimeter;
public:
    Polygons(void) {Area = 0; Perimeter = 0;}
    Polygons(int nArea, int nPerimeter) {Area = nArea; Perimeter = nPerimeter;}
    ~Polygons(void);
    void printArea(void) {std::cout << "넓이: " << Area << std::endl;}
    void printPerimeter(void) {std::cout << "둘레: " << Perimeter << std::endl;}
};

class Square: public Polygons {
private:
    int side;
public:
    Square(void) {Area = 0; Perimeter = 0;}
    Square(int side) {Area = side * side; Perimeter = 4 * side;}
    ~Square(void);
    int calcArea(void) {return Area;}
    int calcPerimeter(void) {return Perimeter;}
};

class Rectangle: public Polygons {
private:
    int sideA;
    int sideB;
public:
    Rectangle(void) {Area = 0; Perimeter = 0;}
    Rectangle(int sideA, int sideB) {Area = sideA * sideB; Perimeter = 2 * (sideA + sideB);}
    ~Rectangle(void);
    int calcArea(void) {return Area;}
    int calcPerimeter(void) {return Perimeter;}
};

int main() {
    std::cout << "## 도형의 넓이와 둘레 구하기 ##" << std::endl;
    Square sqr(5);
    // 정사각형의 넓이 및 둘레 구하는 코드 삽입
    Rectangle rect(10, 20);
    // 직사각형의 넓이 및 둘레 구하는 코드 삽입
    std::cout << std::endl << "[정사각형]" << std::endl;
    // 정사각형의 넓이 및 둘레를 출력하는 코드 삽입
    std::cout << std::endl << "[직사각형]" << std::endl;
    // 직사각형의 넓이 및 둘레를 출력하는 코드 삽입
    std::cout << "여기에 클래스 Polygons에서 area와 perimeter private 또는 public으로 선언하면 안되는 이유를 기술하시오.";
    return 0;

}