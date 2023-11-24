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

void semesterForm::on_pushButtonCourseAdd_clicked()
{
    // Extracting text from QLineEdit widgets
    QString courseName = ui->lineEditCourseName->text();
    QString GPA = ui->lineEdit_2GPA->text();
    QString credits = ui->lineEdit_3Credits->text();

    // Check if all fields are properly filled
    if (courseName.isEmpty() || GPA.isEmpty() || credits.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return; // Stop further execution if any field is empty
    }

    // Check if GPA is a proper decimal between 0 and 4.0
    bool gpaOk;
    double gpaValue = GPA.toDouble(&gpaOk);

    if (!gpaOk || gpaValue < 0.0 || gpaValue > 4.0) {
        QMessageBox::warning(this, "Error", "Please enter a valid GPA between 0.0 and 4.0.");
        return; // Stop further execution if GPA is invalid
    }

    // Check if credits is a proper decimal
    bool creditsOk;
    double creditsValue = credits.toDouble(&creditsOk);

    if (!creditsOk || creditsValue < 0.0) {
        QMessageBox::warning(this, "Error", "Please enter a valid positive decimal for credits.");
        return; // Stop further execution if credits is invalid
    }

    // Concatenate the information into a single string
    QString courseInfo = QString("%1 - GPA: %2 - Credits: %3").arg(courseName, GPA, credits);

    // Update the data in the QStringListModel
    QStringList dataList = listViewModel->stringList();
    dataList.append(courseInfo);
    listViewModel->setStringList(dataList);

    // Clear the input fields after adding the data
    ui->lineEditCourseName->clear();
    ui->lineEdit_2GPA->clear();
    ui->lineEdit_3Credits->clear();
}
