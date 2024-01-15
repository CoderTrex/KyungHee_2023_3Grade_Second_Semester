#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class employee {
protected:
    std::string name;
    std::string phone;
    int salary;
    std::string mento;
public:
    employee(std::string name, std::string phone, int salary, std::string mento) : name(name), phone(phone), salary(salary), mento(mento) {};
    friend ostream& operator<<(ostream&, const employee&);
};

class salaried : public employee {
public:
    int bonus;
    std::string hepler;
    salaried(std::string name, std::string phone, int salary, int bonus, std::string mento, std::string hepler) : employee(name, phone, salary, mento), bonus(bonus), hepler(hepler) {};
    friend ostream& operator<<(ostream&, const salaried&);
};

class permanent : public employee {
private:
    std::string coworker;
public:
    permanent(std::string name, std::string phone, int salary, std::string mento, std::string coworker) : employee(name, phone, salary, mento), coworker(coworker) {};
    friend ostream& operator<<(ostream&, const permanent&);
};

class temporary : public employee {
private:
    std::string coworker;
public:
    temporary(std::string name, std::string phone, int salary, std::string mento, std::string coworker) : employee(name, phone, salary, mento), coworker(coworker) {};
    friend ostream& operator<<(ostream&, const temporary&);
};

ostream& operator<<(ostream& os, const employee& e) {
    os << "Name: " << e.name << endl;
    os << "Phone: " << e.phone << endl;
    os << "Salary: " << e.salary << endl;
    os << "Mento: " << e.mento << endl;
    return os;
}

ostream& operator<<(ostream& os, const salaried& s) {
    os << "Name: " << s.name << endl;
    os << "Phone: " << s.phone << endl;
    os << "Salary: " << s.salary << endl;
    os << "Bonus: " << s.bonus << endl;
    os << "Mento: " << s.mento << endl;
    os << "Helper: " << s.hepler << endl;
    return os;
}

ostream& operator<<(ostream& os, const permanent& p) {
    os << "Name: " << p.name << endl;
    os << "Phone: " << p.phone << endl;
    os << "Salary: " << p.salary << endl;
    os << "Mento: " << p.mento << endl;
    os << "Coworker: " << p.coworker << endl;
    return os;
}

ostream& operator<<(ostream& os, const temporary& t) {
    os << "Name: " << t.name << endl;
    os << "Phone: " << t.phone << endl;
    os << "Salary: " << t.salary << endl;
    os << "Mento: " << t.mento << endl;
    os << "Coworker: " << t.coworker << endl;
    return os;
}


int main() {
    employee* list[3];
    salaried kim("Kim", "201-0000", 3000000, 1000000, "Cho", "Lee"); 
    permanent lee("Lee", "201-0001", 100000, "Kim", "Park"); 
    temporary park("Park", "201-0002", 7000, "Kim", "Lee");

    list[0] = &kim;
    list[1] = &lee;
    list[2] = &park;
    
    for (int i = 0; i < 3; i++) {
        cout << *list[i] << endl;
    }
}
