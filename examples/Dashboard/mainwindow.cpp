#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SetupCompass();
    SetupAirspeedGauge();
}

void MainWindow::SetupCompass() {
    compassGauge = new QcGaugeWidget;

    compassGauge->addBackground(99);
    QcBackgroundItem *bkg1 = compassGauge->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,Qt::black);
    bkg1->addColor(1.0,Qt::white);

    QcBackgroundItem *bkg2 = compassGauge->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,Qt::white);
    bkg2->addColor(1.0,Qt::black);

    QcLabelItem *w = compassGauge->addLabel(80);
    w->setText("W");
    w->setAngle(0);
    w->setColor(Qt::white);

    QcLabelItem *n = compassGauge->addLabel(80);
    n->setText("N");
    n->setAngle(90);
    n->setColor(Qt::white);

    QcLabelItem *e = compassGauge->addLabel(80);
    e->setText("E");
    e->setAngle(180);
    e->setColor(Qt::white);

    QcLabelItem *s = compassGauge->addLabel(80);
    s->setText("S");
    s->setAngle(270);
    s->setColor(Qt::white);

    QcDegreesItem *deg = compassGauge->addDegrees(70);
    deg->setStep(5);
    deg->setMaxDegree(270);
    deg->setMinDegree(-75);
    deg->setColor(Qt::white);
    compassNeedle = compassGauge->addNeedle(60);
    compassNeedle->setNeedle(QcNeedleItem::CompassNeedle);
    compassNeedle->setValueRange(0,360);
    compassNeedle->setMaxDegree(360);
    compassNeedle->setMinDegree(0);
    compassGauge->addBackground(7);
    compassGauge->addGlass(88);
    ui->verticalLayout->addWidget(compassGauge);
}

void MainWindow::SetupAirspeedGauge() {
    airspeedGauge = new QcGaugeWidget;
    airspeedGauge->addArc(55);
    airspeedGauge->addDegrees(65)->setValueRange(0,100);
    QcColorBand *clrBand = airspeedGauge->addColorBand(50);
    clrBand->setValueRange(0,100);
    airspeedGauge->addValues(80)->setValueRange(0,100);
    airspeedGauge->addLabel(70)->setText("Km/h");
    QcLabelItem *lab = airspeedGauge->addLabel(40);
    lab->setText("0");
    airspeedNeedle = airspeedGauge->addNeedle(60);
    airspeedNeedle->setLabel(lab);
    airspeedNeedle->setColor(Qt::blue);
    airspeedNeedle->setValueRange(0,100);
    airspeedGauge->addBackground(7);
    ui->horizontalLayout->addWidget(airspeedGauge);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    compassNeedle->setCurrentValue(value);
    airspeedNeedle->setCurrentValue(value);
}
