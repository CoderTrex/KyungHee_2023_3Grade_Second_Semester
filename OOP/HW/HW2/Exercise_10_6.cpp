#include <iostream>
using namespace std;

// 두 개의 이중 포인터를 받아서 가리키는 주소의 값을 서로 교환하는 함수
void swapDptr(int** x, int** y);

int main() {
    int x = 5, y = 7; // 정수 변수 x와 y를 초기화
    int* px = &x;     // 포인터 px를 x의 주소로 초기화
    int* py = &y;     // 포인터 py를 y의 주소로 초기화
    
    // swapDptr() 호출 전의 상태 출력
    cout << "swapDptr() 호출 전: " << px << "  " << py << "  " << x << "  " << y << endl; 
    // swapDptr() 함수 호출, 포인터의 주소값을 전달하므로 int**로 받아야 함
    swapDptr(&px, &py);
    // swapDptr() 호출 후의 상태 출력
    cout << "swapDptr() 호출 후: " << px << "  " << py << "  " << x << "  " << y << endl; 
    return 0;
}

// 이중 포인터를 이용하여 주소값을 교환하는 함수
void swapDptr(int** x, int** y) {
    int* tmp = *x; // x가 가리키는 주소의 값을 tmp에 저장
    *x = *y;       // x가 가리키는 주소에 y가 가리키는 주소의 값을 대입
    *y = tmp;      // y가 가리키는 주소에 tmp의 값을 대입 (즉, x와 y의 값이 서로 교환됨)
}
