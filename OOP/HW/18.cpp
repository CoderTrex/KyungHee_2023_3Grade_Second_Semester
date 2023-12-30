#include <iostream>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(NULL));
    int randNumber[3];
    bool flag;
    for (int i = 0; i < 3; i++){
        randNumber[i] = rand()%99 + 1;
    }

    for (int i = 0; i < 3; i++){
        flag = true;
        if (randNumber[i] % 2 == 0){
            std::cout << randNumber[i]  << " is not a prime number" << "\n";
            continue;
        }
        for (int j = 3; j < randNumber[i]/2; j += 2){
            if (randNumber[i] % j == 0){
                flag = false;
                break;
            }   
        }
        if (flag){
            std::cout << randNumber[i] << " is a prime number." << "\n"; 
        }
        else {
            std::cout << randNumber[i] << " is not a prime number." << "\n"; 
        }
    }
}