// 3 main algorithms
// transform (called "map" in some languages)
// filter
// accumulate (called "reduce" in some languages)

#include <iostream>
#include <vector>

using namespace std;

auto print_(const auto& container)
{
    for(const auto& item : container)
        cout << item << ", ";
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

auto operator|(const IsContainer auto& container, const auto& func) {
    return func(container);
}

auto operator|(const auto& left, const auto& right) {
    return [=](const auto& item) {
        return right(left(item));
    };
}

template<typename Container>
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

template<typename Container>
auto transform_(Container& container, auto func) {
    auto new_cont = container;
    for(auto& item : new_cont) {
        using func_ret_t = decltype(func(item));
        // if constexpr(is_same<func_ret_t, void>::value)
        //     func(item);
        // else
            item = func(item);
    }
    return new_cont;
}

auto transform(auto func) { // currying
    return [=](const auto& container) {
        return transform_(container, func);
    };
}

template<typename T1, typename T2> struct IsSame       { static const bool value = false; };
template<typename T>               struct IsSame<T, T> { static const bool value = true; };


auto algo_(auto& container, auto func) {
    using item_t = decltype(*container.begin());
    using retval_t = decltype(func(item_t{}));
    if constexpr(IsSame<retval_t, bool>::value) {
        return filter_(container, func);
    } else {
        return transform_(container, func);
    }
}

auto algo(auto func) { // currying
    return [=](auto& container) {
        return algo_(container, func);
    };
}


int main(int, char* [])
{
    std::vector<float>{1.1, 50.3, -3, 5, 10, 100}
        | PRINT()
        // | algo([](auto item) { return item > 10; })
        | algo([](auto& item) { return item + 1; })
        | PRINT()
        // | algo([](auto item) { return item + 1; })
        // | PRINT()
        ;

    return 0;
}
