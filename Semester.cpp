#include "Semester.h"

void Semester::addSubject(std::string pCourseName, double pGrade, int pCredits)
{
    CourseInfo newCourse(pCourseName, pGrade, pCredits);
    Courses.push_back(newCourse); // Adds a new course object to the Semester's courses vector
    calculateSemesterGradePoints();
    calculateSemesterTotalCredits();
}

void Semester::removeCourse(size_t index)
{
    // Check if the index is valid
    if (index < Courses.size()) {
        // Erase the course at the specified index
        Courses.erase(Courses.begin() + index);
    }
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

void Semester::calculateGPA()
{
    if (semesterGradePoints != 0 && semesterTotalCredits != 0)
    {
        GPA = semesterGradePoints/semesterTotalCredits;
    } else {
        GPA = 0;
    }

}

double Semester::getSemesterGradePoints() const
{
    return semesterGradePoints;
}

double Semester::getSemesterTotalCredits() const
{
    return semesterTotalCredits;
}

double Semester::getGPA() const{
    return GPA;
}

std::string Semester::getSemesterName(){
    return semester;
}
