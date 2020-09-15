#include <iostream>
#include"Student.h"
#include"Teacher.h"
using namespace std;

int main()
{
    Course anthro("Anthropology", 101);
    Course bio("Biology", 102);
    Course cp("Computer Programming", 103);
    Course da("Data Analysis", 104);
    Course eco("Economics", 105);
    Course fin("Financing", 106);
    Course gd("Game Development", 107);


    Student anwar("Anwar", "16-05-1999","PECHS, Karachi", 111, "03456732451", "emailtoanwar@gmail.com");
    Student amaan("Amaan", "16-05-1999","PECHS, Karachi", 121, "03456732451", "emailtoamaan@gmail.com");
    Student behroze("Behroze", "23-05-1999","PECHS, Karachi", 131, "03456732451", "emailtobehroze@gmail.com");

    Teacher zubairT("Zubair", "23-07-1991","Garden, Karachi", 682, "03123452345", "zubair@smiu.edu.pk");
    Teacher ayeshaT("Ayesha", "11-07-1980","Malir, Karachi", 683, "03123564345", "ayesha@smiu.edu.pk");

    anwar.enroll(&anthro);
    anwar.enroll(&bio);
    anwar.enroll(&cp);
    anwar.enroll(&gd);

    amaan.enroll(&eco);
    amaan.enroll(&gd);
    amaan.enroll(&anthro);

    cp.deEnrollStudent(&anwar);
    gd.enrollStudent(&anwar);

    anwar.printData();
    //amaan.printData();

    //anthro.printCourse();
    //gd.printCourse();
    //bio.printCourse();
    //eco.printCourse();

    gd.assignTeacher(&zubairT);
    cp.assignTeacher(&ayeshaT);
    Course gdcp = gd + cp;

    gd.printCourse();
    zubairT.printData();

    cp.printCourse();
    //ayeshaT.printData();

    gdcp.printCourse();

    return 0;
}
