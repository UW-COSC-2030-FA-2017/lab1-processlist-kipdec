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
using std::stod;
using std::endl;
using std::fixed;



// Variable Declaration

double first;       // The first number in the file
double last;        // The last number in the file
int count;          // A count of how many numbers have been processed

// Main program

int main() {
    string filename;        // The filename used by the file
    ifstream numberFile;    // This will hold the stream from the filename
    count = 0;
    
    cout << "Filename? ";
    getline( cin, filename);
    cout << "Opening " << "'" << filename << "'..." << endl;
    numberFile.open(filename.c_str());  // To open a file via filename, a string must be converted to a c-string.
    if(!numberFile){            // This checks to make sure that the file is open.
        cout << "File did not open. Check your working directory, filename and try again!" << endl;
        exit(EXIT_FAILURE);     // If it doesn't work, exit.
    }
    
    cout << "Reading file..." << endl;
    
    numberFile >> first;        // Read in the first number.
    
    while(!numberFile.fail()){
        count++;                // Increases the count. .fail() runs one more time than necessary unlike .eof()
        numberFile >> last;     // Reads to the last variable we created. Ensures that the last number read is stored.
    }
    
    cout << "The first number was " << first << endl;
    cout << "The last number was " << last << endl;
    cout << "The count of numbers in the file was " << count << endl;
    
    
}


