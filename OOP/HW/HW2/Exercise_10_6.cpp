#include <iostream>
using namespace std;

void swapDptr(int** x, int** y);

int main() {
    int x = 5, y = 7; 
    int* px = &x;
    int* py = &y;
    
    cout << "swapDptr() 호출 전: " << px << "  " << py << "  " << x << "  " << y << endl; 
    swapDptr(&px, &py); // 포인터 주소에 대한 주소값을 전달하기 때문에 받을 때는, int *의 주소 값인 int** 로 받아야한다.
    cout << "swapDptr() 호출 후: " << px << "  " << py << "  " << x << "  " << y << endl; 
    return 0;
}

void swapDptr(int** x, int** y) {
    int* tmp = *x;
    *x = *y;
    *y = tmp;
}
