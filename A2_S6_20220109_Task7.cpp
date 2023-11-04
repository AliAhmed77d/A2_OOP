/*
File:A2_S6_20220109_Task7.cpp
Purpose: To check whether the domino rectangles can connect with each other or not
Author: Hussam Eldin Hesham Ahmed
Section: S6
ID: 20220109
TA: Mohamed Talaat
Date: 25 Oct 2023
*/



#include <iostream>
#include <vector>

struct dominoT {
    int leftDots;
    int rightDots;
};

// Function to find a domino chain recursively
bool FormsDominoChain(std::vector<dominoT> &dominos, std::vector<dominoT> &chain) {
    if (chain.empty()) {
        for (size_t i = 0; i < dominos.size(); i++) {
            std::vector<dominoT> newChain = {dominos[i]};
            std::vector<dominoT> newDominos = dominos;
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
                std::vector<dominoT> newDominos = dominos;
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
void PrintDominoChain(const std::vector<dominoT> &chain) {
    for (const dominoT &domino : chain) {
        std::cout << domino.leftDots << "|" << domino.rightDots << " - ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<dominoT> dominoSet = {
            {2, 6},
            {6, 1},
            {1, 4},
            {4, 4},
            {4, 3}
    };

    std::vector<dominoT> chain;
    if (FormsDominoChain(dominoSet, chain)) {
        std::cout << "Domino Chain: ";
        PrintDominoChain(chain);
    } else {
        std::cout << "No valid domino chain found." << std::endl;
    }

    return 0;
}
