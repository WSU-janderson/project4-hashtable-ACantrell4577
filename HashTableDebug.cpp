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
    hashTable.insert("6", 30);
    hashTable.insert("7", 40);
    hashTable.insert("8", 50);
    hashTable.insert("9", 60);
    hashTable.insert("10", 70);
    hashTable.insert("11", 80);

    cout << "Inserts Done" << endl;
    cout << hashTable << endl;
    cout << endl << "Removing: 5, 10, 15" << endl << endl;

    hashTable.remove("5");
    hashTable.remove("10");
    hashTable.remove("15");

    cout << hashTable << endl;

    cout << "Contains: 5 " << hashTable.contains("5") << endl;
    cout << "Contains: 6 " << hashTable.contains("6") << endl;


    optional<size_t> num = hashTable.get("6");

    if (num.has_value()) {
        cout << "Get 6: " << *num << endl;
    }
    else {
        cout << "Get 6 not found" << endl;
    }

    num = hashTable.get("15");
    if (num.has_value()) {
        cout << "Get 15: " << *num << endl;
    }
    else {
        cout << "Get 15 not found" << endl;
    }

    cout << "Finding using [6]" << hashTable["6"] << endl;

    cout << endl << "Keys: ";

    vector<string> keys = hashTable.keys();

    for (int i = 0; i < keys.size(); i++) {
        cout << keys[i] << " ";
    }
    cout << endl;
    return 0;
}