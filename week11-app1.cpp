// reverse algorithm
// all_of predicate (parameter-packs)
// take<x> algorithm
// accumulate algorithm in higher-order-function form

// solving for the input to container case
// "requires" expression
// concepts

#include <iostream>
#include <vector>

using namespace std;

auto print_(const auto& container)
{
    for(const auto& item : container) {
        cout << item << ", ";
    }
    cout << endl;
    return container;
}

auto PRINT() {
    return [](const auto& container) {
        return print_(container);
    };
}



template<typename T>
concept IsContainer = requires (T t) {
    t.size();
    t.begin();
    t.end();
};

template<typename T>
concept IsPushable = requires (T t) {
    &t.push_back;
};

// template<typename Container>
// requires(IsContainer<Container>)
// auto operator|(const Container& container, const auto& func) {
//     return func(container);
// }

// template<IsContainer Container>
// auto operator|(const Container& container, const auto& func) {
//     return func(container);
// }

auto operator|(const IsContainer auto& container, const auto& func) {
    return func(container);
}

auto operator|(const auto& left, const auto& right) {
    return [=](const auto& item) {
        return right(left(item));
    };
}

auto swap(auto& a, auto& b) {
    auto t = a;
    a = b;
    b = t;
}

auto reverse_(const IsContainer auto& container) {
    auto new_cont = container;
    auto sz = new_cont.size();
    for(int i=0; i<sz/2; i++) {
        swap(new_cont[i], new_cont[sz-i-1]);
    }
    return new_cont;
}

auto reverse() {
    return [](const IsContainer auto& container) {
        return reverse_(container);
    };
}

template<typename Container>
// requires(IsContainer<Container> && IsPushable<Container>)
auto filter_(const Container& container, auto func) {
    auto new_cont = Container{};
    for(const auto& item : container) {
        if(func(item)) {
            new_cont.push_back(item);
        }
    }
    return new_cont;
}

auto filter(auto func) { // currying
    return [=](const auto& container) {
        return filter_(container, func);
    };
}


auto higher_than_(const auto& item, const auto& threshold) {
    return item > threshold;
}

auto higher_than(const auto& threshold) {
    return [=](const auto& item, const auto& threshold) {
        return higher_than_(item, threshold);
    };
}

auto less_than_(const auto& item, const auto& threshold) {
    return item < threshold;
}

auto less_than(const auto& threshold) {
    return [=](const auto& item, const auto& threshold) {
        return less_than_(item, threshold);
    };
}

auto all_of_(const auto& item, auto pred1, auto pred2) {
    return pred1(item) && pred2(item);
}

auto all_of(auto pred1, auto pred2) {
    return [=](const auto& item) {
        return all_of_(item, pred1, pred2);
    };
}


int main(int, char* [])
{
    // using CONTAINER = std::array<int, 6>;
    using CONTAINER = std::vector<float>;

    CONTAINER{1.1, 50.3, -3, 5, 10, 100}
        | PRINT()
        | reverse() | PRINT()
        | filter([](auto item) { return item > 10; })
        | filter(all_of(higher_than(0), less_than(60)));
        // | take<2>() | PRINT
        // | transform(add(2)) | PRINT
        // | accumulate(1, multiplier) | PRINT;

    return 0;
}
