#include <iostream>
#include <string>

// ------------------------- // 
// --- case : use string --- //
// ------------------------- // 

// int firstDigit (int number){
//     int digit = number[0]  - '0';
//     return digit;
// }
// int secondDigit (int number){
//     int digit = number[1]  - '0';
//     return digit;
// }
// int thirdDigit (int number){
//     int digit = number[2]  - '0';
//     return digit;
// }
// int fourthDigit (int number){
//     int digit = number[3]  - '0';
//     return digit;
// }

// int addFourDigits(int snumber){
//     int num1 = firstDigit(snumber);
//     int num2 = secondDigit(snumber);
//     int num3 = thirdDigit(snumber);
//     int num4 = fourthDigit(snumber);

//     int result = num1 + num2 + num3 + num4;
//     std::cout << "sum : " << result << "\n";
// }

// int main(){
//     int number;
//     int result;
//     int snumber;
//     while (1){
//         std::cin >> number;
//         snumber = std::to_string(number);
//         if (number < 0){
//             std::cout << "You must enter a positive integer..\n";
//             continue;
//         }
//         else if (snumber.length() != 4){
//             std::cout << "You must enter a 4-digit number.\n";
//             continue;
//         }
//         else result = addFourDigits(snumber);
//     }
// }


// ------------------------ // 
// ---- case : use int ---- //
// ------------------------ // 

int firstDigit (int number){
    int digit = number/1000;
    return digit;
}
int secondDigit (int number){
    int digit = number/100;
    digit = digit % 10;
    return digit;
}
int thirdDigit (int number){
    int digit = number/10;
    digit = digit % 10;
    return digit;
}
int fourthDigit (int number){
    int digit = number;
    digit = digit % 10;
    return digit;
}


int addFourDigits(int num){
    int result = firstDigit(num) + secondDigit(num) 
                + thirdDigit(num) + fourthDigit(num);
    return result;
}

int main(){
    int number;
    int result;
    while (1){
        std::cin >> number;
        if (number < 0){
            std::cout << "You must enter a positive integer.\n";
            continue;
        }
        if (number / 10000 >= 1){
            std::cout << "You must enter a 4-digit number.\n";
            continue;
        }
        else result = addFourDigits(number);
        std::cout << "addFourtDigit: " <<  result << "\n";
    }
}

