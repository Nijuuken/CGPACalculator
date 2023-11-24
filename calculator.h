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

    void calculate();
    void reset();
    void displayGPA();
    void displayCGPA();
    bool checkOnlyIntegers(std::string);
    bool checkOnlyIntegers(double);
};

#endif // CALCULATOR_H
