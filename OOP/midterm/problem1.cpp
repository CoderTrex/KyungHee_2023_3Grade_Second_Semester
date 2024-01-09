#include <iostream>
#include <ctime>
using namespace std;

int searchArray(int arr[], int key, int*& result, int arrSize);

int main() {
    int*    dArr = NULL;
    int     length;
    int     key;
    int     numSearch;
    int*    resArr = NULL;

    srand((unsigned int)time(NULL));
    cout << "Enter the size of Array: ";
    cin >> length;
    dArr = new int[length];
    for(int i=0;i<length;i++) {
        dArr[i] = rand()%20 + 1;
        cout << dArr[i] << " ";
    }
    cout << endl;
    cout << "Enter the key value: ";
    cin >> key;
    numSearch = searchArray(dArr, key, resArr, length);
    cout << "Resutls of search: ";
    for(int i=0;i<numSearch;i++)
        cout << resArr[i] << " ";
    cout << endl;
    cout << "# of search results: " << numSearch << endl;
    delete [] dArr;
    delete [] resArr;
    return 0;
}

int searchArray(int arr[], int key, int*& result, int arrSize) {
    int numSearch = 0;
    int cnt=0;
    for(int i=0; i<arrSize;i++)
        if(arr[i] == key)
            numSearch++;
    result = new int[numSearch];
    for(int i=0;i<arrSize;i++)
        if(arr[i] == key){
            result[cnt] = i;
            cnt++;
        }
    return numSearch;
}