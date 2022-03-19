#include <iostream>
using namespace std;

#define println cout << "[" << __LINE__ << "]\n----------------------------\n";

class Test
{
public:
    Test() { cout << "Constructor is executed\n"; }
    ~Test() { cout << "Destructor is executed\n"; }
    void test() {
        cout << "Working\n";
    }
    friend void fun(Test t);
};
void fun(Test t)
{
    println;
    Test();
    println;
    t.~Test();
    t.test();
    println;
}
int main()
{
    println;
    Test();
    println;
    Test t;
    println;
    fun(t);
    println;
    return 0;
}
