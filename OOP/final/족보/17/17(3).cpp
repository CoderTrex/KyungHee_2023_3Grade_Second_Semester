#include <iostream>
#include <string.h>
#include <string>

enum Rank { SAWON, DAERI, GWAJANG, CHAJANG, BUJANG };

class Employee {
protected:
    int age;
    int p_rank;
    std::string position;
    // static int employee_count;

public:
    std::string name;
    Employee(); 
    Employee(std::string name, int age, Rank positon);  
    Employee(const Employee &cp);

    virtual void printInfo();
    virtual int calculatePay();
    void changeRank(Rank rank);
    void changeName(std::string name) { this->name = name; };
};

class EmployeeList {
protected:
    int employee_count;
    Employee **employee_list;

public:
    EmployeeList();
    ~EmployeeList();

    void    addEmployee(Employee *employee);
    int     numberOfcurrentEmployee();
    void    printEmployeeList();
    bool    deleteEmployee(const char *employee);
};

class ManagerEmployee : public Employee {
protected:
    int work_year;

public:
    ManagerEmployee(std::string name, int age, Rank position, int work_year);
    int calculatePay() override;
    void printInfo() override;
};

class TemporaryEmployee : public Employee {
protected:
    int work_hour;

public:
    TemporaryEmployee(std::string name, int age, Rank position, int work_hour);
    int calculatePay() override;
    void printInfo() override;
};

void ManagerEmployee::printInfo() {
    std::cout << name << " " << "age: " << age << " rank: " << position << " working years: " <<  work_year << " Payment: " << calculatePay() << "\n";
}


void TemporaryEmployee::printInfo() {
    std::cout << name << " " << "age: " << age << " rank: " << position << " working hours: " <<  work_hour << " Payment: " << calculatePay() << "\n";
}


TemporaryEmployee::TemporaryEmployee(std::string name, int age, Rank position, int work_hour) : Employee(name, age, position), work_hour(work_hour) {
    this->work_hour = work_hour;
}

int TemporaryEmployee::calculatePay() {
    int payment = this->work_hour * 0.5;
    return payment;
}

ManagerEmployee::ManagerEmployee(std::string name, int age, Rank position, int work_year) : Employee(name, age, position), work_year(work_year) {
    this->work_year = work_year;
}

int ManagerEmployee::calculatePay() {
    int payment = p_rank * 100 + 500 + work_year * 10;
    return payment;
}

EmployeeList::EmployeeList() {
    employee_count = 0;
    employee_list = new Employee*[20];
}

EmployeeList::~EmployeeList() {
    delete[] employee_list;
}

void EmployeeList::addEmployee(Employee *employee) {
    employee_list[employee_count] = employee;
    employee_count++;
}

int EmployeeList::numberOfcurrentEmployee() {
    return employee_count;
}

void EmployeeList::printEmployeeList() {
    for (int i = 0; i < employee_count; i++) {
        employee_list[i]->printInfo();
    }
}

bool EmployeeList::deleteEmployee(const char *employee) {
    for (int i = 0; i < employee_count; i++) {
        if (strcmp(employee_list[i]->name.c_str(), employee) == 0) {
            for (int j = i; j < employee_count - 1; j++) {
                employee_list[j] = employee_list[j + 1];
            }
            employee_count--;
            return true;
        }
    }
    return false;
}

Employee::Employee(): age(30), p_rank(0), name("Anonymous"), position("SAWON") {
    // employee_count++;
};

Employee::Employee(std::string name, int age, Rank position) : name(name), age(age), p_rank(position) {
    // employee_count++;
    if (position == 0)
        this->position = "Sawon";
    else if (position == 1)
        this->position = "Daeri";
    else if (position == 2)
        this->position = "Gwajang";
    else if (position == 3)
        this->position = "Chajang";
    else if (position == 4)
        this->position = "Bujang";
}

Employee::Employee(const Employee &cp) : age(cp.age), p_rank(cp.p_rank), name(cp.name), position(cp.position) {
    // employee_count++;
};

void Employee::printInfo() {
    std::cout << name << " " << "age: " << age << " rank: " << position << " Payment: " << calculatePay() << "\n";
}

void Employee::changeRank(Rank rank) {
        if (rank == 0)
            position = "Sawon", p_rank = 0;
        else if (rank == 1)
            position = "Daeri", p_rank = 1;
        else if (rank == 2)
            position = "Gwajang", p_rank = 2;
        else if (rank == 3)
            position = "Chajang", p_rank = 3;
        else if (rank == 4)
            position = "Bujang", p_rank = 4;
};

int Employee::calculatePay() { 
    int payment = p_rank * 100 + 500; 
    return payment;
}

// int Employee::employee_count = 0;

int main() {
    EmployeeList el;
    el.addEmployee(new Employee("HongcheolNo", 34, SAWON));
    el.addEmployee(new Employee("Haha",34, SAWON));
    el.addEmployee(new ManagerEmployee("JaeseokYoo", 41, BUJANG, 15));
    el.addEmployee(new Employee("JunhaJeong", 43, GWAJANG));
    el.addEmployee(new ManagerEmployee("MyeongsooPark",43,CHAJANG,13));
    el.addEmployee(new Employee("HyeongdonJeong", 36, DAERI));
    el.addEmployee(new TemporaryEmployee("Gil",36, SAWON, 160));
    el.printEmployeeList();

    // el.addEmployee(new Employee("HongcheolNo", 34, SAWON));
    // el.addEmployee(new Employee("Haha",34, SAWON));
    // el.addEmployee(new Employee("Jaeseok Yoo",41, BUJANG));
    // el.addEmployee(new Employee("Junha Jeong",43, GWAJANG));
    // el.addEmployee(new Employee("MyeongsooPark", 43, CHAJANG));
    // el.addEmployee(new Employee("HyeongdonJeong", 36, DAERI));
    // el.printEmployeeList();
    // el.deleteEmployee("Haha");
    // el.printEmployeeList();

    return 0;
    // Employee haha;
    // Employee MSPark("Myeongsoo Park", 45, CHAJANG);
    // Employee HDJeong(MSPark);
    // HDJeong.changeRank(DAERI);
    // HDJeong.changeName("Hyeongdon Jeong");
    // haha.printInfo();
    // MSPark.printInfo();
    // HDJeong.printInfo();
    // return 0;
}
