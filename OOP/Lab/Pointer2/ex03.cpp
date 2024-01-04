#include <iostream>

void swapValue(int x, int y) {
    int tmp = x; 
    x = y;
    y = tmp;
}

void swapAddr(int *px, int *py) {
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

void swapRef(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int x = 5, y = 7;
    int *px = &x, *py = &y;

    swapValue(x, y);
    std::cout << "swapValue() 호출 후 : " << x << ", "  << y << std::endl;
    swapAddr(px, py);
    std::cout << "swapAddr()  호출 후 : " << x << ", "  << y << std::endl;
    swapRef(x, y);
    std::cout << "swapRef()   호출 후 : " << x << ", "  << y << std::endl;
    return 0;
}