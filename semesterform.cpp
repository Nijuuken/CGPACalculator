#include "semesterform.h"
#include "ui_semesterform.h"
#include <QStringListModel>

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
    QString courseName = ui->lineEditCourseName->text();
    QString GPA = ui->lineEdit_2GPA->text();
    QString credits = ui->lineEdit_3Credits->text();

    // Concatenate the information into a single string
    QString courseInfo = QString("%1 - GPA: %2 - Credits: %3").arg(courseName, GPA, credits);

    // Update the data in the QStringListModel
    QStringList dataList = listViewModel->stringList();
    dataList.append(courseInfo);
    listViewModel->setStringList(dataList);
}
