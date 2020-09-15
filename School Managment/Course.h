#ifndef Included_Course_H
#define Included_Course_H
using namespace std;
class Teacher;
class Student;
class Course
{
private:
    string courseName;
    int courseCode;
    int numberOfStudentsEnrolled;
    Teacher *teacher;
public:
    Course();
    Course(string, int);
    int getCourseCode();
    string getCourseName();
    int getNumberOfStudents();
    Teacher* getTeacher();
    void setNumberOfStudents(int);
    void assignTeacher(Teacher*);
    void enrollStudent(Student*);
    void deEnrollStudent(Student*);
    void IncreaseNumberOfStudentsEnrolled();
    Course operator+(Course);
    void printCourse();
};
#endif
