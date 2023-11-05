/*
File:A2_S16_20220109_Task10.cpp
Purpose: Message Altering to Avoid Censorship
Author: Hussam Eldin Hesham Ahmed
Section: S16
ID: 20220109
TA: Mohamed Talaat
Date: 25 Oct 2023
*/


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

// Load the lookup table from a file into a map
map<string, vector<string>> LoadLookupTable(const string& filename) {
    map<string, vector<string>> lookupTable;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        size_t pos = line.find("=");
        if (pos != string::npos) {
            string word = line.substr(0, pos);
            string alternatives = line.substr(pos + 1);
            size_t start = 0;
            size_t end = alternatives.find(",");
            vector<string> altWords;

            while (end != string::npos) {
                altWords.push_back(alternatives.substr(start, end - start));
                start = end + 1;
                end = alternatives.find(",", start);
            }

            altWords.push_back(alternatives.substr(start, end));
            lookupTable[word] = altWords;
        }
    }

    return lookupTable;
}

// Replace words in the message with alternatives
string ReplaceWords(const string& message, const map<string, vector<string>>& lookupTable) {
    string result = message;
    default_random_engine generator(static_cast<unsigned>(time(0)));

    for (const auto& entry : lookupTable) {
        string wordToReplace = entry.first;
        const vector<string>& alternatives = entry.second;

        if (alternatives.empty()) {
            continue;
        }

        uniform_int_distribution<int> distribution(0, alternatives.size() - 1);
        int randomIndex = distribution(generator);

        size_t found = result.find(wordToReplace);
        while (found != string::npos) {
            result.replace(found, wordToReplace.length(), alternatives[randomIndex]);
            found = result.find(wordToReplace, found + alternatives[randomIndex].length());
        }
    }

    return result;
}

int main() {
    map<string, vector<string>> lookupTable = LoadLookupTable("lookup_table.txt");

    ifstream inputFile("Task10.txt");
    string message;

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            message += line + '\n';
        }

        inputFile.close();

        string alteredMessage = ReplaceWords(message, lookupTable);

        ofstream outputFile("altered_message.txt");
        outputFile << alteredMessage;
        outputFile.close();

        cout << "Message altered and saved to 'altered_message.txt'." << endl;
    } else {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    return 0;
}
