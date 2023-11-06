// introducing std::vector<T>
// "transform/map" algorithm with function pointers

// encapsulating functions:
//   functions themselves (with func pointers),
//   function objects
//   lambda functions

// iterators and range-for-loop

// unified/universal construction:
//   stricter construction with {} instead of (),
//   initializer_list support for ctors

#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

using TwoInters = int (*)(int, int);
using OneInter = int (*)(int);

//void transform(vector<int>& v, OneInter funcptr)
//{
//    auto sz = v.size();
//    for(decltype(sz) i = 0; i < sz; i++)
//        v[i] = funcptr(v[i]);
//}

int dosmt1(int a) { return a; }
int dosmt2(int a) { return a*a; }
int incrementBy1(int a) { return a+1; }

int incrementByK_K;
int incrementByK(int a) { return a + incrementByK_K; }

int incrementByKMulM_K;
int incrementByKMulM_M;
int incrementByKMulM(int a) {
    return (a + incrementByKMulM_K) * incrementByKMulM_M;
}

//template<typename Container, typename Func>
//void transform(Container& v, Func funcptr)
//{
//    for(auto iter = v.begin(); iter != v.end(); iter++) {
//        auto& item = *iter;
//        item = funcptr(item);
//    }
//}

template<typename Container, typename Object>
void transform(Container& v, const Object& obj)
{
    for(auto& item : v) {
//    for(auto iter = v.begin(); iter != v.end(); iter++) {
//        auto& item = *iter;
//        item = obj.run(item);
        item = obj(item); // obj.run(item);
    }
}

//template<typename Container, typename Func>
//void transform(Container& v, Func funcptr, int k)
//{
//    for(auto iter = v.begin(); iter != v.end(); iter++) {
//        auto& item = *iter;
//        item = funcptr(item, k);
//    }
//}

template<typename Container>
void print(const Container& v)
{
    for(auto iter = v.begin(); iter != v.end(); iter++) {
        const auto& item = *iter;
        cout << item << ' ';
    }
//    auto sz = v.size(); // size_t ---> unsigned int
//    for(int i=0; i<sz; i++) {
//        const auto& item = v[i];
//        cout << item << ' ';
//    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    auto v = vector<int>{1, 2, 3, 10, 20};
    print(v);
//    incrementByKMulM_K = 10;
//    incrementByKMulM_M = 2;
//    transform(v, &incrementByKMulM);

//    transform(v, IncrementByKMulM(5, 10));

    struct IncrementByKMulM
    {
        int K;
        int M;

        IncrementByKMulM(int K, int M) : K(K), M(M) { }

        inline int operator() (int a) const {
            return (a + K) * M;
        }
    };

    auto obj = IncrementByKMulM(5, 100);

    transform(v, [K=5, M=100](int a) { return (a + K) * M; });
    print(v);

    return 0;
}
