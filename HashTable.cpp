//
//  Andres Gandara
//  CSE 310 Richa
//  HW 4 - Hashing
//
//  HashTable.cpp
//
//  Created by Andy Gandara on 10/8/17.
//  Copyright © 2017 Andy Gandara. All rights reserved.
//

#include "HashTable.h"


using namespace std;

//*************
// Constructor
//*************
HashTable::HashTable(int size, double a) {
    this->size = size;
    this->a = a;
    
    // Alocate slots according to parameter
    slots = new list<int>*[size];
    
    // Initialize each slot as an int list
    for (int i = 0; i < size; i++) {
        ptr = new list<int>;
        slots[i] = ptr;
    }
}

//***************
// Deconstructor
//***************
HashTable::~HashTable() {
    if(slots != NULL) {
        for(int i = 0; i < size; i++) {
            if(slots[i] != NULL)
                delete slots[i];
        }
        delete slots;
    }
    slots = NULL;
 }

//******************
// Print hash table
//******************
string HashTable::print() {
    stringstream ss;
    list<int>::iterator it;
    for (int i = 0; i < size; i++) {
        ptr = slots[i];
        it = ptr->begin();
        ss << i << ": ";
        while (it != ptr->end()) {
            ss << *it << " ";
            it++;
        }
        ss << endl;
    }
    return ss.str();
}

//****************
// Chained insert
//****************
void HashTable::chainedHashInsert(int k) {
    int hash = k % size;
    ptr = slots[hash]; // Points to slot at hash
    slots[hash]->push_front(k); // Add to front of list
}

//****************
// Chained search
//****************
int HashTable::chainedHashSearch(int k) {
    int hash = k % size;
    ptr = slots[hash]; // Points to slot at hash
    list<int>::iterator it = ptr->begin();
    while (it != ptr->end()) {
        if (*it == k) // Key found
            return hash;
        it++;
    }
    
    // Not found
    return -1;
}

//***************
// Linear insert
//***************
void HashTable::linearHashInsert(int k) {
    int hash = 0;
    for (int i = 0; i < size; i++) {
        hash = (int)fmod((floor(size * (fmod((a * k), 1))) + i), size);
        ptr = slots[hash]; // Points to slot at hash
        if(ptr->empty() == true) { // Slot is empty
            ptr->push_front(k);
            return;
        }
    }
}

//***************
// Linear search
//***************
string HashTable::linearHashSearch(int k) {
    stringstream ss;
    int hash = 0;
    for (int i = 0; i < size; i++) {
        hash = (int)fmod((floor(size * (fmod((a * k), 1))) + i), size);
        ss << hash << " ";
        ptr = slots[hash]; // Points to slot at hash
        if (ptr->front() == k) // Key found
            break;
    }
    return ss.str();
}

//***************
// Double insert
//***************
void HashTable::doubleHashInsert(int k) {
    int hash = 0;
    for (int i = 0; i < size; i++) {
        hash = ((k % size) + i * (1 + (k % (size - 2)))) % size;
        ptr = slots[hash]; // Points to slot at hash
        if (ptr->empty() == true) { // Slot is empty
            ptr->push_front(k);
            return;
        }
    }
}

//***************
// Double search
//***************
string HashTable::doubleHashSearch(int k) {
    stringstream ss;
    int hash = 0;
    for (int i = 0; i < size; i++) {
        hash = ((k % size) + i * (1 + (k % (size - 2)))) % size;
        ss << hash << " ";
        ptr = slots[hash]; // Points to slot at hash
        if (ptr->front() == k) // Key found
            break;
    }
    return ss.str();
}




