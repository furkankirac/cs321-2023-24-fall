// generic programming:
//   transform algorithm (map in other languages)
//     inline version with side-effects vs pure version
//   filter algorithm
//   count_if algorithm

//   accumulate algorithm (reducer in other languages)

#include <iostream>
#include <vector>
#include <list>

using namespace std;

//template<typename Container, typename Func>
void transform_inline(auto& container, const auto& func) {
//    for(auto it = container.begin(); it != container.end(); it++) {
//        auto& item = *it;
//        // ...
//    }
    for(auto& item : container) {
        item = func(item);
    }
}

auto transform(const auto& container, const auto& func) {
    auto new_container = container;
    for(auto& item : new_container) {
        item = func(item);
    }
    return new_container;
}

template<typename Container>
auto filter(const Container& container, const auto& func) {
    auto new_container = Container{};
    for(auto& item : container) {
        if(func(item)) {
            new_container.push_back(item);
        }
    }
    return new_container;
}


template<typename Container>
void print(const Container& cont){
    for(const auto& item : cont)
        cout << item << ", ";
    cout << endl;
}

auto accumulate(const auto& container, const auto& func, auto init) {
    auto value = init;
    for(const auto& item : container) {
        value = func(value, item);
    }
    return value;
}

int main(int argc, char* argv[])
{
    auto L = list<float>{1.1f, 2.2f, 3.3f};

    auto multiplyBy2 = [](float& value) { return value * 2; };

    print(L);
//    transform_inline<list<float>, decltype(multiplyBy2)>(L, multiplyBy2);
//    transform_inline(L, multiplyBy2);
    auto L_new = transform(L, multiplyBy2);
    print(L);
    print(L_new);

    auto L_new_filtered = filter(L_new, [](const auto& item) {
        return item > 4.0f;
    });
    print(L_new_filtered);

    {
        auto sum =
            accumulate(L_new_filtered, [](const auto& value, const auto& item) {
            return value + item;
        }, 0.0f);

//        auto sum = 0.0f;
//        for(const auto& item : L_new_filtered)
//            sum += item;
        cout << "Sum is " << sum << endl;

        auto product = 1.0f;
        for(const auto& item : L_new_filtered)
            product *= item;
        cout << "Product is " << product << endl;

    }




    return 0;
}
