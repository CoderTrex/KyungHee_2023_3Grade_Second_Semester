#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int number;
    int randNum = rand()%34 + 3;

    std::cout << "Enter an integer number: ";
    std::cin >> number;

    std::cout << "Random Number: "  << randNum << "\n";
    std::cout << "Multiplication: " << randNum * number << "\n";
    std::cout << "Random number to the power of " << number 
            << ": " << pow(randNum, number) << "\n";
}