/*
    Author : Justin Porteous
    Student : 51565579
    Assignment 2 Question 2
    Unique assignment no: 576441
    GitHub: https://github.com/JGPorteous/COS2614_A2Q2
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
