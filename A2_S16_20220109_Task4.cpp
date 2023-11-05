/*
File: A2_S16_20220109_4.cpp
Purpose: To know all the prime numbers from 2 to the number
Author: Hussam Eldin Hesham Ahmed
Section: S16
ID: 20220109
TA: Mohamed Talaat
Date: 25 Oct 2023
*/


#include <iostream>
#include <vector>

using namespace std;



void is_prime(int number)
{

    vector<bool> isPrime(number + 1, true);

    isPrime[0] = isPrime[1] = false; // To make sure that 0 and 1 are not prime

    for (int j = 2; j * j <= number; j++)// looping through potential prime numbers from 2 to the square root of number
    {

        if (isPrime[j])// If j is marked as prime
        {

            // Mark all multiples of j as non-prime
            for (int i = j * j; i <= number; i += j)
            {

                isPrime[i] = false;

            }

        }

    }


    cout << "\nPrime numbers between 2 and " << number << " are:\n\n( ";

    //output the new list
    for (int i = 2; i <= number; i++)
    {

        if (isPrime[i])
        {

            cout << i << ", ";

        }

    }

    cout<<")"<<endl;

}

int main() {

    int number;

    cout << "Enter a number (n) to find all prime numbers between 2 and n: ";
    cin >> number;

    if (number >= 2)
    {

        is_prime(number);


    }
    else
    {

        cout << "\nPlease enter a number bigger than or equal to 2.\n" << endl;
        main();

    }

    return 0;
}

