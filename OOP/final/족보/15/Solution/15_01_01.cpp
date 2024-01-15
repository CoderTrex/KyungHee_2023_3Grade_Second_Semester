#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* Base class: Employee */
class employee{
public:
    employee(string name, string tel, int pay, string boss, string helper): name(name),tel(tel),pay(pay),boss(boss),helper(helper){}
    virtual ~employee(){}
    friend std::ostream& operator<<(std::ostream& out, const employee& rhs);
    virtual int annualIncome()=0;
    int getPay(){return pay;}
private:
    string name;
    string tel;
    int pay;
    string boss;
    string helper;

};

/* Derived class 1: Slaried */
class salaried : public employee{
public:
    salaried(string name = "Anonymous", string tel = "00000000000", int pay = 0, int bonus = 0, string boss = "Anonymous", string helper = "Anonymous"): employee(name,tel,pay,boss,helper),bonus(bonus){}
    ~salaried(){};
    int annualIncome();
private:
    int bonus;
};

/* Derived class 2: Permanent */
class permanent : public employee{
public:
    permanent(string name = "Anonymous", string tel = "00000000000", int pay = 0, string boss = "Anonymous", string helper = "Anonymous"):employee(name,tel,pay,boss,helper){}
    ~permanent(){};
    int annualIncome();
private:

};

/* Derived class 3: Temporary */
class temporary : public employee{
public:
    temporary(string name = "Anonymous", string tel = "00000000000", int pay = 0, string boss = "Anonymous", string helper = "Anonymous"):employee(name,tel,pay,boss,helper){}
    ~temporary(){};
    int annualIncome();
private:

};

/* Definition of overloaded friend operator << */
std::ostream& operator<<(std::ostream& out, const employee& rhs)
{
    out << "Name: " << rhs.name << std::endl;
    out << "Phone number: " << rhs.tel << std::endl;
    out << "Boss: " << rhs.boss << std::endl;
    out << "Helper: " << rhs.helper << std::endl;
    return out;
}

/* Definition of overrided annulIncome function for salaried */
int salaried::annualIncome(){
    return getPay()*12+bonus;
}

/* Definition of overrided annulIncome function for permenent */
int permanent::annualIncome(){
    return getPay()*300;
}

/* Definition of overrided annulIncome function for temporary */
int temporary::annualIncome(){
    return getPay()*1500;
}

/* main function */
int main(){
    /* file output (write) three objects */
    employee* list[3];
        /* Dynamic memory allocation */
    list[0]=new salaried("Kim","201-0000",3000000,1000000,"Cho","Lee");
    list[1]=new permanent("Lee","201-0001",100000,"Kim","Park");
    list[2]=new temporary("Park","201-0002",7000,"Kim","Lee");
    
    ofstream fout;
        /* Binary mode */
    fout.open("emp.dat",ios::binary);
    
    fout.write((char*)list[0],sizeof(salaried));
    fout.write((char*)list[1],sizeof(permanent));
    fout.write((char*)list[2],sizeof(temporary));
    
    fout.close();
    
    /* Print objects on the screen by using overloaded << operator */
    /* Release dynmically allocated objects */
    for(int i=0; i<3; i++) {
        cout << *list[i] << endl;
        delete list[i];
    }
    
    /* file input (read) three objects */
    salaried kim;
    permanent lee;
    temporary park;
    
    ifstream fin;
    /* Exection handling for file open */
    try{
        fin.open("emp.dat",ios::binary);
        if(!fin)
            throw 0;
        
        fin.read((char*)&kim,sizeof(salaried));
        fin.read((char*)&lee,sizeof(permanent));
        fin.read((char*)&park,sizeof(temporary));
    }
    catch(int a){
        exit(0);
    }
    
    cout<< "Sum of all employee's income: " << kim.getPay()+lee.getPay()+park.getPay() << endl;
    fin.close();
    return 0;
}
