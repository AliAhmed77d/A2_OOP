#include <iostream>
using namespace std;

void decimalToBinary(int number) {
    int binary[32];
    int x = 0;

    while (number > 0) {
        binary[x] = number % 2;
        number = number / 2;
        x++;
    }


    for (int y = x - 1; y >= 0; y--) {
        cout << binary[y];
    }
}

int main() {
    int number;

    cin >> number;

    decimalToBinary(number);

    return 0;
}