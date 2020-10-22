#include <cstdlib>
#include <time.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numReversed = 0;

    srand(time(0));
    int a = rand() % 10;
    int b = rand() % 10;
    int c = rand() % 10;
    int d = rand() % 10;
    

    if (a == 0) {
        a += 1;
    }

    while (!(a != b && a != c && a != d)) {
        
        a = rand() % 10;

        if (a == 0) { 
            a += 1;
        }
    }
    numReversed = (numReversed * 10) + a;

    while (!(b != c && b != d)) {
        b = rand() % 10;
    }
    numReversed = (numReversed * 10) + b;

    while (!(c != d)) {
        c = rand() % 10;
    }
    numReversed = (numReversed * 10) + c;
    numReversed = (numReversed * 10) + d;
    
    //cout << "FINAL NUMBER: " << numReversed << endl;

    int myGuess = 0;
    
    int bulls = 0;
    int cows = 0;
    int turns = 0;
    
    cout << "\nGuess the 4-digit number: " << endl << endl;

    while (!(numReversed == myGuess)) {

        
        cin >> myGuess;
        if(isnan(myGuess)){
            cout << "enter a valid number!" << endl;
            break;
        }
        if(myGuess == -1) {
            cout << "You have given up! The number is " << numReversed << endl;
            break;
        }
        if (myGuess / 1000 == (myGuess / 100) % 10 || myGuess / 1000 == (myGuess / 10) % 10
            || myGuess / 1000 == myGuess % 10 || (myGuess / 100) % 10 == (myGuess / 10) % 10
            || (myGuess / 100) % 10 == myGuess % 10
            || (myGuess / 10) % 10  == myGuess % 10) {
                cout << "Number should have four different digits!" << endl;
                continue;
        }
        if (myGuess / 1000 == 0) {
            cout << "invalid num!" << endl << endl;
            continue;
        }
        
        if (numReversed == myGuess) {

            turns +=  1;
            cout << "You guessed the number on the " << turns << "-th turn!" << endl;
            break;
        }
        bulls = 0;
        cows = 0;
        turns += 1;
        
        if (a == myGuess / 1000 ){
            bulls += 1;
        }
        if (b == (myGuess / 100) % 10) {
            bulls += 1;
        }
        if (c == (myGuess / 10) % 10) {
            bulls += 1;
        }
        if (d == myGuess % 10) {
            bulls += 1;
        }
        if (a == (myGuess / 100) % 10 || a == (myGuess / 10) % 10 || a == myGuess % 10) {
            cows += 1;
        }
        if (b == myGuess / 1000 || b == (myGuess / 10) % 10 || b == myGuess % 10) {
            cows += 1;
        }
        if (c == myGuess / 1000 || c == (myGuess / 100) % 10 || c == myGuess % 10) {
            cows += 1;
        }
        if (d == myGuess / 1000 || d == (myGuess / 100) % 10 || d == (myGuess / 10) % 10) {
            cows += 1;
        }
        
        cout << "[" << turns << "]:     " << myGuess << "   :   " << "bulls: " << bulls 
        << ", cows: " << cows << endl;

        cout << "\nGuess again... " << endl << endl;
    }
    
}