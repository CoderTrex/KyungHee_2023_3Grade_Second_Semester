#include <iostream>
using namespace std;

int main() 
{
    int a; 
    int *p, **q, ***r; 

    p = &a;
    q = &p;
    r = &q;

    std::cout << "\nEnter a number: "; 
    cin >> a;
    cout << "Your number is " << a << endl;

    std::cout << "\nEnter a number: ";
    cin >> *p;
    cout << "Your number is " << a << endl;
    
    std::cout << "\nEnter a number: ";
    cin >> **q;
    cout << "Your number is " << a << endl;
    
    std::cout << "\nEnter a number: ";
    cin >> ***r;
    cout << "Your number is " << a << endl;
    
    return 0;
}
