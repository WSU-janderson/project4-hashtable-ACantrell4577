/**
 * HashTable.cpp
 */

#ifndef HASH_TABLE_HASHTABLE_H
#define HASH_TABLE_HASHTABLE_H

#include "HashTable.h"

#include <chrono>
#include <optional>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;

//creates the hash table
HashTable::HashTable(size_t initCapacity) {

    for (size_t i = 0; i < initCapacity; i++) {

        this->tableData.push_back(HashTableBucket());

    }

    this->createOffsets();
    this->keyCount = 0;

}

//inserts a key value pair into the hash table
bool HashTable::insert(const string &key, const size_t value) {


int probeValue = 0;


    //probes the hash table until an empty field is found
    for (int i = 0; i < this->offsets.size(); i++) {

        //sets the probe value to hash
        probeValue = (stoi(key) + this->offsets[i]) % this->capacity();


        //if the bucket is empty then load the data into the bucket
        if (this->tableData[probeValue].isEmpty()) {

            this->tableData[probeValue].load(key, value);


            //increases the keycount
            keyCount++;

            //if the load factor is great enough resize
            if (this->alpha() >= 0.5) {
                this->resize();
            }

            //return
            return true;
        }

        //if duplicate is found
        else if (this->tableData[probeValue].getKey() == key) {
            return false;
        }
    }

}

//removes key value pair from the hash table
bool HashTable::remove(const string &key) {

int probe = 0;

    //probes through the hash table
    for (int i = 0; i < this->offsets.size(); i++) {
        //sets probe value
        probe = (stoi(key) + this->offsets[i]) % this->capacity();

        //if the key matches
        if (this->tableData[probe].getKey() == key) {

            //remove data if the key is found
            this->tableData[probe].unload();

            //decrement the key count
            keyCount--;

            //return
            return true;
        }

        //if ESS end the loop
        else if (this->tableData[probe].getType() == "ESS") {
            i = this->offsets.size();

            //return false
            return false;
        }
    }

}

//checks to see if the the key is contained in a bucket
bool HashTable::contains(const string &key) const {

    int probe = 0;

    //probes through the hash table
    for (int i = 0; i < this->offsets.size(); i++) {
        //sets probe value
        probe = (stoi(key) + this->offsets[i]) % this->capacity();

        //if the key matches
        if (this->tableData[probe].getKey() == key) {

            //return true
            return true;
        }

        //if ESS end the loop
        else if (this->tableData[probe].getType() == "ESS") {
            i = this->offsets.size();

            //not found
            return false;
        }
    }

}

//recieves a key and returns the value
optional<size_t> HashTable::get(const string &key) const {

    int probe = 0;

    //probes through the hash table
    for (int i = 0; i < this->offsets.size(); i++) {
        //sets probe value
        probe = (stoi(key) + this->offsets[i]) % this->capacity();

        //if the key matches
        if (this->tableData[probe].getKey() == key) {

            //return the value
            return this->tableData[probe].value;
        }

        //if ESS end the loop
        else if (this->tableData[probe].getType() == "ESS") {
            i = this->offsets.size();

            //return nullopt
            return nullopt;
        }
    }

}

//searches through the hash table looking for the proper key
size_t& HashTable::operator[](const string &key) {

    //creating a found operator
    bool found = false;

    for (size_t i = 0; i < this->tableData.size(); i++) {

        //if found
        if (this->tableData[i].getKey() == key) {

            //mark found true and return the value
            found = true;
            return this->tableData[i].value;
        }
    }

    //if not found throw exception
    if (!found) {
        throw exception();
    }
}

//returns a vector of keys present in the hash table
vector<string> HashTable::keys() const {

    //creates a vector for the strings
    vector<string> keyVector;

    //itterates through the vector
    for (size_t i = 0; i < this->tableData.size(); i++) {

        //if the type is set to normal push pack on the vector adding the key
        if (this->tableData[i].getType() == "Normal") {
            keyVector.push_back(this->tableData[i].getKey());
        }

    }

    //return the vector
    return keyVector;
}

//returns load capacity
double HashTable::alpha() const {

    //casts the size and capacity to doubles and returns size/capacity as a double
    return (static_cast<double>(this->size()) / static_cast<double>(this->capacity()));


}

//returns the number of buckets in the hash table
size_t HashTable::capacity() const {

    return tableData.size();

}

//returns the number of keys inside the hash table
size_t HashTable::size() const {

return this->keyCount;

}

//creates and shuffles the offsets vector
void HashTable::createOffsets() {

    //populates the offsets vector
    for (int i = 0; i < this->tableData.size()-1; i++) {
        this->offsets.push_back(i+1);
    }

    /*CITATION
     *https://www.geeksforgeeks.org/cpp/how-to-shuffle-a-vector-in-cpp/#
     *
     *Used to learn how to use the shuffle method
    */

    //creates the random number generator
    random_device rand;
    mt19937 gen(rand());

    //shuffles the vector with inputs of (start, end, generator)
    shuffle(offsets.begin(), offsets.end(), gen);

}

//clears the table out
void HashTable::clear() {

    for (int i = 0; i < this->tableData.size(); i++) {

        this->tableData[i].resset();
        this->keyCount = 0;
    }
}

void HashTable::resize() {

    //creates temp table
    vector<HashTableBucket> hashHold;

    //copies old table to temp
    for (int i = 0; i < this->tableData.size(); i++) {
        //copies the data over to temp table
        hashHold.push_back(this->tableData[i]);
    }


    //clears out the table
    this->clear();

    //doubles the size of the table by adding a pushback for each element already inside the table while also resizing offsets
    for (int i = 0; i < hashHold.size(); i++) {



        //creates a new empty bucket
        this->tableData.push_back(HashTableBucket());

        //increases offsets
        this->offsets.push_back(0);
    }

    //repopulates offsets
    for (int i = 0; i < this->tableData.size()-1; i++) {
        this->offsets[i+1];
    }

    //reshuffles offsets
    //creates the random number generator
    random_device rand;
    mt19937 gen(rand());

    //shuffles the vector with inputs of (start, end, generator)
    shuffle(offsets.begin(), offsets.end(), gen);

    //re-adds every item in the temp table back into the main table
    for (int i = 0; i < hashHold.size(); i++) {

        //if normal
        if (hashHold[i].getType() == "Normal") {
            this->insert(hashHold[i].getKey(), hashHold[i].getValue());
        }
    }


}


ostream &operator<<(ostream &os, const HashTable &obj) {

    //itterate through the hash table
    for (int i = 0; i < obj.capacity(); i++) {

        //if type == Normal then stage the bucket
        if (obj.tableData[i].getType() == "Normal") {
            os << "Bucket " << i << ": " << obj.tableData[i] << endl;
        }
    }

    return os;

}

#endif
