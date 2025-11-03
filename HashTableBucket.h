//
// Created by avery on 11/3/2025.
//

#ifndef HASHTABLE_HASHTABLEBUCKET_H
#define HASHTABLE_HASHTABLEBUCKET_H
#include <string>

using namespace std;


class HashTableBucket {

private:
    string type;
    string key;

public:

    size_t value;

    //default constructor
    HashTableBucket() : type("ESS"), key(""), value(0){};

    //overloaded constructor
    HashTableBucket(const size_t value, string key) : type("Normal"), key(key), value(value){};

    //inserts into the bucket
    void load(const string& key, const size_t& value);

    //removes from bucket
    void unload();

    //returns if bucket is empty
    bool isEmpty() const;

    //ressets bucket
    void resset();

    //getters and setters
    string getKey() const;
    void setKey(const string& key);
    size_t getValue() const;
    string getType() const;
    void setType(const string& type);

    friend ostream& operator<<(ostream& os, const HashTableBucket& bucket);
};

#endif //HASHTABLE_HASHTABLEBUCKET_H