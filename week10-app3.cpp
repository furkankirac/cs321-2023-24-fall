// Multiply, Divide, IsSame
// parameter packs, pack expansions

// constexpr, if constexpr, concepts
// Pair
// print_container

#include <iostream>

using namespace std;


template<typename T1, typename T2> struct IsSame        { static constexpr bool value = false; };
template<typename T>               struct IsSame<T, T>  { static constexpr bool value = true; };


template<typename T1, typename T2>
void print()
{
    constexpr auto issame = IsSame<T1, T2>::value;
    if constexpr(issame) {
        cout << "T1 and T2 are of the same type" << endl;
    } else {
        cout << "Hey there're different!" << endl;
    }
}

void print_int_int()
{
    cout << "T1 and T2 are of the same type" << endl;
}

void print_int_float()
{
    cout << "Hey there're different!" << endl;
}

int main(int argc, char* argv[])
{
    cout << IsSame<int, int>::value << endl;
    // cout << true << endl;
    cout << IsSame<int, float>::value << endl;
    // cout << false << endl;

    print<int, int>();
    print_int_int();
    print<int, float>();
    print_int_float();

    return 0;
}
