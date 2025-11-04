/**
 * HashTableDebug.cpp
 *
 * Write your tests in this file
 */
#include <iostream>
#include "HashTable.h"

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;

    HashTable hashTable = HashTable();

    cout << "Table Created" << endl;

    hashTable.insert("5", 20);

    cout << "Load Factor: " << hashTable.alpha() << endl;
    cout << "Keys: " << hashTable.size() << endl;

    hashTable.insert("6", 30);
    cout << "Load Factor: " << hashTable.alpha() << endl;
    cout << "Keys: " << hashTable.size() << endl;

    hashTable.insert("7", 40);
    cout << "Load Factor: " << hashTable.alpha() << endl;
    cout << "Keys: " << hashTable.size() << endl;

    hashTable.insert("8", 80);
    cout << "Load Factor: " << hashTable.alpha() << endl;
    cout << "Keys: " << hashTable.size() << endl;
    return 0;
}