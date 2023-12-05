#include "calculator.h"

Calculator::Calculator()
{

}

void Calculator::calculateCGPA(const std::vector<double>& semesterGPAs, const std::vector<double>& semesterCredits)
{
    double totalGradePoints = 0.0;
    double totalCredits = 0.0;

    // Calculate the sum of grade points and credits from all semesters
    for (size_t i = 0; i < semesterGPAs.size(); ++i)
    {
        totalGradePoints += semesterGPAs[i] * semesterCredits[i];
        totalCredits += semesterCredits[i];
    }

    // Calculate CGPA
    if (totalCredits > 0.0)
    {
        CGPA = totalGradePoints / totalCredits;
    }
    else
    {
        CGPA = 0.0;
    }
}

double Calculator::getCGPA() const
{
    return CGPA;
}
