#include "pizzagenie.h"
#include "./ui_pizzagenie.h"
#include <QString>

PizzaGenie::PizzaGenie(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PizzaGenie)
{
    ui->setupUi(this);
    compute();
}

PizzaGenie::~PizzaGenie()
{
    delete ui;
}

void PizzaGenie::compute()
{
    float waterPercentage = ui->hydrationSpinBox->value();

    int totalWeight = ui->femalesSB->value() * ui->femalesDoughWeightSB->value() + ui->malesSB->value() * ui->malesDoughWeightSB->value();
    ui->totalWeightLabel->setText(QString::number(totalWeight));

    float flour = ui->flourSpinBox->value();
    float water = flour*waterPercentage/100.0;

    float yeast = flour * yeastPerKilo/1000.0;
    float dryYeast = yeast * 3.0;
    float malt = yeast * maltPercentage;

    float salt = flour * 0.030;
    float olive = flour/1000.0;

    ui->waterLabel->setText(QString::number(water));

    QString yeastString = QString::number((int)(yeast+.5));
    QString dryYeastString = QString::number((int)(dryYeast+.5));
    QString yeastCompleteString = yeastString + " / " + dryYeastString;

    ui->yeastLabel->setText(yeastCompleteString);
    ui->maltLabel->setText(QString::number((int)(malt+.5)));
    ui->saltLabel->setText(QString::number(salt));
    ui->oliveLabel->setText(QString::number(olive));

    ui->totalLabel->setText(QString::number((int)((flour+water)+0.5)));
}


void PizzaGenie::on_femalesSB_valueChanged(int arg1)
{
    compute();
}


void PizzaGenie::on_malesSB_valueChanged(int arg1)
{
    compute();
}


void PizzaGenie::on_femalesDoughWeightSB_valueChanged(int arg1)
{
    compute();
}


void PizzaGenie::on_malesDoughWeightSB_valueChanged(int arg1)
{
    compute();
}


void PizzaGenie::on_flourSpinBox_valueChanged(double arg1)
{
    compute();
}


void PizzaGenie::on_hydrationSpinBox_valueChanged(int arg1)
{
    compute();
}


void PizzaGenie::on_pushButton_clicked()
{
    int totalWeight = ui->femalesSB->value() * ui->femalesDoughWeightSB->value() + ui->malesSB->value() * ui->malesDoughWeightSB->value();
    ui->totalWeightLabel->setText(QString::number(totalWeight));

    float waterPercentage = ui->hydrationSpinBox->value();
    ui->flourSpinBox->setValue(100 * (totalWeight/(100 + waterPercentage)));
}

