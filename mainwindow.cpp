#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <semesterform.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("CGPA Calculator");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAddSemester_clicked()
{
    // Check if lineEditSemesterAdd is not empty
       if (ui->lineEditSemesterAdd->text().isEmpty()) {
           QMessageBox::warning(this, "Error", "Please enter a semester name.");
           return;
       }
    // Create a new semesterForm instance
    semesterForm* newSemesterForm = new semesterForm(this);

    // Connect the signals and slots
    connect(newSemesterForm, &semesterForm::courseAdded, this, &MainWindow::addCoursetoSemester);
    connect(newSemesterForm, &semesterForm::courseDeleted, this, &MainWindow::delCoursefromSemester);

    // Add the semesterForm instance to the tabWidget
    ui->tabWidgetSemester->addTab(newSemesterForm, QString(ui->lineEditSemesterAdd->text().arg(ui->tabWidgetSemester->count() + 1)));

    // Create a new Semester instance
    std::string semesterLineText = ui->lineEditSemesterAdd->text().toStdString();
    Semester newSemester(semesterLineText);
    semesters.push_back(newSemester);
    // Clear the input field for the semester name
    ui->lineEditSemesterAdd->clear();
    std::cout << "Current Number of Semesters in vector: " << semesters.size() << std::endl;
}

void MainWindow::on_tabWidgetSemester_tabCloseRequested(int index)
{
    ui->tabWidgetSemester->removeTab(index);
    semesters.erase(semesters.begin()+index);
    std::cout << semesters.size() << std::endl;
    updateCGPA();
}


void MainWindow::on_tabWidgetSemester_currentChanged(int index)
{
    std::cout << "Current Tab Index is: "<< index << std::endl;
}

void MainWindow::updateCGPA()
{
    // You would need to collect the GPAs and credits for all semesters and call the Calculator
    std::vector<double> semesterGPAs;
    std::vector<double> semesterCredits;

    for (const auto& semester : semesters) {
        semesterGPAs.push_back(semester.getGPA());
        semesterCredits.push_back(semester.getSemesterTotalCredits());
    }

    calculator.calculateCGPA(semesterGPAs, semesterCredits);
    double cgpa = calculator.getCGPA();
    cgpa = round(cgpa * 100.0) / 100.0;
    ui->labelCGPA->setText(QString("CGPA: %1").arg(cgpa));
}

void MainWindow::addCoursetoSemester(const QString& courseName, double grade, int credits)
{
    // Get the index of the currently selected tab
    int currentIndex = ui->tabWidgetSemester->currentIndex();

    // Convert QString to std::string
    std::string courseNameStr = courseName.toStdString();

    // Call addSubject for the selected semester
    semesters[currentIndex].addSubject(courseNameStr, grade, credits);

    // Update semesterGradePoints and semesterTotalCredits
    semesters[currentIndex].calculateSemesterGradePoints();
    semesters[currentIndex].calculateSemesterTotalCredits();

    // Calculate GPA after updating semesterGradePoints and semesterTotalCredits
    semesters[currentIndex].calculateGPA();

    // Fetch the corresponding semesterForm
    semesterForm* currentSemesterForm = qobject_cast<semesterForm*>(ui->tabWidgetSemester->widget(currentIndex));

    if (currentSemesterForm) {
        // Update GPA and display it in the corresponding semesterForm
        double roundedGPA = round(semesters[currentIndex].getGPA() * 100.0) / 100.0;  // Round to the hundredth place
        QString gpaText = QString("GPA: %1").arg(QString::number(roundedGPA, 'f', 2));
        currentSemesterForm->setSemesterGPAText(gpaText);
    }

    updateCGPA();
}

void MainWindow::delCoursefromSemester(int rowIndex)
{
    // Get the current selected tab index
    int currentIndex = ui->tabWidgetSemester->currentIndex();

    // Fetch the corresponding semesterForm
    semesterForm* currentSemesterForm = qobject_cast<semesterForm*>(ui->tabWidgetSemester->widget(currentIndex));

    if (currentSemesterForm) {
        // Remove the course from the corresponding semester using the rowIndex
        semesters[currentIndex].removeCourse(rowIndex);

        // Update semesterGradePoints and semesterTotalCredits
        semesters[currentIndex].calculateSemesterGradePoints();
        semesters[currentIndex].calculateSemesterTotalCredits();

        // Calculate GPA after updating semesterGradePoints and semesterTotalCredits
        semesters[currentIndex].calculateGPA();

        // Update GPA and display it in the corresponding semesterForm
        double roundedGPA = round(semesters[currentIndex].getGPA() * 100.0) / 100.0;  // Round to the hundredth place
        QString gpaText = QString("GPA: %1").arg(QString::number(roundedGPA, 'f', 2));
        currentSemesterForm->setSemesterGPAText(gpaText);

        // Assuming you want to update the CGPA whenever a course is deleted
        // You would need to collect the GPAs and credits for all semesters and call the Calculator
        std::vector<double> semesterGPAs;
        std::vector<double> semesterCredits;

        for (const auto& semester : semesters) {
            semesterGPAs.push_back(semester.getGPA());
            semesterCredits.push_back(semester.getSemesterTotalCredits());
        }

        calculator.calculateCGPA(semesterGPAs, semesterCredits);
        double cgpa = calculator.getCGPA();
        cgpa = round(cgpa * 100.0) / 100.0;
        ui->labelCGPA->setText(QString("CGPA: %1").arg(cgpa));
    }
}
