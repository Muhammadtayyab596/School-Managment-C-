#ifndef Included_Student_H
#define Included_Student_H

#include"Person.h"
#include"Course.h"

using namespace std;
class Student : public Person
{
private:
    int studentID;
    int numberOfCourses;
    Course courses[3];
    string phoneNumber;
    string emailAddress;
public:
    Student(string, string, string, int, string, string);
    void updateEmail(string);
    void updatePhoneNumber(string);
    void enroll(Course*);
    void printData();
    int getNumberOfCourses();
    void setNumberOfCourses(int);
    Course* getCourses();
};
#endif
