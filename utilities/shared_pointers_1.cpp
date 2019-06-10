#include <iostream>
#include <vector>
#include <memory>
#include <string>

using std::cout;
using std::vector;

int main()
{
    std::shared_ptr<std::string> p1(new std::string("kostas"),
                                    [](std::string *p) {
                                        cout << "deleting..." << *p << std::endl;
                                        delete p;
                                    });
    std::shared_ptr<std::string> p2(new std::string("giannis"),
                                    [](std::string *p) {
                                        cout << "deleting..." << *p << std::endl;
                                        delete p;
                                    });

    (*p1)[0] = 'K';
    p2->replace(0, 1, "G");

    cout << *p1 << std::endl;
    cout << *p2 << std::endl;

    vector<std::shared_ptr<std::string>> whoMadeCoffee;

    whoMadeCoffee.push_back(p2);
    whoMadeCoffee.push_back(p2);
    whoMadeCoffee.push_back(p2);
    whoMadeCoffee.push_back(p1);
    whoMadeCoffee.push_back(p1);

    for (auto ptr : whoMadeCoffee)
    {
        cout << *ptr << " ";
    }
    cout << std::endl;

    *p1 = "Dimitris";

    for (auto ptr : whoMadeCoffee)
    {
        cout << *ptr << " ";
    }
    cout << std::endl;

    cout << "Use Count: " << whoMadeCoffee[0].use_count() << std::endl;

    whoMadeCoffee.resize(2);

    p1 = nullptr; // this will call the deleter first

    cout << "exiting..." << std::endl;
}