#include<iostream>
#include"Person.h"
using namespace std;
int Person::persons = 0;
Person::Person()
{
    Person::persons++;
}
Person::Person(string n, string d, string a)
{
    Person::persons++;
    name = n;
    dateOfBirth = d;
    address = a;
}
void Person::setName(string n)
{
    name = n;
}
string Person::getName()
{
    return name;
}
void Person::updateAddress(string a)
{
    address = a;
}
void Person::printData()
{
    //cout << "\t\t\t---------Person's Data---------" << endl;
    cout << "\t\t\tName: " << name << endl;
    cout << "\t\t\tAddress: " << address << endl;
    cout << "\t\t\tDate of Birth: " << dateOfBirth << endl;
    cout << "\t\t\t--------------------------------" << endl;
}
