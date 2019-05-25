#include <iostream>
#include <tuple>
#include <string>

int main()
{
    {
        // standard declaration
        std::tuple<std::string, int, int> t;
        // create tuple explicitly
        std::tuple<int, float, std::string> t1(40, 5.5, "Kostas");
        // getting values
        std::cout << std::get<0>(t1) << " ";
        std::cout << std::get<1>(t1) << " ";
        std::cout << std::get<2>(t1) << " ";
        std::cout << std::endl;
    }

    {
        // can create with make_tuple
        auto t = std::make_tuple(22, 44, "Kostas");
        std::tuple<int, float, std::string> t1(40, 5.5, "Kostas");
        // get function returns a reference so this is possible
        std::get<1>(t1) = std::get<1>(t);
        std::get<2>(t1) = "MyName";
    }

    {
        // we can also create references in the tuples
        std::string s;
        std::make_tuple(std::ref(s)); // type tuple<string&>
    }

    {
        // refs and ties
        auto t = std::make_tuple(77, 11.5f, "kostas");
        int i;
        float f;
        std::string s;
        std::make_tuple(std::ref(i), std::ref(f), std::ref(s)) = t;
    }

    {
        // the same with ties
        auto t = std::make_tuple(77, 11.5f, "kostas");
        int i;
        float f;
        std::string s;
        std::tie(i, f, s) = t;
    }

    {
        // should call constructor explicitly
        std::tuple<int, double> t(42, 33.3);
        std::tuple<int, double> t{42, 33.3};
        // ERROR ==> std::tuple<int, double> t = {42, 33.3};
    }

    {
        /*
        std::tuple<int,int,int> f(){
            return {1,2,3}; // ERROR tries to implicitly convert to tuple
        }
         */
    }

    {
        typedef std::tuple<int, float, std::string> TupleType;
        std::tuple_size<TupleType>::value; // this is 3
        // tuple concatenation
        auto t = std::tuple_cat(std::make_tuple(12, "me"), std::make_tuple(3.3, 4));
        // will return a tuple with 4 entries
    }
}