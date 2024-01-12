# include <iostream>

class Polygons {
protected:
    int Area;
    int Perimeter;
public:
    Polygons(void) {Area = 0; Perimeter = 0;}
    Polygons(int nArea, int nPerimeter) {Area = nArea; Perimeter = nPerimeter;}
    ~Polygons(void);
    virtual void printArea(void) {std::cout << "도형의 넓이는 " << Area << " 입니다." <<  std::endl;}
    virtual void printPerimeter(void) {std::cout << "도형의 둘레는 " << Perimeter << " 입니다." << std::endl;}
};


Polygons::~Polygons(void) {

}

class Square: public Polygons {
private:
    int side;
public:
    Square(int side);
    ~Square(void);

    void printArea(void) {std::cout << "정사각형의 넓이는 " << Area << " 입니다." <<  std::endl;}
    void printPerimeter(void) {std::cout << "정사각형의 둘레는 " << Perimeter << " 입니다." << std::endl;}
};

Square::Square(int side) : Polygons(side * side, 4 * side) {
    this->side = side;
}

Square::~Square(void) {

}

class Rectangle: public Polygons {
private:
    int sideA;
    int sideB;
public:
    Rectangle(int sideA, int sideB);
    ~Rectangle(void);

    void printArea(void) {std::cout << "직사각형의 넓이는 " << Area << " 입니다." <<  std::endl;}
    void printPerimeter(void) {std::cout << "직사각형의 둘레는 " << Perimeter << " 입니다." << std::endl;}
};

Rectangle::Rectangle(int sideA, int sideB) : Polygons(sideA * sideB, 2 * (sideA + sideB)) {
    this->sideA = sideA;
    this->sideB = sideB;
}

Rectangle::~Rectangle(void) {

}

int main() {
    std::cout << "## 도형의 넓이와 둘레 구하기 ##" << std::endl;

    // 정사각형의 넓이 및 둘레 구하는 코드 삽입
    Square sqr(5);
    // 직사각형의 넓이 및 둘레 구하는 코드 삽입
    Rectangle rect(10, 20);

    // 정사각형의 넓이 및 둘레를 출력하는 코드 삽입
    std::cout << std::endl << "[정사각형]" << std::endl;
    sqr.printArea();
    sqr.printPerimeter();
    

    std::cout << std::endl << "[직사각형]" << std::endl;
    // 직사각형의 넓이 및 둘레를 출력하는 코드 삽입
    rect.printArea();
    rect.printPerimeter();

    // std::cout << "여기에 클래스 Polygons에서 area와 perimeter를 private 또는 public으로 선언하면 안되는 이유를 기술하시오." << std::endl;
    // std::cout << "답: area와 perimeter는 다른 클래스에서 상속받아 사용하는 변수이기 때문에 private으로 선언하면 다른 클래스에서 사용할 수 없다." << std::endl;
    // std::cout << "public으로 선언하면 다른 클래스에서 사용할 수 있지만, 이는 캡슐화의 원칙에 어긋난다." << std::endl;

    return 0;

}