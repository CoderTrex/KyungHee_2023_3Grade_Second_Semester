#include <iostream>

int main() {
    int arr[10];
    int *arr_up = new int[10];
    int *arr_down = new int[10];

    for (int i = 0; i < 10; i++) {
        std::cin >> arr[i];
        arr_up[i] = arr[i];
        arr_down[i] = arr[i];
    }

    std::cout << "unsorted array: \n";
    std::cout << "ascend : descend\n";
    for (int i = 0; i < 10; i++) {
        std::cout << arr_up[i] << " " << arr_down[i] << "\n";
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (arr_up[i] > arr_up[j]) {
                int temp = arr_up[i];
                arr_up[i] = arr_up[j];
                arr_up[j] = temp;
            }
            if (arr_down[i] < arr_down[j]) {
                int temp = arr_down[i];
                arr_down[i] = arr_down[j];
                arr_down[j] = temp;
            }
        }
    }

    std::cout << "sorted array: \n";
    std::cout << "ascend : descend\n";
    for (int i = 0; i < 10; i++) {
        std::cout << arr_up[i] << " : " << arr_down[i] << "\n";
    }

    delete[] arr_up;
    delete[] arr_down;

    return 0;
}
