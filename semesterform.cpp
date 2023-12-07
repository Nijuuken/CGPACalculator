#include "semesterform.h"
#include "ui_semesterform.h"
#include <QStringListModel>
#include <QMessageBox>


semesterForm::semesterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::semesterForm)
{
    ui->setupUi(this);

    // Initialize the QStringListModel for the QListView
    listViewModel = new QStringListModel(this);
    ui->listView->setModel(listViewModel);
    // Initialize the grade to GPA mapping
    gradeToGPA = {
        {"A+", 4.0},
        {"A", 4.0},
        {"A-", 3.7},
        {"B+", 3.3},
        {"B", 3.0},
        {"B-", 2.7},
        {"C+", 2.3},
        {"C", 2.0},
        {"C-", 1.7},
        {"D+", 1.3},
        {"D", 1.0},
        {"D-", 0.7},
        {"F", 0.0}
    };
}

//semesterForm::semesterForm(QWidget *parent, Semester pSemester) :
//    QWidget(parent),
//    ui(new Ui::semesterForm),
//    semesterTab(pSemester)
//{
//    ui->setupUi(this);
//}


semesterForm::~semesterForm()
{
    delete ui;
}

void semesterForm::setSemesterGPAText(const QString& text)
{
    ui->label_Semester_GPA->setText(text);
}

void semesterForm::on_pushButtonCourseAdd_clicked()
{
    // Extracting text from QLineEdit widgets
    QString courseName = ui->lineEditCourseName->text();
    QString letterGrade = ui->lineEdit_2GPA->text().toUpper(); // Convert to uppercase for case-insensitivity
    QString credits = ui->lineEdit_3Credits->text();

    // Check if all fields are properly filled
    if (courseName.isEmpty() || letterGrade.isEmpty() || credits.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return; // Stop further execution if any field is empty
    }

    // With this block to convert letter grades to GPAs
    double gpaValue = gradeToGPA.value(letterGrade, -1.0);

    if (gpaValue == -1.0) {
        QMessageBox::warning(this, "Error", "Please enter a valid letter grade.");
        return;
    }

    // Check if credits is a proper decimal
    bool creditsOk;
    double creditsValue = credits.toDouble(&creditsOk);

    if (!creditsOk || creditsValue < 0.0) {
        QMessageBox::warning(this, "Error", "Please enter a valid positive decimal for credits.");
        return; // Stop further execution if credits is invalid
    }
    emit courseAdded(courseName, gpaValue, creditsValue);
    // Concatenate the information into a single string
    QString courseInfo = QString("%1 - Letter Grade: %2 - Credits: %3").arg(courseName, letterGrade, credits);

    // Update the data in the QStringListModel
    QStringList dataList = listViewModel->stringList();
    dataList.append(courseInfo);
    listViewModel->setStringList(dataList);

    // Clear the input fields after adding the data
    ui->lineEditCourseName->clear();
    ui->lineEdit_2GPA->clear();
    ui->lineEdit_3Credits->clear();
}

void semesterForm::on_pushButtonCourseDel_clicked()
{
    // Get the selected index from the QListView
    QModelIndexList selectedIndexes = ui->listView->selectionModel()->selectedIndexes();

    // Check if any item is selected
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select a course to delete.");
        return;
    }

    // Get the selected row
    int selectedRow = selectedIndexes.first().row();

    // Remove the course from the QStringListModel
    QStringList dataList = listViewModel->stringList();
    dataList.removeAt(selectedRow);
    listViewModel->setStringList(dataList);

    // Emit a signal to notify MainWindow about the course deletion
    emit courseDeleted(selectedRow);
}
