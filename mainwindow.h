#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Semester.h>
#include <vector>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAddSemester_clicked();

    void on_tabWidgetSemester_tabCloseRequested(int index);

    void on_tabWidgetSemester_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    std::vector<Semester> semesters;
};
#endif // MAINWINDOW_H