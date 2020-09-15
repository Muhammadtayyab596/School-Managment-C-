#include"Teacher.h"

Teacher::Teacher(string n, string d, string a, int t, string p, string e)
{
    numberOfCourses = 0;
    name = n;
    dateOfBirth = d;
    address = a;
    teacherID = t;
    phoneNumber = p;
    emailAddress = e;
}
void Teacher::addCourse(Course* c)
{
    cout << "\nAttempting to assign " << name << " the course of " << c->getCourseName() << "............\n";
    if(numberOfCourses == 2)
    {
        cout << name << " CANNOT TAKE MORE COURSES!!!!" << endl << endl;
    }
    else
    {
        courses[numberOfCourses] = *c;
        numberOfCourses++;
        cout << name << " now teaches " << c->getCourseName() << endl << endl;
    }
}
void Teacher::removeCourse(Course* c)
{
    cout << "\nAttempting to Remove " << name << " from teaching " << c->getCourseName() << "............\n";
    int found = -1;
    for(int i = 0; i < numberOfCourses; i++)
    {
        if(courses[i].getCourseCode() == c->getCourseCode())
        {
            found = i;
            i = numberOfCourses;
        }
    }
    if(found != -1)
    {
        for(int i = found; i < numberOfCourses; i++)
        {
            if(found == numberOfCourses-1)
                continue;
            else
                courses[found] = courses[found+1];
        }
        numberOfCourses--;
        cout << "Course Removed" << endl;
    }
    else
    {
        cout << name << " is not teaching this course" << endl;
    }
}
void Teacher::enrollStudent(Student *s, Course* c)
{
    s->enroll(c);
}

void Teacher::printData()
{
    cout << endl << "\t\t\t" << "**********Teacher's Data**************" << endl;
    cout << "\t\t\t" << "Teacher ID: " << teacherID << endl;
    Person::printData();
    cout << "\t\t\t" << "Email Address: " << emailAddress << endl;
    cout << "\t\t\t" << "Phone Number: " << phoneNumber << endl;
    cout << "\t\t\t" << "Courses Teaching: " << numberOfCourses << endl;
    if(numberOfCourses == 0)
    {
        cout << "\t\t\t" << name << " is not Teaching any courses" << endl;
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
int Teacher::getNumberOfCourses()
{
    return numberOfCourses;
}
void Teacher::setNumberOfCourses(int num)
{
    numberOfCourses = num;
}
