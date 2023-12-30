#include <iostream>
#include <iomanip>

int main(){
    int number;
    std::cin >> number;

    std::cout << std::setw(20) <<  std::setfill(' ') << "Decimal"; 
    std::cout << std::setw(20) <<  std::setfill('-') << std::dec << number << "\n";

    std::cout << std::setw(20) <<  std::setfill(' ') << "Hexadecimal";
    std::cout << std::setw(20) <<  std::setfill('-') << std::hex << number << "\n";

    std::cout << std::setw(20) <<  std::setfill(' ') << "Octal"; 
    std::cout << std::setw(20) <<  std::setfill('-') << std::oct << number << "\n";
}