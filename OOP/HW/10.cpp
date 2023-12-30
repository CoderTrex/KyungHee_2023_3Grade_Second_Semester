// 10, 12, 18, 20, 24

#include <iostream>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(NULL));
    int number1 = rand() % 10;
    int number2 = rand() % 10;


    if (number1 == number2){
        std::cout << number1 << " == " << number2 << "\n";
    }
    if (number1 > number2){
        std::cout << number1 << " > " << number2 << "\n";
    }
    if (number1 < number2){
        std::cout << number1 << " < " << number2 << "\n";
    }
}