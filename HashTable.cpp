/**
 * HashTable.cpp
 */

#ifndef HASH_TABLE_HASHTABLEBUCKET_H
#define HASH_TABLE_HASHTABLEBUCKET_H

#include "HashTable.h"

#include <optional>
#include <string>
#include <vector>

using namespace std;

HashTable::HashTable(size_t initCapacity) {

    for (size_t i = 0; i < initCapacity; i++) {

        this->tableData.push_back(HashTableBucket());

    }
}

bool HashTable::insert(const string &key, const size_t value) {

}

bool HashTable::remove(const string &key) {

}

bool HashTable::contains(const string &key) const {

}

optional<size_t> HashTable::get(const string &key) const {

}

size_t &HashTable::operator[](const string &key) {

    for (size_t i = 0; i < this->tableData.size(); i++) {
        if (this->tableData[i].getKey() == key) {
            return this->tableData[i]->getValue();
        }
    }

}

vector<string> HashTable::keys() const {

}

double HashTable::alpha() const {

}

size_t HashTable::capacity() const {

}

size_t HashTable::size() const {

}

ostream &operator<<(ostream &os, const HashTable &obj) {


}

#endif
