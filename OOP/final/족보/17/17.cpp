// #include <iostream>
// #include <string>

// enum Rank{SAWON, DAERI, GAWJANG, CHAJANG, BUJANG};

// class Employee {
// public:
//     int         age;
//     int         p_rank;
//     std::string name;
//     std::string position; 
//     static int  employee_count;
    


//     Employee() : age(30), p_rank(0), name("Anonymous"), position("SAWON") {
//         employee_count++;
//     };
//     Employee(std::string name, int age, Rank positon) {
//         employee_count++;
//     }
//     Employee(const Employee &cp) : age(cp.age), p_rank(cp.p_rank), name(cp.name), position(cp.position) {
//         employee_count++;
//     };
//     void printInfo();
//     int calculatePay() {int payment = p_rank * 100 + 500; return payment;};
//     void changeRank(Rank rank) {
//         if (rank == 0)
//             position = "Sawon"; p_rank = 0;
//         if (rank == 1)
//             position = "Daeri"; p_rank = 1;
//         if (rank == 2)
//             position = "Gawjang"; p_rank = 2;
//         if (rank == 3)
//             position = "Chajang"; p_rank = 3;
//         if (rank == 4)
//             position = "Bujang"; p_rank = 4;
//     };
//     void changeName(std::string name) {this->name = name;};
// };

// void Employee::printInfo() {
//     std::cout << name << " " << "age: " << age << " rank: " << position << " Payment: " << calculatePay() << "\n";
// }

// int main () {
//         Employee haha;
//         Employee MSPark("Myeongsoo Park", 45, CHAJANG);
//         Employee HDJeong(MSPark);
//         HDJeong.changeRank(DAERI);
//         HDJeong.changeName("Hyeongdon Jeong");
//         haha.printInfo();
//         MSPark.printInfo();
//         HDJeong.printInfo();
//         return 0;
// }

#include <iostream>
#include <string>

enum Rank { SAWON, DAERI, GAWJANG, CHAJANG, BUJANG };

class Employee {
public:
    int age;
    int p_rank;
    std::string name;
    std::string position;
    static int employee_count;

    Employee() : age(30), p_rank(0), name("Anonymous"), position("SAWON") {
        employee_count++;
    };
    Employee(std::string name, int age, Rank positon) : age(age), p_rank(static_cast<int>(positon)), name(name) {
        employee_count++;
         if (p_rank == 0)
            position = "Sawon";
        else if (p_rank == 1)
            position = "Daeri";
        else if (p_rank == 2)
            position = "Gawjang";
        else if (p_rank == 3)
            position = "Chajang";
        else if (p_rank == 4)
            position = "Bujang";
    
    }
    Employee(const Employee &cp) : age(cp.age), p_rank(cp.p_rank), name(cp.name), position(cp.position) {
        employee_count++;
    };

    void printInfo();
    int calculatePay() { int payment = p_rank * 100 + 500; return payment; };
    void changeRank(Rank rank) {
        if (rank == 0)
            position = "Sawon", p_rank = 0;
        else if (rank == 1)
            position = "Daeri", p_rank = 1;
        else if (rank == 2)
            position = "Gawjang", p_rank = 2;
        else if (rank == 3)
            position = "Chajang", p_rank = 3;
        else if (rank == 4)
            position = "Bujang", p_rank = 4;
    };
    void changeName(std::string name) { this->name = name; };
};

void Employee::printInfo() {
    std::cout << name << " " << "age: " << age << " rank: " << position << " Payment: " << calculatePay() << "\n";
}

int Employee::employee_count = 0;

int main() {
    Employee haha;
    Employee MSPark("Myeongsoo Park", 45, CHAJANG);
    Employee HDJeong(MSPark);
    HDJeong.changeRank(DAERI);
    HDJeong.changeName("Hyeongdon Jeong");
    haha.printInfo();
    MSPark.printInfo();
    HDJeong.printInfo();
    return 0;
}
