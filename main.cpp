//
//  Andres Gandara
//  CSE 310 Richa
//  HW 4 - Hashing
//
//  main.cpp
//
//  Created by Andy Gandara on 10/8/17.
//  Copyright © 2017 Andy Gandara. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "HashTable.h"
using namespace std;

int main(int argv, char** argc) {
    if(argv != 2) {
        cout << "Error: Include the name of the input file as an argument.\n";
        return 0;
    }
    cout << "Attempting to open file " << argc[1] << ".\n";
    string file = argc[1];
    int p = 0; // Size of hash table
    int n = 0; // Number of inputs
    int key = 0; // Key element to search
    double alpha = 0.0; // Alpha value for linear hashing
    HashTable *chainedHT, *linearHT, *doubleHT;
    int *k;
    cout << "Attempting to read input file " << file.c_str() << ".\n";
    
    ifstream inFile;
    inFile.open(file.c_str(), ios::in);
    if (!inFile.is_open()) {
        cout << "Cannot open file.\n";
        inFile.close();
        return 0;
    }
    
    // Reading values for p, alpha, and n
    inFile >> p;
    inFile >> alpha;
    inFile >> n;
    
    // Allocate pointer k according to number of inputs
    k = new int[n];
    for (int i = 0; i < n; i++) {
        inFile >> k[i];
    }
    
    // Read key to search for
    inFile >> key;
    
    // Close file
    cout << "Closing file.\n";
    inFile.close();
    
    cout << "p = " << p << ", a = " << alpha << ", n = " << n << ", s = " << key << endl;
    cout << "Keys[" << n << "]\n";
    for (int i = 0; i < n; i++) {
        cout << k[i] << " ";
    }
    cout << endl;
    
    // Initialize hash tables
    chainedHT = new HashTable(p, alpha);
    linearHT = new HashTable(p, alpha);
    doubleHT = new HashTable(p, alpha);
    ofstream fileStream;
    string output;
    
    //********************
    // Chained Hash Table
    //********************
    cout << "Chained Hash Table: (chained-output.txt)" << endl;
    
    // Open file
    fileStream.open("chained-output.txt", ios::out | ios::trunc);
    if(!fileStream.is_open()) {
        cout << "Error: Could not open chained-output.txt for writing\n";
        return 0;
    }
    
    // Insert
    for(int i = 0; i < n; i++)
        chainedHT->chainedHashInsert(k[i]);
    output = chainedHT->print();
    cout << chainedHT->print();
    fileStream << output;
    
    // Search
    int foundKey = chainedHT->chainedHashSearch(key);
    cout << foundKey << endl;
    fileStream << foundKey << endl;
    
    // Close file
    fileStream.close();
    
    //*******************
    // Linear Hash Table
    //*******************
    cout << "\nLinear Hash Table: (linear-output.txt):" << endl;
    
    // Open file
    fileStream.open("linear-output.txt", ios::out | ios::trunc);
    if(!fileStream.is_open()) {
        cout << "Error: Could not open linear-output.txt for writing\n";
        return 0;
    }
    
    // Insert
    for(int i = 0; i < n; i++)
        linearHT->linearHashInsert(k[i]);
    output = linearHT->print();
    cout << output;
    fileStream << output;
    
    // Search
    output = linearHT->linearHashSearch(key);
    cout << output << endl;
    fileStream << output << endl;
    
    // Close file
    fileStream.close();
    
    //*******************
    // Double Hash Table
    //*******************
    cout << "\nDouble Hash Table: (double-output.txt)" << endl;
   
    // Open file
    fileStream.open("double-output.txt", ios::out | ios::trunc);
    if(!fileStream.is_open()) {
        cout << "Error: Could not open double-output.txt for writing\n";
        return 0;
    }
    
    // Insert
    for(int i = 0; i < n; i++)
        doubleHT->doubleHashInsert(k[i]);
    output = doubleHT->print();
    cout << output;
    fileStream << output;
    
    // Search
    output = doubleHT->doubleHashSearch(key);
    cout << output << endl;
    fileStream << output << endl;
    
    //Close file
    fileStream.close();
    
    // Deconstruct HashTables
    delete chainedHT;
    delete linearHT;
    delete doubleHT;
    delete [] k;
    
    return 0;
    
    
}
