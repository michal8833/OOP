#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdexcept>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(&displacement, SIGNAL(send(float)),
                     &speed, SLOT(receive(float)));
    QObject::connect(&displacement, SIGNAL(send(float)),
                     &acceleration, SLOT(receive(float)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    displacement.set(ui->lineEdit->text().toFloat());

    try {
        ui->speedLCD->display(speed.get());
    }
    catch(std::runtime_error) {
        ui->speedLCD->display(0);
    }

    try {
        ui->accelerationLCD->display(acceleration.get());
    }
    catch(std::runtime_error) {
        ui->accelerationLCD->display(0);
    }
}
