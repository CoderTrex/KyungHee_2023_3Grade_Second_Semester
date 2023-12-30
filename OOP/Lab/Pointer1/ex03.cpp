#include <iostream>
#include <iomanip> 
#include <math.h>

void diagonalMatrix(){
    int **DiagonalMatrix = new int*[6];
    for(int i = 0; i < 6; i++) 
        DiagonalMatrix[i] = new int[6];
    
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (5-i>j)
                DiagonalMatrix[i][j] = 1;
            else if (5-i==j)
                DiagonalMatrix[i][j] = 0;
            else
                DiagonalMatrix[i][j] = -1;
        }
    }
    std::cout << "Diagonal:\n";
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            std::cout << std::setw(5) << DiagonalMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    diagonalMatrix();
    return 0;  
}
