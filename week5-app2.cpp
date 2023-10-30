// function pointers
// for_each

// Fraction class: Want to represent rational numbers with a numerator and denominator

// OOP: (encapsulates all necessary tools in a box that communicates
//  with caller via c-tors, assignment operators, and casting
// ctor/dtor
// copy-ctor, copy-assignment
// casting
// inheritance (will discuss later)

// function overloading, overload set
// operators and operator overloading

// literals, types of constants (remember units in your Physics class: 9.8 m/s^2)
// user-defined literals (a special way to create your own literals)

// Celsius/Fahrenheit example
// converting constructors

// pass by value, pass by reference, pass by constant reference
// implicit/explicit constructors

// operator== and operator+ overloads for Celsius/Fahrenheit
// static attributes and staticness. static variable initialization

#include <iostream>
#include <vector>

using namespace std;

struct Fraction {
    int n;
    int d;

    Fraction(int n, int d = 1) : n(n), d(d) { }
//    Fraction(int n) : n(n), d(1) { }

    Fraction(const Fraction& other) : n(other.n), d(other.d) {
        cout << "copy constructor of Fraction called" << endl;
    }

    void operator=(const Fraction& right) { // copy-assignment operator
        this->n = right.n;
        this->d = right.d;
        cout << "copy assignment of Fraction called" << endl;
    }

    operator double() {
        return double(n) / d;
    }

};

void print(const Fraction& f)
{
    cout << f.n << "/" << f.d << endl;
}

int doit(int a, int b) { return a; }
int doit(float a, int b) { return a+b; }
int doit(double a, int b) { return a-b; }


auto operator"" _frac(long double value)
{
    return Fraction(int(value));
}

int main(int argc, char* argv[])
{
    auto f0 = 25.0_frac;
    auto f1 = Fraction(1, 4);
    auto f2 = Fraction(5);
    auto text = std::string("hi there");
    auto text2 = "hi there"s;

//    f1 = f2; // copy assignment
//    f1.operator=(f2);
    print(f1);
    print(f2);

    f1 = 15;
    print(f1);

//    Fraction f3(f1);
//    Fraction f3 = f1;
    auto f3 = f1;
    f3 = f1;

    cout << Fraction(15, 4) << endl;

    return 0;
}
