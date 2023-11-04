#include <iostream>
using namespace std;

bool bears(int D) {

    if (D == 42) {
        return true;
    } else if (D < 42) {
        return false;
    }
    if (D % 2 == 0 && bears(D / 2)) {
        return true;
    }
    if (D % 3 == 0 && bears(D - (D % 10) * (D / 10) % 10)) {
        return true;
    }
    if (D % 4 == 0 && bears(D - 42)) {
        return true;
    }

    return false;
}

int main() {
    int testCases[] = {250, 42, 84, 53, 41};

    for (int X = 0; X < 5; ++X) {
        bool result = bears(testCases[X]);
        cout << "bears(" << testCases[X] << ") is " << (result ? "true" : "false") <<endl;
    }

    return 0;
}