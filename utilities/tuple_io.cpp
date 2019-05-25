#include <iostream>
#include <tuple>
#include <string>

// IO and tuples
// How to write to a stream
template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE
{
    static void print(std::ostream &strm, const std::tuple<Args...> t)
    {
        strm << std::get<IDX>(t) << (IDX + 1) == MAX ? "" : ",";
        PRINT_TUPLE<IDX + 1, MAX, Args...>::print(strm, t);
    }
};

template <int MAX, int MAX, typename... Args>
struct PRINT_TUPLE
{
    static void print(std::ostream &strm, const std::tuple<Args...> t)
    {
        // empty to end recursion
    }
};

template <typename... Args>
std::ostream &operator<<(std::ostream &strm, const std::tuple<Args...> t)
{
    strm << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(strm, t);
    return strm << "]";
}
