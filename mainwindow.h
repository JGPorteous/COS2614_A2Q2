#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void SetCurrentImage(QString filename);


private slots:
    void on_pbStartStop_clicked();
    void changeTrafficLight();

private:
    Ui::MainWindow *ui;
    bool trafficLightOn;
    int currentTrafficLight;
    QTimer lightTimer;

};

#endif // MAINWINDOW_H
