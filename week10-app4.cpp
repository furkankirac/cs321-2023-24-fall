// IsSame

// constexpr, if constexpr, concepts

using INT = int; // type aliasing

template<typename T1, typename T2, bool b> struct ConditionalType { using type = T1; };
template<typename T1, typename T2> struct ConditionalType<T1, T2, false> { using type = T2; };

template<typename T>
struct TypeDisplayer;

int main(int argc, char* argv[])
{
    using PickedType = ConditionalType<int, float, false>::type;

    // use this to generate a compile error from which you can read PickedType!
    // auto a = TypeDisplayer< PickedType >();

    return 0;
}
