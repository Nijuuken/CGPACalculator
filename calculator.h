#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <vector>


class Calculator
{
private:
    double CGPA;
public:
    Calculator();; // Empty Constructor
    void calculateCGPA(const std::vector<double>& semesterGPAs, const std::vector<double>& semesterCredits);
    void reset();
    double getCGPA() const;
};

#endif // CALCULATOR_H
