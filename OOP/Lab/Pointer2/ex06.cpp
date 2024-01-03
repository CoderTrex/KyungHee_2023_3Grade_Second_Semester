#include <iostream>
using namespace std;

void swapDptr(int** x, int** y);


int main() {
    int x = 5, y = 7; 
    int* px = &x, int* py = &y;
    
    cout << "swapDptr() 호출 전: " << px << "  " << py << "  " << x << "  " << y << endl; //확인
    swapDptr(&px, &py); // 함수호출
    cout << "swapDptr() 호출 전: " << px << "  " << py << "  " << x << "  " << y << endl; //확인
    return 0;
}

void swapDptr(int** x, int** y) {
    int *tmp = *x;
    *x = *y;
    *y = tmp;
}   