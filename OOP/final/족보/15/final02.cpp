#include <iostream>


template <typename TYPE>
class complex {
private:
    TYPE a;
    TYPE b;
public:
    complex(): a(0), b(0) {};
    complex(TYPE a) : a(a), b(0) {};
    complex(TYPE a, TYPE b) : a(a), b(b) {};
    complex(const complex& c) : a(c.a), b(c.b) {};
    ~complex() {};
    
    void prinTYPEComplex();
    
    TYPE returnA() {return a;};
    TYPE returnB() {return b;};

    complex<TYPE> operator=(TYPE num);
    complex operator+(complex& c) {
        complex temp;
        temp.a = this->a + c.a;
        temp.b = this->b + c.b;
        return temp;
    }
    complex<TYPE> operator-(complex<TYPE>& c) {
        complex temp;
        temp.a = this->a - c.a;
        temp.b = this->b - c.b;
        return temp;
    }
    complex<TYPE> operator*(complex<TYPE>& c) {
        complex temp;
        temp.a = this->a * c.a - this->b * c.b;
        temp.b = this->b * c.a + this->a * c.b;
        return temp;
    }
    // complex<TYPE> operator/(complex<TYPE>& c) {
    //     complex temp;
    //     temp.a = (this->a * c.a + this->b * c.b) / (c.a * c.a + c.b * c.b);
    //     temp.b = (this->b * c.a - this->a * c.b) / (c.a * c.a + c.b * c.b);
    //     return temp;  
    // }
    friend complex<TYPE> operator / (const complex<TYPE>& fr1, const complex<TYPE>& fr2) {
        return complex<TYPE>((fr1.a*fr2.a+fr1.b*fr2.b)/(fr2.a*fr2.a+fr2.b*fr2.b), (fr1.b*fr2.a-fr1.a*fr2.b)/(fr2.a*fr2.a+fr2.b*fr2.b));
    };
        /* Answer for 2.H. */
    friend std::ostream& operator<<(std::ostream& out, const complex<type>& rhs) {
        out << "(" << rhs.a << "+" << rhs.b << "i)";
        return out;
    };
};

template <typename TYPE>
void complex<TYPE>::prinTYPEComplex() {
    std::cout << this->a << " + " << this->b << "i" << std::endl;
}

template <typename TYPE>
complex<TYPE> complex<TYPE>::operator=(TYPE num) {
    this->a = num;
    this->b = 0;
    return *this;
}

int main() {
    complex<int> c1(1, 2);
    complex<int> c2(3, 4);
    complex<int> c3;
    c3 = c1 + c2;
    c3.prinTYPEComplex();
    c3 = c1 - c2;
    c3.prinTYPEComplex();
    c3 = c1 * c2;
    c3.prinTYPEComplex();
    c3 = c1 / c2;
    c3.prinTYPEComplex();
    return 0;
}

