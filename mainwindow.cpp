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


void MainWindow::on_btnAddStudent_clicked()
{
    long id = ui->txtID->text().toLong();
    QString name = ui->txtName->text();
    int age = ui->txtAge->text().toInt();
    int year = ui->txtYear->text().toInt();

    // Take the first dormitory in the system
    Dormitory* d = uni.findDormitory(
        ui->txtDormName->text().toStdString()
        );

    if (!d)
    {
        ui->txtOutput->append("Create a dormitory first.");
        return;
    }

    Student* s = new Student(
        id,
        name.toStdString(),
        age,
        year,
        0
        );

    if (d->addStudent(s))
    {
        ui->txtOutput->append(
            "Student added to system: " + name
            );
    }
    else
    {
        ui->txtOutput->append(
            "Failed to add student."
            );
    }
}

void MainWindow::on_btnAssignRoom_clicked()
{
    QString dormName =
        ui->txtAssignDormitory->text();

    long id =
        ui->txtAssignStudent->text().toLong();

    int roomNumber =
        ui->txtAssignRoomNumber->text().toInt();

    Dormitory* d =
        uni.findDormitory(
            dormName.toStdString()
            );

    if (!d)
    {
        ui->txtOutput->append(
            "Dormitory not found."
            );
        return;
    }

    Student* s =
        uni.findStudent(
            id,
            dormName.toStdString()
            );

    if (!s)
    {
        ui->txtOutput->append(
            "Student not found."
            );
        return;
    }

    Room* r =
        uni.findRoom(
            roomNumber,
            dormName.toStdString()
            );

    // Automatically create room if missing
    if (!r)
    {
        r = new Room(roomNumber, 4);
        d->addRoom(r);
    }

    if (d->addStudentToRoom(s, r))
    {
        ui->txtOutput->append(
            "Student assigned to room "
            + QString::number(roomNumber)
            );
    }
    else
    {
        ui->txtOutput->append(
            "Assignment failed."
            );
    }
}

void MainWindow::on_btnRemoveStudent_clicked()
{
    long id =
        ui->StudentIdRemove->text().toLong();

    QString dormName =
        ui->DormitoryNameRemove->text();

    int roomNumber =
        ui->RoomNumberRemove->text().toInt();

    Dormitory* d =
        uni.findDormitory(
            dormName.toStdString()
            );

    if (!d)
    {
        ui->txtOutput->append(
            "Dormitory not found."
            );
        return;
    }

    Student* s =
        uni.findStudent(
            id,
            dormName.toStdString()
            );

    Room* r =
        uni.findRoom(
            roomNumber,
            dormName.toStdString()
            );

    if (!s || !r)
    {
        ui->txtOutput->append(
            "Student or room not found."
            );
        return;
    }

    if (d->removeStudentFromRoom(s, r))
    {
        ui->txtOutput->append(
            "Student removed from room "
            + QString::number(roomNumber)
            );
    }
    else
    {
        ui->txtOutput->append(
            "Removal failed."
            );
    }
}

