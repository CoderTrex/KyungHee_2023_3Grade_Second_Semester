#include <iostream>
#include <string>
#include <limits> 
#include <cstring> 

class SmartPhone {
private:
    char Os_name[20]; 
    int memory_size;

public:
    SmartPhone() {
        strcpy(this->Os_name, "");
        this->memory_size = 0;
    }

    SmartPhone(char Os_name[]) {
        strcpy(this->Os_name, Os_name);
        this->memory_size = 0;
    }

    SmartPhone(int memory_size) {
        strcpy(this->Os_name, "");
        this->memory_size = memory_size;
    }

    SmartPhone(char Os_name[], int memory_size) {
        strcpy(this->Os_name, Os_name);
        this->memory_size = memory_size;
    }

    void changeMemSize(int memory_size) {
        this->memory_size = memory_size;
    }

    void changeOSName(char Os_name[]) {
        strcpy(this->Os_name, Os_name);
    }

    void print() {
        std::cout << "Os_name: " << this->Os_name << std::endl;
        std::cout << "Memory_size: " << this->memory_size << "GBtye" << std::endl;
    }
};

void getPhone(char strName[], int& nMemSize);

int main () {
    std::cout << "This program creates SmartPhone" << std::endl;
    char strName[20] = {0};
    int nMemorySize = 0;

    // 입력받은 정보를 이용하는 생성자를 통해 TomPhone을 선언
    getPhone(strName, nMemorySize);
    SmartPhone TomPhone(strName, nMemorySize);
    TomPhone.print();
    /*             */
    
    // 기본생성자를 통해 MyPhone을 선언
    SmartPhone MyPhone;
    MyPhone.print();
    /*             */

    // 스마트폰의 OS 이름과 메모리의 크기를 사용자로부터 입력
    getPhone(strName, nMemorySize);
    MyPhone.changeOSName(strName);
    MyPhone.changeMemSize(nMemorySize);
    MyPhone.changeMemSize(nMemorySize);
    MyPhone.changeOSName(strName);
    MyPhone.print();
    std::cout << "\nThinks you for using Smart Phones.\n";
    /*             */
    return 0;
}

void getPhone(char strName[], int& nMemSize) {
    // 1. 입력받은 매개변수를 모두 0으로 초기화
    strcpy(strName, "");
    nMemSize = 0;

    // 2. 스마트폰의 OS 이름과 메모리의 크기를 입력받아 입력받은 매개변수에 저장
    std::cout << "Enter the OS name of the phone: ";
    std::cin >> strName;
    std::cout << "Enter the memory size of the phone: ";
    std::cin >> nMemSize;
}
