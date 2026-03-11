#ifndef PIZZAGENIE_H
#define PIZZAGENIE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class PizzaGenie;
}
QT_END_NAMESPACE

class PizzaGenie : public QMainWindow
{
    Q_OBJECT

public:
    PizzaGenie(QWidget *parent = nullptr);
    ~PizzaGenie();

private slots:
    void compute();

    void on_femalesSB_valueChanged(int arg1);

    void on_malesSB_valueChanged(int arg1);

    void on_femalesDoughWeightSB_valueChanged(int arg1);

    void on_malesDoughWeightSB_valueChanged(int arg1);

    void on_flourSpinBox_valueChanged(double arg1);

    void on_hydrationSpinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::PizzaGenie *ui;

    const float yeastPerKilo = 16.0;
    const float maltPercentage = 0.33;
};
#endif // PIZZAGENIUS_H
