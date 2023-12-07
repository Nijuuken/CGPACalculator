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
    void setSemesterGPAText(const QString& text);
    explicit semesterForm(QWidget *parent = nullptr);
//    semesterForm(QWidget *parent = nullptr,  pSemester = Semester());
    ~semesterForm();
    signals:
        void courseAdded(const QString& courseName, double grade, int credits);
        void courseDeleted(int row);

private slots:
    void on_pushButtonCourseAdd_clicked();
    void on_pushButtonCourseDel_clicked();
private:
    Ui::semesterForm *ui;
    QMap<QString, double> gradeToGPA;
};

#endif // SEMESTERFORM_H
