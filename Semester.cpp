#include "Semester.h"

void Semester::addSubject(std::string pCourseName, double pGrade, int pCredits)
{
    CourseInfo newCourse(pCourseName, pGrade, pCredits);
    Courses.push_back(newCourse); // Adds a new course object to the Semester's courses vector
    calculateSemesterGradePoints();
    calculateSemesterTotalCredits();
}

void Semester::calculateSemesterGradePoints()
{
    semesterGradePoints = 0;

    for (std::vector<CourseInfo>::iterator i = Courses.begin(); i != Courses.end(); ++i) // Iterates through the Courses vector to calculate the total semester's total grade points
    {
        semesterGradePoints += i->getCoursePoints();
    }

    //semesterGradePoints = std::ceil(semesterGradePoints * 100.0) / 100.0;
}

void Semester::calculateSemesterTotalCredits()
{
    semesterTotalCredits = 0;

    for (std::vector<CourseInfo>::iterator i = Courses.begin(); i != Courses.end(); ++i) // Iterates through the Courses vector to calculate the total semester's total credit amount
    {
        semesterTotalCredits += i->getCredits();
    }
}

double Semester::getSemesterGradePoints()
{
    return semesterGradePoints;
}

double Semester::getSemesterTotalCredits()
{
    return semesterTotalCredits;
}
