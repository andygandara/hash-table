//
//  Andres Gandara
//  CSE 310 Richa
//  HW 4 - Hashing
//
//  HashTable.h
//
//  Created by Andy Gandara on 10/8/17.
//  Copyright © 2017 Andy Gandara. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <cmath>
#include <string>
#include <sstream>
#include <list>

using namespace std;

class HashTable
{
private:
    int size; // # of slots
    double a; // for linear hash
    list<int>** slots;
    list<int>* ptr;
    
public:
    // Constructor and deconstructor
    HashTable(int, double);
    ~HashTable();
    
    // Print method
    string print();
    
    // Chained HT insert and search
    void chainedHashInsert(int);
    int chainedHashSearch(int);
    
    // Linear HT insert and search
    void linearHashInsert(int);
    string linearHashSearch(int);
    
    // Double HT insert and search
    void doubleHashInsert(int);
    string doubleHashSearch(int);
};

#endif /* HashTable_h */


