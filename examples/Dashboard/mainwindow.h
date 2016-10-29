#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../source/qcgaugewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    void SetupCompass();

private:
    Ui::MainWindow *ui;

    QcGaugeWidget    *compassGauge;
    QcNeedleItem     *compassNeedle;
};

#endif // MAINWINDOW_H
