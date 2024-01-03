// 10, 12, 18, 20, 24

#include <iostream>

int main(){
    int number[3];
    int small, large;
    bool undertw = false, t2n = true;

    std::cout << "Enter three integers: ";
    std::cin >> number[0] >> number[1] >> number[2];

    small = number[0];
    large = number[0];

    for (int i = 0; i < 3; i++){
        if (small > number[i])
            small = number[i];
        if (large < number[i])
            large = number[i];
        if (number[i] < 20)
            undertw = true;
        if (number[i] < 10 || number[i] > 90)
            t2n = false;
    }

    std::cout << "THhe smallest: " << small << "\n";
    std::cout << "THhe largest: " << large << "\n";
    std::cout << "Is there a number less than 20?: ";
    if (undertw)
        std::cout << "YES" << "\n";
    else    
        std::cout << "NO" << "\n";
    std::cout << "Are all numbers in range(10~90)?: ";
    if (t2n)
        std::cout << "YES" << "\n";
    else    
        std::cout << "NO" << "\n";
}