//
//  main.cpp
//  Lab01
//  This lab reads and counts the number of numbers in a file seperated by whitespace.
//  Created by Kip DeCastro on 9/11/17.
//  Copyright © 2017 Kip DeCastro. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using namespace std;




// Variable Declaration

double first;       // The first number in the file
double second;      // The second number in the file
double penultimate; // The penultimate number in the file
double last;        // The last number in the file
int c;              // A count of how many numbers have been processed

// Main program

int main() {
    string filename;        // The filename used by the file.
    ifstream numberFile;    // This will hold the stream from the filename.
    c = 0;                  // Initializing the count.

    cout << "Filename? ";
    getline( cin, filename);
    cout << "Opening " << "'" << filename << "'..." << endl;
    numberFile.open(filename.c_str());  // To open a file via filename, a string must be converted to a c-string.
    if(!numberFile){            // This checks to make sure that the file is open.
        cout << "File did not open. Check your working directory, filename and try again!" << endl;
        exit(EXIT_FAILURE);     // If it doesn't work, exit.
    }
    
    cout << "Reading file..." << endl;
    
    if(numberFile >> first){
        c++;                    // Increase the count by one if successfully read.
        last = first;           // The last number in file containing one number
                                // is the same as the first...
    }

    if(numberFile >> second) {
        c++;                    
    }

    while(!numberFile.eof()){               
        if(numberFile >> penultimate){
            c++;
        } else if(c == 2) { 
            penultimate = first;    // The penultimate number in a file containing
        }                           // 2 numbers is the first number.
        if(numberFile >> last){
            c++;
        } else if(c == 2){          // The last number in a file containing 2
            last = second;          // numbers is the second number.
        } else {
            last = penultimate;     // The last number in a file containing
                                    // 3 numbers would be the third number,
                                    // which would record as the penultimate.
            penultimate = second;   // The true penultimate number in a file 
        }                           // containing 3 numbers would be the second.
    }

    cout << "The first number was " << first << endl;
    cout << "The second number was " << second << endl;
    cout << "The penultimate number was " << penultimate << endl;
    cout << "The last number was " << last << endl;
    cout << "The count of numbers in the file was " << c << endl;
    
    
}


