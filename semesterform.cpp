#include "semesterform.h"
#include "ui_semesterform.h"

semesterForm::semesterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::semesterForm)
{
    ui->setupUi(this);
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
    //
}

