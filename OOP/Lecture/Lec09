#include <iostream>
using namespace std;

int main(){
    // int a[5] = {2, 4, 6, 8, 22};
    // int *p;

    // p = &a[1];
    // std::cout << a[0] << " " << p[-1];
    

    int a[20];
    int * p = &(a[5]);
    for(int i=0;i<20;i++)
        a[i] = i;

    cout << p+5 << endl; //address of a[10]
    cout << *(p+5) << endl; //10
    cout << *(p++) << endl; //5
    cout << *(--p) << endl; //5
    int * q = &(a[10]);
    cout << *(p + (q-p)/2) << endl; //
    return 0;
}

// 9page 2는 오타 -임
// 11page 괄호를 꼭 쳐줘야함. * 연산자의 순서 때문에

지시연산2번           지시연산1번
dim2[i][j]; => 치환 *(p + i*4 + j);
                ex) *(p + 9)


new와 delete는 항상 같이 쓰자.

int *p = new int;
int *q = p;

p --------->[]
            |
q -----------

이후에 p를 지우면
q는에러가남 -> 댕글링 포인터가 생성이 됨.


메모리를 할당한 이후에 free를 통해 메모리를 해제한 곳에 대한 메모리 영역을 포인터가 지시하면 에러.
이를 댕글링 포인터라고 부른다.

-> 알고리즘 딴에서 에러를 조심해야햐함.


33page 개별 딴의 배열은 중구난방(위치=크기)으로 배열이 생성이 된다.


ERROR: 2차원 배열 큰 배열부터 배열을 하면 그 안의 1차원 배열은 떠도는 상태가 된다.

2차원 배열 해제하는 방법:
for (배열전체)
    delete[] 배열[i];
delete 배열


// 뒤에는 무조건 상수

void doIt(int ary[][20]);
void doThat(int **ary); //wrong -> ary[][] 이랑 같은 뜻임

int main()
{
    int a[10][20];
    int (*p)[20] = a;
    doIt(a);
    doIt(p);
    doIt(&(a[0]));

    // doThat(a); //wrong
    // doThat(p); //wrong
    // doThat(&(a[0])); //wrong
}

void doIt(int ary[][20]){
    return ;
}
void doThat(int **ary){
    return ;
} //wrong -> ary[][] 이랑 같은 뜻임