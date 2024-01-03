#include <iostream>
#include <math.h>


int main(){
    double a, b, c;
    std::cout << "Enter three constants: ";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    if (a == 0){
        std::cout << "There is only one real roots" << "\n";
        return 0;
    }

    double result = b*b - 4 * a * c;
    if (result < 0){
        std::cout << "There are no real roots." << "\n";
        return 0;
        
    }
    else if (result == 0){
        std::cout << "There is only one real roots." << "\n";
        return 0;
    }
    else if (result > 0){
        std::cout << "There are two real roots." << "\n";
        return 0;
    }
    else {
        std::cout << "WTF?" << "\n";
    }
}