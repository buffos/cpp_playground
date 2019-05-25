#include <iostream>
#include <utility> // for pair
#include <tuple>   // for tutple
#include <map>
#include <string>

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
        // this creates an initializer list and not a pair
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

    {
        // make_pair saves time from declaring pair types
        // it will deduce types from call parameters
        auto p = make_pair(30, 'g'); // it will correctly deduce the types
        // we can even do f(make_pair(a,b)) and do implicit conversions
        string s, t;
        auto q = make_pair(move(s), move(t));
    }

    {
        // we can also add references in pairs
        int i = 0;
        auto p = make_pair(std::ref(i), std::ref(i));
        ++p.first;  // i is now 1
        ++p.second; // i is not 2
    }

    {
        // we can also use tie to deconstruct a pair
        auto p = make_pair('x', 'y');
        char c;
        std::tie(std::ignore, c) = p; // this extracts a reference to the second argument of the pair
        // in c++17 there is a better way
    }
}