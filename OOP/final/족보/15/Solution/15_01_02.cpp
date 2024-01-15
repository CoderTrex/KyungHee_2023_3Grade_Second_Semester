//#pragma once
#include <iostream>
#include <ostream>
#include <cmath>

using namespace std;


template <class type>  // Answer for 2.B.
class complex
{
protected:
    type a; // real number
    type b; // imagine number
public:
    /* Answer for 2.C. */
    complex() : a(0),b(0){};
    complex(type num) : a(num) {};
    complex(type num1,type num2) : a(num1),b(num2) {};
    complex(const complex<type>& fr) {this->a = fr.a; this->b = fr.b;};

    /* Answer for 2.D. */
    complex<type>& operator = (const complex<type>& fr) {
        this->a = fr.a;
        this->b = fr.b;
        return *this;
    };
    
    complex<type>& operator = (type num)
    {
        this->a = num;
        return *this;
    };
    
    /* Answer for 2.E. */
    type getreal(){return a;};
    type getimagine(){return b;};
    
    /* Answer for 2.F. */
    friend complex<type> operator + (const complex<type>& fr1, const complex<type>& fr2) {
        return complex<type>(fr1.a+fr2.a, fr1.b+fr2.b);
    };
    friend complex<type> operator - (const complex<type>& fr1, const complex<type>& fr2) {
        return complex<type>(fr1.a-fr2.a, fr1.b-fr2.b);
    };
    friend complex<type> operator * (const complex<type>& fr1, const complex<type>& fr2) {
        return complex<type>(fr1.a*fr2.a-fr1.b*fr2.b, fr1.b*fr2.a+fr1.a*fr2.b);
    };
    friend complex<type> operator / (const complex<type>& fr1, const complex<type>& fr2) {
        return complex<type>((fr1.a*fr2.a+fr1.b*fr2.b)/(fr2.a*fr2.a+fr2.b*fr2.b), (fr1.b*fr2.a-fr1.a*fr2.b)/(fr2.a*fr2.a+fr2.b*fr2.b));
    };
    /* Answer for 2.G.*/
    complex<type> operator -= (const complex<type>& fr) {
        return *this - fr;
    };
    
    /* Answer for 2.H. */
    friend std::ostream& operator<<(std::ostream& out, const complex<type>& rhs) {
        out << "(" << rhs.a << "+" << rhs.b << "i)";
        return out;
    };

    /* Answer for 2.I. */
    friend bool operator == (const complex<type>& lhs, const complex<type>& rhs)
    {
        if(lhs.a == rhs.a && lhs.b == rhs.b)
            return true;
        return false;
    };
    
    friend bool operator != (const complex<type>& lhs, const complex<type>& rhs)
    {
        if(lhs.a == rhs.a || lhs.b == rhs.b)
            return false;
        return true;
    }
    
    /* Answer for 2.J. */
    type getabs(){return sqrt((a*a)+(b*b));}
    type getnorm(){return (a*a)+(b*b);}

    
};

int main() {
    complex<int> comInt(1, 1);
    complex<float> comFloat(1.1, 2.2);
    
    complex<double> com1;
    complex<double> com2(3.14);
    complex<double> com3(1.5, 3.14);
    complex<double> com4(com2);
    
    cout << "<Template test>" << endl;
    cout << comInt << endl;
    cout << comFloat << endl;
    
    cout << "<Constructor overloading test>" << endl;
    cout << com1 << endl;
    cout << com2 << endl;
    cout << com3 << endl;
    cout << com4 << endl;
    
    com1 = com3;
    com3 = 2.17;
    cout << "<Assignment operator test>" << endl;
    cout << com1 << endl << com2 << endl;
    
    cout << "<Function which returns Real/Imagine number test>" << endl;
    cout << "Real: " << com3.getreal() << endl;
    cout << "Imagine: " << com3.getimagine() << endl;
    
    cout << "<Operator overloading test>" << endl;
    cout << com3 << " + " << com2 << " = " << com3+com2 << endl;
    cout << com3 << " - " << com2 << " = " << com3-com2 << endl;
    cout << com3 << " * " << com2 << " = " << com3*com2 << endl;
    cout << com3 << " / " << com2 << " = " << com3/com2 << endl;
    
    com2 -= com3;
    cout << "<-= operator test>" << endl;
    
    if(com2 == com3)
        cout << "com2 and com3 are same." << endl;
    else
        cout << "com2 and com3 are different." << endl;
    
    if(com2 != com3)
        cout << "com2 and com3 are different." << endl;
    else
        cout << "com2 and com3 are same." << endl;
    
    cout << "Norm of com3: " << com3.getnorm() << endl;
    cout << "Abs of com3: " << com3.getabs() << endl;
    
    return 0;
}
