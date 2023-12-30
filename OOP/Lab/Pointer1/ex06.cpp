#include <iostream>

int main() {
    int arr_ascend[10];
    int arr_descend[10];
    for (int i = 0; i < 10; i++){
        std::cin >> arr_ascend[i];
        arr_descend[i] = arr_ascend[i];
    }

    std::cout << "unsorted array: \n";
    std::cout << "ascend : descend\n";
    for (int i = 0 ; i < 10; i++){
        std::cout << arr_ascend[i] << " : " << arr_descend[i] << "\n";
    }
    
    for (int i = 0; i < 10; i++){
        for (int j = i; j < 10; j++){
            if (arr_ascend[i] > arr_ascend[j]){
                int temp = arr_ascend[i];
                arr_ascend[i] = arr_ascend[j];
                arr_ascend[j] = temp;
            }
            if (arr_descend[i] < arr_descend[j]){
                int temp = arr_descend[i];
                arr_descend[i] = arr_descend[j];
                arr_descend[j] = temp;
            }
        }
    }
    std::cout << "sorted array: \n";
    std::cout << "ascend : descend\n";
    for (int i = 0; i < 10; i++){
        std::cout << arr_ascend[i] << " : " << arr_descend[i] << "\n";
    }
    return 0;
}