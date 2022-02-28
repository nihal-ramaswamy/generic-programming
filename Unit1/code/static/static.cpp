#include <iostream>
using namespace std;

static int y = 10; // external static

int value() {
    static int x = 5; // internal static
    return x;
}

int main() {
    cout << value() << "\n";
    cout << y << "\n";
    return 0;
}
