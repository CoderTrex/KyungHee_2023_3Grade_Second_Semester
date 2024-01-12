#include <iostream>


class Animal {
public:
    Animal(void);
    ~Animal(void);
    void talkStaticBinding(void);
    virtual void talkDynamicBinding(void);
};

Animal::Animal(void) {
    std::cout << "[Animal] 생성자 호출" << std::endl;
}

Animal::~Animal(void) {
    std::cout << "[Animal] 소멸자 호출" << std::endl;
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
    std::cout << "[Dog] 생성자 호출" << std::endl;
}

Dog::~Dog(void) {
    std::cout << "[Dog] 소멸자 호출" << std::endl;
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
    std::cout << "[Cat] 생성자 호출" << std::endl;
}

Cat::~Cat(void) {
    std::cout << "[Cat] 소멸자 호출" << std::endl;
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

    // animalPtr1의 두 함수 (talkStaticBinding(), talkDynamicBinding()) 호출 코드 삽입
    animalPtr1->talkStaticBinding();
    animalPtr1->talkDynamicBinding();
    
    // animalPtr2의 두 함수 (talkStaticBinding(), talkDynamicBinding()) 호출 코드 삽입
    animalPtr2->talkStaticBinding();
    animalPtr2->talkDynamicBinding();
    return 0;
}