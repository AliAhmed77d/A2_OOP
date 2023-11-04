#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<string, int> phishingTerms = {
            {"bank", 3}, {"credit", 3}, {"password", 3}, {"account", 3},
            {"social", 3}, {"update", 2}, {"validate", 2}, {"verify", 2},
            {"login", 2}, {"urgent", 2}, {"immediately", 2}, {"suspend", 2},
            {"confirm", 2}, {"fraud", 2}, {"phishing", 3}, {"www", 1},
            {"http", 1}, {"https", 1}, {"click", 2}, {"secure", 2},
            {"personal", 2}, {"information", 2}, {"paypal", 3}, {"ebay", 3},
            {"amazon", 3}, {"irs", 3}, {"irs.gov", 3}, {"lottery", 3}
    };

    string inputText = "Your input text goes here.";

    int total = 0;
    unordered_map<string, int> termOccurrences;

    for (const auto& term : phishingTerms) {
        size_t found = inputText.find(term.first);
        while (found != std::string::npos) {
            total += term.second;
            termOccurrences[term.first]++;
            found = inputText.find(term.first, found + 1);
        }
    }

    for (const auto& term : termOccurrences) {
        cout << term.first << " - Occurrences: " << term.second << ", Points: " << term.second * phishingTerms[term.first] << endl;
    }

    cout << "Total Points: " << total << endl;

    return 0;
}