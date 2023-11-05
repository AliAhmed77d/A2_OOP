#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> split(const string& target, const string& delimiter) {
    vector<string> total;
    size_t start = 0, end = 0;

    while ((end = target.find(delimiter, start)) != string::npos) {
        result.push_back(target.substr(start, end - start));
        start = end + delimiter.length();
    }

    result.push_back(target.substr(start));
    return result;
}

int main() {
    string inputA = "10,20,30";
    string delimiterA = ",";
    vector<string> resultA = split(inputA, delimiterA);

    string inputB = "do re mi fa so la ti do";
    string delimiterB = " ";
    vector<string> resultB = split(inputB, delimiterB);


    for (const string& str : resultA) {
        cout << str << endl;
    }

    for (const string& str : resultB) {
        cout << str << endl;
    }

    return 0;
}