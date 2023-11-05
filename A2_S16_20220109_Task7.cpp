/*
File:A2_S16_20220109_Task7.cpp
Purpose: To check whether the domino rectangles can connect with each other or not
Author: Hussam Eldin Hesham Ahmed
Section: S16
ID: 20220109
TA: Mohamed Talaat
Date: 25 Oct 2023
*/



#include <iostream>
#include <vector>

using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

// Function to find a domino chain recursively
bool FormsDominoChain(vector<dominoT> &dominos, vector<dominoT> &chain) {
    if (chain.empty()) {
        for (size_t i = 0; i < dominos.size(); i++) {
            vector<dominoT> newChain = {dominos[i]};
            vector<dominoT> newDominos = dominos;
            newDominos.erase(newDominos.begin() + i);
            if (FormsDominoChain(newDominos, newChain)) {
                chain = newChain;
                return true;
            }
        }
    } else {
        int rightDots = chain.back().rightDots;
        for (size_t i = 0; i < dominos.size(); i++) {
            if (dominos[i].leftDots == rightDots) {
                chain.push_back(dominos[i]);
                vector<dominoT> newDominos = dominos;
                newDominos.erase(newDominos.begin() + i);
                if (FormsDominoChain(newDominos, chain)) {
                    return true;
                }
                chain.pop_back();
            }
        }
    }
    return dominos.empty();
}

// Function to print the domino chain
void PrintDominoChain(const vector<dominoT> &chain) {
    for (const dominoT &domino : chain) {
        cout << domino.leftDots << "|" << domino.rightDots << " - ";
    }
    cout << endl;
}

int main() {
    vector<dominoT> dominoSet = {
            {2, 6},
            {6, 1},
            {1, 4},
            {4, 4},
            {4, 3}
    };

    vector<dominoT> chain;
    if (FormsDominoChain(dominoSet, chain)) {
        cout << "Domino Chain: ";
        PrintDominoChain(chain);
    } else {
        cout << "No valid domino chain found." << endl;
    }

    return 0;
}
