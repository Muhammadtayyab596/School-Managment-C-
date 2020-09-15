#include<iostream>
#include"Course.h"
#include"Teacher.h"
Course::Course()
{
    teacher = nullptr;
}
Course::Course(string name, int code)
{
    numberOfStudentsEnrolled = 0;
    courseName = name;
    courseCode = code;
    teacher = nullptr;
}
void Course::IncreaseNumberOfStudentsEnrolled()
{
    numberOfStudentsEnrolled++;
}
int Course::getCourseCode()
{
    return courseCode;
}
string Course::getCourseName()
{
    return courseName;
}

void Course::enrollStudent(Student* s)
{
    if(s->getNumberOfCourses() == 3)
    {
        cout << "\nAttempting to enroll " << s->getName() << " in " << courseName << "............\n";
        cout << "CANNOT ENROLL IN MORE COURSES!!!!" << endl;
    }
    else
    {
        s->enroll(this);
    }
}
void Course::deEnrollStudent(Student* s)
{
    cout << "\nAttempting to de-enroll " << s->getName() << " from " << courseName << "............\n";
    int found = -1;
    Course *temp = s->getCourses();
    for(int i = 0; i < s->getNumberOfCourses(); i++)
    {
        if(temp[i].courseCode == courseCode)
        {
            found = i;
            //cout << s->getName() << " has been de-enrolled from " << courseName << endl << endl;
            break;
        }
    }
    if(found == -1)
    {
        cout << s->getName() << " was not enrolled in " << courseName << endl << endl;
    }
    else
    {
        for(int i = found; i < s->getNumberOfCourses(); i++)
        {
            if(i == s->getNumberOfCourses()-1)
                continue;
            else
                temp[i] = temp[i+1];
        }
        s->setNumberOfCourses(s->getNumberOfCourses()-1);
        numberOfStudentsEnrolled--;
        cout << s->getName() << " has been de-enrolled from " << courseName << endl << endl;
    }
}
void Course::assignTeacher(Teacher* t)
{
    if(t->getNumberOfCourses() == 2)
    {
        cout << "\nAttempting to assign " << t->getName() << " the course of " << courseName << "............\n";
        cout << t->getName() << " CANNOT TAKE MORE COURSES!!!!" << endl << endl;
    }
    else
    {
        teacher = t;
        teacher->addCourse(this);
    }
}
int Course::getNumberOfStudents()
{
    return numberOfStudentsEnrolled;
}
void Course::setNumberOfStudents(int v)
{
    numberOfStudentsEnrolled = v;
}
Teacher* Course::getTeacher()
{
    return teacher;
}
Course Course::operator+(Course argC)
{
    string tempName = this->courseName + " & " + argC.getCourseName();
    int tempCode = (this->courseCode*10) + argC.getCourseCode()%100;
    int tempNumberOfStudentsEnrolled = this->numberOfStudentsEnrolled + argC.getNumberOfStudents();

    string tempTeacher = this->teacher->getName() + " & " + argC.getTeacher()->getName();

    Teacher *tt = new Teacher(tempTeacher, "13-12-1945","Malir, Karachi", 684, "03453564345", "newOne@smiu.edu.pk");

    Course temp(tempName, tempCode);
    temp.setNumberOfStudents(tempNumberOfStudentsEnrolled);
    temp.teacher = tt;

    return temp;
}
void Course::printCourse()
{
    cout << endl << "\t\t\t" << "**********Course's Data**************" << endl;
    cout << "\t\t\tCourse Code: " << courseCode << endl;
    cout << "\t\t\tCourse Name: " << courseName << endl;
    cout << "\t\t\tStudents Enrolled: " << numberOfStudentsEnrolled << endl;
    if(teacher != nullptr)
        cout << "\t\t\tTeacher: " << teacher->getName() << endl;
}
