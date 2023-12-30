#include <iostream>
#include <iomanip> 
#include <math.h>

#define ROW 4

void printMatrix(int inMatrix[][4]){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < sizeof(inMatrix[0])/sizeof(int); j++){
            std::cout << std::setw(5) << inMatrix[i][j];
            if (j != 3){
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}


int main(){
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}
    };
    printMatrix(matrix);
    return 0;  
}
