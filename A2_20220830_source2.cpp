#include <iostream>
using namespace std;

bool bears(int x) {

    if (x == 42) {
        return true;
    }
    else if (x < 42) {
        return false;
    }
    if (x % 2 == 0 && bears(x / 2)) {
        return true;
    }
    if (x % 3 == 0 && bears(x - (x % 10) * (x / 10) % 10)) {
        return true;
    }
    if (x % 4 == 0 && bears(x - 42)) {
        return true;
    }

    return false;
}

int main() {
    int testCases[] = { 250, 42, 84, 53, 41 };

    for (int i = 0; i < 5; ++i) {
        bool result = bears(testCases[i]);
        cout << "bears(" << testCases[i] << ") is " << (result ? "true" : "false") << endl;
    }

    return 0;
}