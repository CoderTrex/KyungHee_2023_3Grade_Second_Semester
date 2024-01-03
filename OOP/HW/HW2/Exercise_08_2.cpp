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

void sumMatrix(int AMatrix[][4], int BMatrix[][4]){
    int SumMatrix[4][4];

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < sizeof(SumMatrix[0])/sizeof(int); j++){
            SumMatrix[i][j] = AMatrix[i][j] + BMatrix[i][j];
        }
    }
    std::cout << "SUM:\n";
    printMatrix(SumMatrix);
}


void multiMatrix(int AMatrix[][4], int BMatrix[][4]){
    int MultiMatrix[4][4];

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < sizeof(MultiMatrix[0])/sizeof(int); j++){
            MultiMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < sizeof(MultiMatrix[0])/sizeof(int); j++){
            for (int k = 0; k < ROW; k++){
                MultiMatrix[i][j] += AMatrix[i][k] * BMatrix[k][j];
            } 
        }
    }
    std::cout << "Multi:\n";
    printMatrix(MultiMatrix);
}

int main(){
    int matrixA[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}
    };
    int matrixB[4][4] = {
        {9, 0, 1, 2},
        {5, 6, 7, 8},
        {3, 4, 5, 6},
        {1, 2, 3, 4}
    };
    sumMatrix(matrixA, matrixB);
    multiMatrix(matrixA, matrixB);
    return 0;  
}
