#include <iostream>
#include <utility> // for pair
#include <tuple>   // for tutple
#include <map>

#include <typeinfo>

using namespace std;

struct big
{
    int data[100];
    big(int first, int step)
    {
        for (int i = 0; i < 100; i++)
        {
            data[i] = first + i * step;
        }
    }
};

template <typename T, typename U>
ostream &operator<<(ostream &strm, pair<T, U> p)
{
    return strm << "pair = [ " << p.first << ", " << p.second << " ]" << endl;
}

int main()
{
    {
        auto p = {7, 5};
        cout << typeid(decltype(p)).name() << endl; // St16initializer_listIiE
    }

    {
        pair<int, int> p = {7, 5};
        cout << typeid(decltype(p)).name() << endl; //St4pairIiiE
        cout << p;
    }

    {
        pair<int, const char *> p = {7, "5"};
        cout << typeid(decltype(p)).name() << endl; // St4pairIiPKcE
        cout << p;
    }

    {
        map<int, big> m;
        auto p = m.emplace(piecewise_construct, forward_as_tuple(1) /*key*/, forward_as_tuple(1, 10) /*value*/); //c++14
        cout << typeid(decltype(p)).name() << endl;                                                              // St4pairISt17_Rb_tree_iteratorIS_IKi3bigEEbE
        cout << p.first->first << endl;
    }
}