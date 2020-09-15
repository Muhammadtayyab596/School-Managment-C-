#include<iostream>
#include"Student.h"
Student::Student(string n, string d, string a, int s, string p, string e)
{
    numberOfCourses = 0;
    name = n;
    dateOfBirth = d;
    address = a;
    studentID = s;
    phoneNumber = p;
    emailAddress = e;
}
void Student::updatePhoneNumber(string p)
{
    phoneNumber = p;
}
void Student::updateEmail(string e)
{
    emailAddress = e;
}
void Student::enroll(Course *c)
{
    cout << "\nAttempting to enroll " << name << " in " << c->getCourseName() << "............\n";
    if(numberOfCourses == 3)
    {
        cout << "CANNOT ENROLL IN MORE COURSES!!!!" << endl;
    }
    else
    {
        c->IncreaseNumberOfStudentsEnrolled();
        courses[numberOfCourses] = *c;
        numberOfCourses++;
        cout << name << " has been enrolled in " << c->getCourseName() << endl;
    }
}
void Student::printData()
{
    cout << endl << "\t\t\t" << "**********Student's Data**************" << endl;
    cout << "\t\t\t" << "Student ID: " << studentID << endl;
    Person::printData();
    cout << "\t\t\t" << "Email Address: " << emailAddress << endl;
    cout << "\t\t\t" << "Phone Number: " << phoneNumber << endl;
    cout << "\t\t\t" << "***********" << name << "'s Courses***********" << endl;
    if(numberOfCourses == 0)
    {
        cout << "\t\t\t" << name << "is not Enrolled in any courses" << endl;
    }
    else
    {
        int i = 0;
        while(i < numberOfCourses)
        {
            cout << "\t\t\t" << courses[i].getCourseCode() << "\t" << courses[i].getCourseName() << endl;
            i++;
        }
        cout << endl;
    }
}

int Student::getNumberOfCourses()
{
    return numberOfCourses;
}
void Student::setNumberOfCourses(int num)
{
    numberOfCourses = num;
}
Course* Student::getCourses()
{
    return courses;
}
