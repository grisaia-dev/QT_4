#include "MainWindow.hpp"
#include "StopWatch.hpp"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow), timer(new StopWatch()) {
    ui->setupUi(this);

    // Buttons
    ui->btn_start_stop->setText("Старт");
    ui->btn_start_stop->setCheckable(true);
    ui->btn_circle->setText("Круг");
    ui->btn_circle->setEnabled(false);
    ui->btn_clear->setText("Очистить");

    // Text timer
    ui->l_time->setText("0:0:0");

    QObject::connect(timer, &StopWatch::sig_circleTime, this, &MainWindow::ctSignal);
    connect(timer, &StopWatch::sig_showTime, this, &MainWindow::timeSignal);
}

// slots
void MainWindow::on_btn_clear_clicked() {
    timer->stop_timer();
    timer->clear();
    ui->btn_start_stop->setText("Старт");
    ui->btn_start_stop->setChecked(false);
    ui->l_time->setText("0:0:0");
    //ui->tb_show_ct->clear();
}

void MainWindow::on_btn_start_stop_toggled(bool) {
    if (ui->btn_start_stop->isChecked()) {
        timer->start_timer();
        timeSendSignal();
        ui->btn_start_stop->setText("Стоп");
        ui->btn_circle->setEnabled(true);
    } else {
        timer->stop_timer();
        ui->btn_start_stop->setText("Старт");
        ui->btn_circle->setEnabled(false);
    }
}

void MainWindow::on_btn_circle_clicked() {
    ctSendSignal();
}

void MainWindow::ctSignal(QString str) {
    ui->tb_show_ct->append(str);
}

void MainWindow::ctSendSignal() {
    timer->sig_circleTime(timer->sendCircleTime());
}

void MainWindow::timeSignal(QString str) {
    ui->l_time->setText(str);
}

void MainWindow::timeSendSignal() {
    timer->sig_showTime(timer->sendShowTime());
}