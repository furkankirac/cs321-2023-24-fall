// overview of encapsulating functions (OOP):
//   functions themselves (with func pointers)
//   function objects (overloading the function call operator  "operator()"
//   lambda functions

// GENERATORS (Coroutines): for functional programming
// mutable lambdas: fibonacci generator

// generic programming:
//   transform algorithm (map in other languages)
//     inline version with side-effects vs pure version
//   accumulate algorithm (reducer in other languages)
//   filter algorithm
//   count_if algorithm

#include <iostream>
#include <vector>   // an array dynamically allocated contiguously in heap memory
#include <list>     // this is a linked-list implementation
#include <string>

using namespace std;

// 0, 1, 1, 2, 3, 5, 8, 13

struct FibonacciGenerator
{
    int a;
    int b;

    FibonacciGenerator(int& a, int& b) : a(a), b(b) { }

    int operator() () {
        auto retval = a + b;
        a = b;
        b = retval;
        return retval;
    }
};


int main(int argc, char* argv[])
{
    int a=0;
    int b=1;

//    auto fg = FibonacciGenerator(a, b);

    auto fg_lambda = [a, b]() mutable {
        auto retval = a + b;
        a = b;
        b = retval;
        return retval;
    };

    for(int i=0; i<10; i++)
        cout << fg_lambda() << endl;

    cout << endl;
    cout << a << endl;
    cout << b << endl;

    return 0;
}
