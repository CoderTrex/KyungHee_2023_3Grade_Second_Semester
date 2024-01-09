#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int     height;
    int**   practArr = NULL;
    cout << "Height?: ";
    cin >> height;
    practArr = new int*[height];
    for(int i=0;i<height;i++)
        practArr[i] = new int[i+1];
    for(int i=0;i<height;i++) {
        for(int j=0;j<=i;j++) {
            if(i==0 && j==0)
                *(*(practArr+i)+j) = 1;
            else if(j == 0)
                *(*(practArr+i)+j) = *(*(practArr+i-1)+j);
            else if(j==i)
                *(*(practArr+i)+j) = *(*(practArr+i-1)+j-1);
            else
                *(*(practArr+i)+j) = *(*(practArr+i-1)+j) + *(*(practArr+i-1)+j-1);
            cout << setw(5) << practArr[i][j];
        }
        cout << endl;
    }
    for(int i=0;i<height;i++)
        delete [] practArr[i];
    delete [] practArr;
    return 0;
}
