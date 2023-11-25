#ifndef SEMESTERFORM_H
#define SEMESTERFORM_H

#include <QWidget>
#include <mainwindow.h>
#include <QStringListModel>

namespace Ui {
class semesterForm;
}

class semesterForm : public QWidget
{
    Q_OBJECT

public:
    QStringListModel *listViewModel;
    explicit semesterForm(QWidget *parent = nullptr);
//    semesterForm(QWidget *parent = nullptr, Semester pSemester = Semester());
    ~semesterForm();
    signals:
        void courseAdded(const QString& courseName, double grade, int credits);

private slots:
    void on_pushButtonCourseAdd_clicked();

private:
    Ui::semesterForm *ui;
//    Semester semesterTab;
};

#endif // SEMESTERFORM_H
