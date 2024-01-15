#include <iostream>


class Animal {
public:
    Animal(void);
    ~Animal(void);
    void talkStaticBinding(void);
    virtual void talkDynamicBinding(void);
};

Animal::Animal(void) {
    std::cout << "[Animal] Constructor is Called!" << std::endl;
}

Animal::~Animal(void) {
    std::cout << "[Animal] Desconstructor is Called!" << std::endl;
}

void Animal::talkStaticBinding(void) {
    std::cout << "[Animal] Crying!" << std::endl;
}

void Animal::talkDynamicBinding(void) {
    std::cout << "[Animal] Crying!" << std::endl;
}


class Dog: public Animal {
public:
    Dog(void);
    ~Dog(void);
    void talkStaticBinding(void);
    void talkDynamicBinding(void) override;
};

Dog::Dog(void) {
    std::cout << "[Dog] Constructor is Called!" << std::endl;
}

Dog::~Dog(void) {
    std::cout << "[Dog] Desconstructor is Called!" << std::endl;
}

void Dog::talkStaticBinding(void) {
    std::cout << "[Dog] Woof! Woof" << std::endl;
}

void Dog::talkDynamicBinding(void) {
    std::cout << "[Dog] Woof! Woof" << std::endl;
}


class Cat: public Animal {
public:
    Cat(void);
    ~Cat(void);
    void talkStaticBinding(void);
    void talkDynamicBinding(void) override;
};

Cat::Cat(void) {
    std::cout << "[Cat] Constructor is Called!" << std::endl;
}

Cat::~Cat(void) {
    std::cout << "[Cat] Desconstructor is Called!" << std::endl;
}

void Cat::talkStaticBinding(void) {
    std::cout << "[Cat] Meow! Meow" << std::endl;
}

void Cat::talkDynamicBinding(void) {
    std::cout << "[Cat] Meow! Meow" << std::endl;
}


int main() {
    Animal* animalPtr1;
    Animal* animalPtr2;

    // animalPtr1에 Dog 객체 할당 코드 삽입
    animalPtr1 = new Dog();
    // animalPtr2에 Cat 객체 할당 코드 삽입
    animalPtr2 = new Cat();

    // 동적할당과 정적할당은 다음과 같은 차이점을 보인다.
    // 정적할당은 컴파일 타임에 메모리를 할당하여 결정한다. 일반 함수나 일반 변수가 다음과 같은 방식으로 생성된다.
    // 동적할당은 런타임에 메모리를 할당한다. 가상함수나 변수의 동적할당에 의해 할당된다.
    
    // 정적할당:
    // 장점은 컴파일시 정보가 결정되기 때문에 속도가 빠르며, 에러를 초기에 발견할 수 있어서 안정적이다.
    // 단점은 컴파일 이후에 변경이 불가능하다.

    // 동적할당:
    // 장점은 동적할당은 자유롭게 할당할 수 있어 적응성이 높다. 또한 포인터에 상관없이 실제 클래스 형에 따라 재정의된 함수 호출이 가능하다.
    // 미리 메모리 공간을 할당하고 있어서 메모리 낭비가 발생될 수 잇다. 또한 상대적으로 느리다.

    // animalPtr1의 두 함수 (talkStaticBinding(), talkDynamicBinding()) 호출 코드 삽입
    animalPtr1->talkStaticBinding();    // 정적 바인딩으로 컴파일 타임에 결정되어서 Animal::talkStaticBinding()이 호출됨
    animalPtr1->talkDynamicBinding();   // 동적 바인딩으로 런타임에 결정되어서 Dog::talkDynamicBinding()이 호출됨 
    
    // animalPtr2의 두 함수 (talkStaticBinding(), talkDynamicBinding()) 호출 코드 삽입
    animalPtr2->talkStaticBinding();
    animalPtr2->talkDynamicBinding();

    // animalPtr1, 2의 Desconstructor is Called! 코드 삽입
    delete animalPtr1;
    delete animalPtr2;
    return 0;
}