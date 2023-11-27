// in search of a simpler and more understandable generic way of writing code
//  the dance of OOP, FP and GP paradigms

// lifting a function (higher order functions):
//  a function returning a function object: delays function use
// lt, gt, get_name, ...

// composing functions

// extra generic transform algorithm


#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Color { Red, Blue, Black };

struct Laptop {
    float price;
    short ram;
    string model;
    Color color;
};

auto get_price_(const auto& l) { return l.price; }

// struct GetPrice {
//     auto operator() (const Laptop& l) { return l.price; }
// };

auto get_price() {
    // auto price_extractor = GetPrice();
    // return price_extractor;
    return [](const auto& l) { return get_price_(l); };
}


// template<typename T>
auto less_than_(auto a, auto b) { return a < b; }

auto less_than(auto what) {
    return [what](auto value) {
        return less_than_(value, what);
        // return value < what;
    };
}

auto printer_(const auto& whatever)
{
    cout << whatever << endl;
    return whatever;
}

auto printer() {
    return [](const auto& whatever) {
        return printer_(whatever);
        // return whatever;
    };
}


auto compose(auto f, auto g) {
    return [f, g](const auto& item) {
        return g(f(item));
    };
}

auto operator|(auto f, auto g) {
    return compose(f, g);
}

template<typename Container>
auto filter(const Container& container, auto func)
{
    auto C = Container{};
    for(const auto& item : container) {
        if(func(item))
            C.push_back(item);
    }
    return C;
}

void print(const auto& container) {
    for(const auto& item : container)
        cout << item.model << ", ";
    cout << endl;
}


int main(int argc, char* argv[])
{
    auto v = vector<Laptop>{
        {8000, 32, "Dell", Color::Red},
        {38000, 64, "Apple", Color::Blue},
        {25000, 64, "Lenovo", Color::Black},
    };

    auto item = v[0];
    // cout << get_price()(item) << endl;

    auto lt10000 = less_than(10000);
    // cout << lt10000(19000) << endl;

    // auto FoGoL = compose(compose(get_price(), less_than(10000)), printer());
    auto FoGoL = get_price() | printer() | less_than(30000) | printer();
    // auto FoGoL = operator|(get_price(), less_than(10000)) | printer();

    // FoGoL(item);
    // cout << FoG(item) << endl;


    auto result = filter(v, FoGoL);
    print(result);


    // auto color = Color::Red;

    // auto laptop = Laptop{8000, 32, "Dell", Color::Red};
    return 0;
}
