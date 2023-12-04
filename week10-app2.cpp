// Multiply, Divide, IsSame
// parameter packs, pack expansions

// constexpr, if constexpr, concepts
// Pair
// print_container

#include <iostream>

using namespace std;


int multiply_10_5 = 50;
int multiply_10_6 = 60;

struct Mul_10_5 {
    static const int value = 50;
};

struct Mul_10_6 {
    static const int value = 60;
};

template<int i, int j>
struct Mul {
    static const int value = i * j;
};


template<int i, int j> struct Div { static const int value = i / j; };
template<int a> struct Div<a, 0> { static const int value = 0; };


int main(int argc, char* argv[])
{
    auto a = 10 * 5 * 2;

    // Mul_10_6::value;
    // cout << Mul<Mul<10, 6>::value, 2>::value << endl;

    cout << Div<10, 0>::value << endl;
    // auto d = 10 / 0;

    return 0;
}
