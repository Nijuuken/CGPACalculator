#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <semesterform.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAddSemester_clicked()
{
    // Create a new semesterForm instance
    semesterForm* newSemesterForm = new semesterForm(this);

    // Connect the signals and slots
    connect(newSemesterForm, &semesterForm::courseAdded, this, &MainWindow::updateSemester);

    // Add the semesterForm instance to the tabWidget
    ui->tabWidgetSemester->addTab(newSemesterForm, QString(ui->lineEditSemesterAdd->text().arg(ui->tabWidgetSemester->count() + 1)));

    // Create a new Semester instance
    std::string semesterLineText = ui->lineEditSemesterAdd->text().toStdString();
    Semester newSemester(semesterLineText);
    semesters.push_back(newSemester);

    std::cout << "Current Number of Semesters in vector: " << semesters.size() << std::endl;
}

void MainWindow::on_tabWidgetSemester_tabCloseRequested(int index)
{
    ui->tabWidgetSemester->removeTab(index);
    semesters.erase(semesters.begin()+index);
    std::cout << semesters.size() << std::endl;
}


void MainWindow::on_tabWidgetSemester_currentChanged(int index)
{
    std::cout << "Current Tab Index is: "<< index << std::endl;
}

void MainWindow::updateSemester(const QString& courseName, double grade, int credits)
{
    // Get the index of the currently selected tab
    int currentIndex = ui->tabWidgetSemester->currentIndex();

    // Convert QString to std::string
    std::string courseNameStr = courseName.toStdString();

    // Call addSubject for the selected semester
    semesters[currentIndex].addSubject(courseNameStr, grade, credits);
    std::cout << "Class: " << courseName.toStdString() << " has been added to semester " << semesters[currentIndex].getSemesterName() << std::endl;

}
