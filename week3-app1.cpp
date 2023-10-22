// stack memory vs heap memory
// value semantics vs reference semantics

// global scope, local scope
// free-functions

// class/struct? object? ------> type? instance?
// typedef (C)

// c-tor of a primitive type
// c-tor of a complex type (struct)

// write a c-tor of a struct instance as a free function (imperative programming paradigm)
// write a c-tor of a struct instance as a member function (OOP paradigm)

// allocate memory at run-time (dynamic memory allocation)
// free memory at run-time

// write a dtor as a free function (imperative programming paradigm)
// write a dtor as a member function (OOP paradigm)

// member variables ~= attributes ~= properties (OOP)

#include <iostream>

int i = 10;

struct Vector2d {
    int a;
    int b;

    Vector2d() : a(0), b(0) { }

    Vector2d(int a_, int b_) : a(a_), b(b_) { }

    Vector2d addVectors(const Vector2d& second) {
        Vector2d result; // default c-tor

        result.a = this->a + second.a;
        result.b = this->b + second.b;
        return result;
    }

    Vector2d operator+(const Vector2d& right) {
        Vector2d result;
        result.a = this->a + right.a;
        result.b = this->b + right.b;
        return result;
    }
};

//Vector2d operator+(const Vector2d& left, const Vector2d& right) {
//    Vector2d result;
//    result.a = left.a + right.a;
//    result.b = left.b + right.b;
//    return result;
//}




void func() {
    int i = 100;
    //    func(i);

    // first 2d vector instance
    Vector2d A(5, 7);

    // second 2d vector instance
    Vector2d B(-1, 3);

    // add two 2d vectors


    Vector2d C = A + B;
//    Vector2d C = operator+(A, B);
//    Vector2d C = A.addVectors(B);
}


int main(int argc, char* argv[])
{
    func();

    func();

    return 0; // 0 means everything is okay
}
