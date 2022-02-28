#include <iostream>
using namespace std;

extern int a; // something for the linker; decleration
// Nothing at runtime, only for compiler

extern const int b;

int main() {
    cout << "a :" << a << "\n";
    cout << "b :" << b << "\n";
    return 0;
}
