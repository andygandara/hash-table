# Andres Gandara
# CSE 310 Richa
# MW 12:15PM
Hashtable: main.o HashTable.o
	g++ main.o HashTable.o -o Hashtable
main.o: main.cpp
	g++ -c main.cpp
HashTable.o: HashTable.cpp HashTable.h
	g++ -c HashTable.cpp HashTable.h
