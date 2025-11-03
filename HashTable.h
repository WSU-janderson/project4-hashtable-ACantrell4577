/**
 * HashTable.h
 */

#ifndef HashTable_H
#define HashTable_H

//includes
#include <optional>
#include <ostream>
#include <string>
#include <vector>

#include "HashTableBucket.h"

using namespace std;

class HashTable {

private:
    vector<HashTableBucket> tableData;
    size_t keyCount;
    vector<int> offsets;

public:

    //constructor
    HashTable(size_t initCapacity = 8);

    //inserts a keyvalue pair into the vector
    bool insert(const string& key, const size_t value);

    //removes key value pair from the vector
    bool remove(const string& key);

    //returns if vector contains an item with the key
    bool contains(const string& key) const;

    //gets the value of the specified key
    optional<size_t> get(const string& key) const;

    //overloads the [] operator
    size_t& operator[](const string& key);

    //returns a vector with all of the keys in the hash table
    vector<string> keys() const;

    //returns size/capacity
    double alpha() const;

    //returns total buckets
    size_t capacity() const;

    //returns total items in the hash table
    size_t size() const;

    //creates the offset vector
    void createOffsets();

    //overloads <<
    friend ostream& operator<<(ostream& os, const HashTable& hashTable);
};


#endif
