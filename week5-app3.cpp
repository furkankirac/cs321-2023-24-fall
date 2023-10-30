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

struct Fahrenheit;

struct Celcius {
    double value;
    Celcius(double value) : value(value) { }
    Celcius(const Fahrenheit& f);
};

struct Fahrenheit {
    double value;
    Fahrenheit(double value) : value(value) { }
    Fahrenheit(const Celcius& c) : value((c.value * 9) / 5 + 32) { }
};

Celcius::Celcius(const Fahrenheit& f) : value((f.value - 32) / 9 * 5) { }



auto operator"" _c(long double value) {
    return Celcius(value);
}

auto operator"" _f(long double value) {
    return Fahrenheit(value);
}


[[nodiscard]] int func(int a)
{
    std::cout << "hello there" << std::endl;
    return a+1;
}

int main(int argc, char* argv[])
{
    auto c1 = Celcius(30);
    auto f1 = Fahrenheit(120);
    auto c2 = 30.0_c;
    auto f2 = 120.0_f;

    auto c3 = Celcius(f1);
    auto f3 = Fahrenheit(c1);

    (Fahrenheit)Celcius(f1);

    10;
    func(10);

    using namespace std;
    cout << f1.value << endl;
    cout << c3.value << endl;

    return 0;
}
