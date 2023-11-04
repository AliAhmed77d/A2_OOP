#include <iostream>
#include <string>
using namespace std;
void numbers(string prefix, int z) {
    if (z == 0) {
        cout << prefix << endl;
    } else {
        numbers(prefix + "0", z - 1);
        numbers(prefix + "1", z - 1);
    }
}

int main() {
    string prefix = "00101";
    int z = 2;
    numbers(prefix, z);
    return 0;
}