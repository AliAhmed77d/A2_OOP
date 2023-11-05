#include <iostream>
using namespace std;

class BigReal {
public:
    BigReal(const string& realNumber);
    BigReal(const BigReal& other);
    BigReal& operator=(const BigReal& other);

    void setNum(const string& realNumber);
    int size() const;
    int sign() const;
    BigReal operator+(const BigReal& other) const;
    BigReal operator-(const BigReal& other) const;
    bool operator<(const BigReal& anotherReal) const;
    bool operator>(const BigReal& anotherReal) const;
    bool operator==(const BigReal& anotherReal) const;

    friend ostream& operator<<(ostream& out, const BigReal& num);
};

BigReal::BigReal(const string& realNumber) {
    // Implementation of the constructor
}

BigReal::BigReal(const BigReal& other) {
    // Implementation of the copy constructor
}

BigReal& BigReal::operator=(const BigReal& other) {
    if (this == &other) {
        return *this;
    }

    // Implementation of the assignment operator

    return *this;
}

void BigReal::setNum(const string& realNumber) {
    // Implementation of the setNum function
}

int BigReal::size() const {
    // Implementation of the size function
}

int BigReal::sign() const {
    // Implementation of the sign function
}

BigReal BigReal::operator+(const BigReal& other) const {
    // Implementation of the addition operator
}

BigReal BigReal::operator-(const BigReal& other) const {
    // Implementation of the subtraction operator
}

bool BigReal::operator<(const BigReal& anotherReal) const {
    // Implementation of the less than operator
}

bool BigReal::operator>(const BigReal& anotherReal) const {
    // Implementation of the greater than operator
}

bool BigReal::operator==(const BigReal& anotherReal) const {
    // Implementation of the equality operator
}

ostream& operator<<(ostream& out, const BigReal& num) {
    // Implementation of the insertion operator
}

int main() {
    // Your code here

    return 0;
}