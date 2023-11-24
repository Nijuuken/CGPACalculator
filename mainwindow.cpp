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
    std::string semesterLineText = ui->lineEditSemesterAdd->text().toStdString();
    Semester newSemester(semesterLineText);
    semesters.push_back(newSemester);
    ui->tabWidgetSemester->addTab(new semesterForm(), QString(ui->lineEditSemesterAdd->text().arg(ui->tabWidgetSemester->count() + 1)));

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

