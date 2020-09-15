#ifndef Included_Teacher_H
#define Included_Teacher_H
#include"Person.h"
#include"Student.h"
#include"Course.h"
using namespace std;
class Teacher : public Person
{
private:
    int teacherID;
    string phoneNumber;
    string emailAddress;
    Course courses[2];
    int numberOfCourses;
public:
    Teacher(){}
    Teacher(string, string, string, int, string, string);
    void addCourse(Course*);
    void removeCourse(Course*);
    void enrollStudent(Student*, Course*);
    void printData();
    int getNumberOfCourses();
    void setNumberOfCourses(int);
};
#endif
