#include <iostream>

// 반복문 구조
int factlter(int x){
    int result = 1;
    for (int i = 1; i <= x; i++){
        result *= i;
    }
    return result;
}

// 재귀문 구조
int factRecur(int x){
    if (x > 0){
        return x * factRecur(x - 1);
    }
    else {
        return 1;
    }
}

int main() {
    int number;
    int lter, recur;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    lter = factlter(number);
    recur = factRecur(number);
    std::cout << "factlter:  " << lter << "\n";
    std::cout << "factRecur: " << recur << "\n";

    if (lter == recur){
        std::cout << "Result are the same." << "\n";
    }
    else{
        std::cout << "Result aren't the same." << "\n";
    }
}