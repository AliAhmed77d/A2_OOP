/*
File: A2_S6_20220109_Task1.cpp
Purpose: To organize the sentence and remove any extras
Author: Hussam Eldin Hesham Ahmed
Section: S6
ID: 20220109
TA: Mohamed Talaat
Date: 25 Oct 2023
*/


#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int MAX_SENTENCE_LENGTH = 100;

    char sentence[MAX_SENTENCE_LENGTH];

    char correctedSentence[MAX_SENTENCE_LENGTH];

    char previousChar = ' ';

    int correctedIndex = 0;

    cout << "Enter a sentence (up to 100 characters): ";
    cin.getline(sentence, MAX_SENTENCE_LENGTH, '.');

    for (int i = 0; sentence[i] != '\0'; i++)
    {

        if (isspace(sentence[i]) || sentence[i] == '\n')
        {

            // To remove extra spaces
            if (previousChar != ' ') {

                correctedSentence[correctedIndex++] = ' ';

            }

        }
        else
        {

            if (correctedIndex == 0)
            {

                // Capitalize the first letter
                correctedSentence[correctedIndex++] = toupper(sentence[i]);

            }
            else
            {

                // Convert the rest of the letters to lowercase
                correctedSentence[correctedIndex++] = tolower(sentence[i]);

            }

        }

        previousChar = sentence[i];

    }

    correctedSentence[correctedIndex] = '.';
    correctedSentence[correctedIndex + 1] = '\0';

    cout << "\nCorrected sentence: " << correctedSentence << endl;

    return 0;
}
