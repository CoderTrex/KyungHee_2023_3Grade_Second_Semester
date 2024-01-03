#include <iostream>
using namespace std;

int main() 
{
    int a; int* p, int** q, int*** r;
    p = &a;
    q = &p;
    r = &q;

    printf("Enter a number: ");
    cin >> a >> "\n";
    cout << "Your number is " << a << endl;


    printf("Enter a number: ");
    cin >> *p >> "\n";
    cout << "Your number is " << a << endl;
    
    
    printf("Enter a number: ");
    cin >> **q >> "\n";
    cout << "Your number is " << a << endl;
    
    
    printf("Enter a number: ");
    cin >> ***r >> "\n";
    cout << "Your number is " << a << endl;
    
    return 0;
}
