//Першин Александр, 335 группа, задание "Кортежи"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

template<typename... Ttypes>
class Tuple;

template<>
class Tuple<> {};

template<typename Tfirst, typename... Tother>
class Tuple<Tfirst, Tother...> : public Tuple<Tother...> {
public:
    Tfirst value;
};

template<size_t index, typename Ttuple>
class Element;

template<typename Tfirst, typename... Tother>
class Element<0, Tuple<Tfirst, Tother...>> {
public:
    using Type_t = Tfirst;
    using TupleType_t = Tuple<Tfirst, Tother...>;
};

template<size_t index, typename Tfirst, typename... Tother>
class Element<index, Tuple<Tfirst, Tother...>> : public Element<index - 1, Tuple<Tother...>> {};

template<size_t index, typename... Ttypes>
typename Element<index, Tuple<Ttypes...>>::Type_t&
Get_Element(Tuple<Ttypes...>& tuple) {
    using TupleType_t = typename Element<index, Tuple<Ttypes...>>::TupleType_t;
    return static_cast<TupleType_t&>(tuple).value;
}

template<size_t index, typename Ttuple>
void FillTuple(Ttuple& tuple) {}

template<size_t index, typename Ttuple, typename Tfirst, typename... Tother>
void FillTuple(Ttuple& tuple, const Tfirst& first, const Tother&... other) {
    Get_Element<index>(tuple) = first;
    FillTuple<index + 1>(tuple, other...);
}

template<typename... Ttypes>
Tuple<Ttypes...> MakeTuple(const Ttypes&... args) {
    Tuple<Ttypes...> temp;
    FillTuple<0>(temp, args...);
    return temp;
}


int main() {

    auto tuple = MakeTuple(888, 3.14, 'g', string("abc"));

    auto element_1 = Get_Element<0>(tuple);
    auto element_2 = Get_Element<1>(tuple);
    auto element_3 = Get_Element<2>(tuple);
    auto element_4 = Get_Element<3>(tuple);

    cout << element_1 << endl << element_2 << endl;
    cout << element_3 << endl << element_4 << endl;

    return 0;
}