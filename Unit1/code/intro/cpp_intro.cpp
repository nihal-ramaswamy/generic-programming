#include <iostream> // Header file
using namespace std; // Including standard namespace

namespace Pain {
    void pain() {
        cout << "Internal pain\n";
    }
} // namespace Pain

void pain() {
    cout << "External pain\n";
}

int main() { // Main function is entry point

    cout << "Hello World\n" << "AAAAAAAAA\n"; // Output operator along with cascading
    int pow2_3 = (1 << 3); // Same operator, different meaning

    Pain::pain(); // Calling pain function from namespace
    pain(); // Calling pain function outside namespace

    return 0;
}
