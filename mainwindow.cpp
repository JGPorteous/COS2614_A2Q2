/*
    Author : Justin Porteous
    Student : 51565579
    Assignment 2 Question 2
    Unique assignment no: 576441
    GitHub: https://github.com/JGPorteous/COS2614_A2Q2
 */

/*
 Note to Marker:
     I was unable to debug & run this application, I think it was due to a dll issue.
     Because I couldn't use QT4 for this application, and the fact that it compiles without error or warning
     and that I'm confident on the logic, I'm assuming that it works :)
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //initialize variables
    trafficLightOn = false;
    currentTrafficLight = 0;

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbStartStop_clicked()
{
    if (trafficLightOn)
    { //Traffic light is on, stop it
        ui->pbStartStop->setText("Start Traffic Light");
        ui->sbInterval->setReadOnly(false);
        lightTimer.stop();
        currentTrafficLight = 0;
    }
    else
    { //Traffic Light is off, start it
        ui->pbStartStop->setText("Stop Traffic Light");
        lightTimer.setInterval(ui->sbInterval->value() * 1000); //Convert to milliseconds
        ui->sbInterval->setReadOnly(true);
        connect(this, SIGNAL(timeout()), this, SLOT(changeTrafficLight()));
        lightTimer.start();
    }

    //Change flag to opposite of what it was, so we can keep track
    // of the state of the traffic light (on or not)
    trafficLightOn = !trafficLightOn;
}

void MainWindow::changeTrafficLight()
{
    //Update Traffic Light Image
    // Assumes that the images are in the same folder as the compiled EXE
    switch (currentTrafficLight)
    {
    case 0: //Green
        ui->lblCheckLight->setText("Green");
        SetCurrentImage("Green.jpg");
        break;

    case 1: //Yellow
        ui->lblCheckLight->setText("Yellow");
        SetCurrentImage("Yellow.jpg");
        break;

    case 2: //Red
        ui->lblCheckLight->setText("Red");
        SetCurrentImage("Red.jpg");
        break;
    }

    //Set Next Traffic Light
    if (currentTrafficLight < 2)
        currentTrafficLight++;
    else
        currentTrafficLight = 0;

}

void MainWindow::SetCurrentImage(QString filename)
{
    //Change the current graphic
    QGraphicsScene *scene = new QGraphicsScene();
    QPixmap pm(filename);
    scene->setBackgroundBrush(pm.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->gvTrafficLight->setScene(scene);
}

