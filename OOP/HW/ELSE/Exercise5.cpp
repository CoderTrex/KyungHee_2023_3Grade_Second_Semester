#include <iostream>
using namespace std;
#define PI 3.1415926536

int main() {
    const double pi = 3.1416926536;
    cout << "Defined constant PI: " << PI << "\n";
    cout << "Memory constant pi:  " << pi << "\n";
    cout << "Literal constant:    " << 3.1415926536 << "\n";

    const double euler = 2.71828;
    cout<< "Euler: " << euler << "\n";
    return 0;
}