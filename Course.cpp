# include "Course.h"

void CourseInfo::addCourseName(std::string pCourseName)
{
    courseName = pCourseName;
}

void CourseInfo::addGrade(double pGrade)
{
    grade = pGrade;
}

void CourseInfo::addCredits(int pCredits)
{
    credits = pCredits;
}

void CourseInfo::calculateCourseGradePoint()
{
    coursePoints = 0;

    coursePoints = grade * credits;
}

std::string CourseInfo::getCourseName()
{
    return courseName;
}

double CourseInfo::getGrade()
{
    return grade;
}

int CourseInfo::getCredits()
{
    return credits;
}

double CourseInfo::getCoursePoints()
{
    return coursePoints;
}
