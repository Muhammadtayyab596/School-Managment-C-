#ifndef Included_Person_H
#define Included_Person_H
#include<iostream>
using namespace std;
class Person
{
protected:
    string name;
    string dateOfBirth;
    string address;
public:
    static int persons;
    Person();
    Person(string, string, string);
    void setName(string);
    string getName();
    void updateAddress(string);
    void printData();
};
#endif
