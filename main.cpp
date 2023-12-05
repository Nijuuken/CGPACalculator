#include "mainwindow.h"
#include "Semester.h"
#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Semester testSemester("Winter 2022");
    testSemester.addSubject("CIS 376", 3.6, 3);
    testSemester.addSubject("CIS 450", 2.7, 4);
    std::cout<<"HELLOWORLD"<<std::endl;
    return a.exec();
}
