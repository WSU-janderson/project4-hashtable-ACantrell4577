//
// Created by avery on 11/3/2025.
//

#ifndef HASH_TABLE_BUCKET_H
#define HASH_TABLE_BUCKET_H

#include "HashTableBucket.h"
#include <string>

using namespace std;

//inserts into the bucket
void HashTableBucket::load(const string& key, const size_t& value) {

    this->key = key;
    this->value = value;
    this->type = "Normal";

}

//returns true if bucket isnt Normal
bool HashTableBucket::isEmpty() const {

    if (this->type == "Normal") {
        return false;
    }
    else {
        return true;
    }

}

//overloads friend operator <<
ostream& operator<<(ostream& os, const HashTableBucket& bucket) {

}

//getter for the bucket's key
string HashTableBucket::getKey() const {
    return this->key;
}

//getter for bucket's value
size_t HashTableBucket::getValue() const {
    return this->value;
}

#endif