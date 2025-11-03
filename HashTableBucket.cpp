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

//removes item from bucket
void HashTableBucket::unload() {

    this->type = "EAR";
    this->key = "";
    this->value = 0;

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

    //Stages the buckets print
    os << "<" + bucket.getKey() + ", " + to_string(bucket.getValue()) + ">";

    return os;

}

//getter for the bucket's key
string HashTableBucket::getKey() const {
    return this->key;
}

//returns the bucket's type
string HashTableBucket::getType() const {
    return this->type;
}

//getter for bucket's value
size_t HashTableBucket::getValue() const {
    return this->value;
}

//setter for key
void HashTableBucket::setKey(const string& key) {
    this->key = key;
}

//setter for type
void HashTableBucket::setType(const string& type) {
    this->type = type;
}

void HashTableBucket::resset() {
    this->type = "EES";
    this->value = 0;
    this->key = "";
}


#endif