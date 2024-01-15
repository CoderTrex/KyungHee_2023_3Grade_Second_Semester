#include <iostream>
#include <string>
#include <vector>

class Lecture;

class Member {
public:
    int         ID;
    std::string name;
    std::vector<Lecture *> lectureList;

    Member(int ID, std::string name) : ID(ID), name(name) {};
    virtual void participateLecture(Lecture *lecture) = 0;
    virtual void printMember() = 0;
};


class lectureMember : public Member {
public:
    int salary = 500000;
    int workingYear;

    lectureMember(int ID, std::string name, int _workingYear);
    ~lectureMember();
    void participateLecture(Lecture *lecture) override;
    void printMember() override;
};


lectureMember::lectureMember(int ID, std::string name, int _workingYear): Member(ID, name) {
    this->workingYear = _workingYear;
}

void lectureMember::participateLecture(Lecture *lecture) {
    this->lectureList.push_back(lecture);
    salary = 500000 + (100000 * workingYear) + this->lectureList.size() * 200000;
}

void lectureMember::printMember() {
    std::cout << "Lecturer: " << this->name << std::endl;
    std::cout << "ID: " << this->ID << std::endl;
    std::cout << "Lectures giving: ";
    for (int i = 0; i < this->lectureList.size(); i++) {
        std::cout << this->lectureList[i]->getLectureName() << " ";
    } 
    std::endl(std::cout);
    std::cout << "Working Years: " << workingYear << std::endl;
    std::cout << "Salary: " << salary << std::endl;
}

class StudentMember : public Member {
public:
    int tutition = 0;

    StudentMember(int ID, std::string name);
    ~StudentMember();
    void participateLecture(Lecture *lecture) override;
    void printMember() override;
};

StudentMember::StudentMember(int ID, std::string name) : Member(ID, name) {
}

void StudentMember::participateLecture(Lecture *lecture) {
    this->lectureList.push_back(lecture);
    this->tutition = this->lectureList.size() * 100000;
}


void StudentMember::printMember() {
    std::cout << "Student: " << this->name << std::endl;
    std::cout << "ID: " << this->ID << std::endl;
    std::cout << "Lectures taking: ";
    for (int i = 0; i < this->lectureList.size(); i++) 
        std::cout << this->lectureList[i]->getLectureName() << " ";
    std::endl(std::cout);
    std::cout << "Tutition: " << tutition << std::endl;
}

class Lecture {
private:
    std::string ID;
    std::string name;
    std::vector<Lecture *> prerequisiteLectureList;
    int fromWhen;   // 시작시간
    int toWhen ;    // 끝시간
public:
    Lecture(std::string ID, std::string name,  std::vector<Lecture *> prequisiteLectureList, int fromWhen, int toWhen);
    ~Lecture();
    void printLecture();

    std::string getLectureName();
};

Lecture::Lecture(std::string ID, std::string name, std::vector<Lecture *> prequisiteLectureList, int fromWhen, int toWhen) {
    this->ID = ID;
    this->name = name;
    this->prerequisiteLectureList = prequisiteLectureList;
    this->fromWhen = fromWhen;
    this->toWhen = toWhen;
}

std::string Lecture::getLectureName() {
    return this->name;
}

int main() {
    Member *m[3];
    int in;
    for (int i = 0; i < 3; i++) {
        std::cout << "사용자 추가. 둘 중 선택하시오, 강사:1, 학생:2  ";
        std::cin >> in;
        if (in == 1)
            m[i] = new lectureMember(1, "이성원", 1);
        else
            m[i] = new StudentMember(2, "정은성");
    }
    m[0]->participateLecture("OOP");
    m[0]->participateLecture("OS");
    m[1]->participateLecture("software");
    m[2]->participateLecture("software");
    m[2]->participateLecture("software");
    m[2]->participateLecture("software");
    m[2]->participateLecture("software");

    for (int i = 0; i < 3; i++) {
        m[i]->printMember();
        std::cout << std::endl;
    }
}