// pure functions != free functions
// pure functions are better. eliminate state if possible.
// if state is definitely required, better use OOP to encapsulate it from the outside world in a lambda function

// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword.
// meta-programming trick in templates

// Multiply, Divide, IsSame
// parameter packs, pack expansions

// constexpr, if constexpr, concepts
// Pair
// print_container


#include <iostream>

using namespace std;


int free_func(int i) { // not a pure function, it has side effects on sugar
    static int sugar = 100;

    --sugar;
    return i+sugar;
}

struct FunctionObject {
    int sugar = 100;
    int operator() (int i) {
        --sugar;
        return i+sugar;
    }
};

auto lambda = [sugar=100](int i) mutable {
    --sugar;
    return i+sugar;
};



int main(int argc, char* argv[])
{
    {
        auto val = free_func(10);
        cout << val << endl;
    }
    {
        auto val = free_func(10);
        cout << val << endl;
    }
    {
        auto fo = FunctionObject();
        cout << fo(10) << endl;
        cout << fo(10) << endl;
    }
    {
        cout << lambda(10) << endl;
        cout << lambda(10) << endl;
    }

    return 0;
}
