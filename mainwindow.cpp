#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_btnAddDormitory_clicked()
{
    QString name = ui->txtDormName->text();
    int roomCap = ui->txtRoomCap->text().toInt();
    int studentCap = ui->txtStudentCap->text().toInt();

    Dormitory* d = new Dormitory(roomCap, studentCap);
    d->setName(name.toStdString());

    uni.addDormitory(d);

    ui->txtOutput->append("Dormitory added: " + name);
}

