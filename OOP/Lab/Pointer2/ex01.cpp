#include <iostream>
#include <iomanip>



int main() {
    int grade1, grade2, grade3;
    int *pgrade1, *pgrade2, *pgrade3;

    std::cin >> grade1 >> grade2 >> grade3;
    
    pgrade1 = &grade1;
    pgrade2 = &grade2;
    pgrade3 = &grade3;
    
    std::cout << "\n";
    std::cout << "Value :"  
                << std::setw(13) << " grade1 = " << std::setw(15) << grade1 
                << std::setw(13) << " *pgrade1 = " << std::setw(15) << *pgrade1
                << std::setw(13) << " *&pgrade1 = " << std::setw(15) << *&grade1;
    std::cout << "\n";
    std::cout << "Addr  :" 
                << std::setw(13) << " &grade1 = " << std::setw(15) << &grade1 
                << std::setw(13) << " pgrade1 = " << std::setw(15) << pgrade1
                << std::setw(13) << " &pgrade1 = " << std::setw(15) << &grade1;
    
    std::cout << "\n";
    std::cout << "Value :"  
                << std::setw(13) << " grade2 = " << std::setw(15) << grade2 
                << std::setw(13) << " *pgrade2 = " << std::setw(15) << *pgrade2
                << std::setw(13) << " *&pgrade2 = " << std::setw(15) << *&grade2;
    std::cout << "\n";
    std::cout << "Addr  :" 
                << std::setw(13) << " &grade2 = " << std::setw(15) << &grade2 
                << std::setw(13) << " pgrade2 = " << std::setw(15) << pgrade2
                << std::setw(13) << " &pgrade2 = " << std::setw(15) << &grade2;
    
    std::cout << "\n";
    std::cout << "Value :"  
                << std::setw(13) << " grade3 = " << std::setw(15) << grade3 
                << std::setw(13) << " *pgrade3 = " << std::setw(15) << *pgrade3
                << std::setw(13) << " *&pgrade3 = " << std::setw(15) << *&grade3;
    std::cout << "\n";
    std::cout << "Addr  :" 
                << std::setw(13) << " &grade3 = " << std::setw(15) << &grade3 
                << std::setw(13) << " pgrade3 = " << std::setw(15) << pgrade3
                << std::setw(13) << " &pgrade3 = " << std::setw(15) << &grade3;
}