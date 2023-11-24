#ifndef COURSE_H
#define COURSE_H

#include <string>

class CourseInfo
{
private:
    std::string courseName;
    double grade,
           coursePoints;
    int credits;

public:
    CourseInfo(){}; // Empty Constructor
    CourseInfo(std::string pCourseName, double pGrade, int pCredits) : courseName(pCourseName), grade(pGrade),
        coursePoints(pGrade * pCredits), credits(pCredits){}; // Default Constructor

    void addCourseName(std::string pCourseName);
    void addGrade(double pGrade);
    void addCredits(int pCredits);
    void calculateCourseGradePoint();

    std::string getCourseName();
    double getGrade();
    int getCredits();
    double getCoursePoints();

};


#endif // COURSE_H
