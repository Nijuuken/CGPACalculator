#ifndef SEMESTER_H
#define SEMESTER_H

#include <vector>
#include <string>
#include <Course.h>
#include <cmath>

class Semester
{
private:
    std::string semester;
    std::vector <CourseInfo> Courses;
    double semesterGradePoints;
    double semesterTotalCredits;

public:
    Semester(){};
    Semester(std::string pSemester) : semester(pSemester){};
    void addSubject(std::string pCourseName, double pGrade, int pCredits);

    void calculateSemesterGradePoints();
    void calculateSemesterTotalCredits();
    double getSemesterGradePoints();
    double getSemesterTotalCredits();
    std::string getSemesterName();
};

#endif // SEMESTER_H
