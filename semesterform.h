#ifndef SEMESTERFORM_H
#define SEMESTERFORM_H

#include <QWidget>
#include <mainwindow.h>

namespace Ui {
class semesterForm;
}

class semesterForm : public QWidget
{
    Q_OBJECT

public:
    explicit semesterForm(QWidget *parent = nullptr);
//    semesterForm(QWidget *parent = nullptr, Semester pSemester = Semester());
    ~semesterForm();

private slots:
    void on_pushButtonCourseAdd_clicked();

private:
    Ui::semesterForm *ui;
//    Semester semesterTab;
};

#endif // SEMESTERFORM_H