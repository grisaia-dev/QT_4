#pragma once
#include <QMainWindow>
#include "stopwatch.hpp"
#include "ui_MainWindow.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent), ui(new Ui::MainWindow), timer(new Stopwatch(this)) { 
        ui->setupUi(this);

        // Buttons
        ui->btn_start_stop->setText("Старт");
        ui->btn_start_stop->setCheckable(true);
        ui->btn_circle->setText("Круг");
        ui->btn_circle->setEnabled(false);
        ui->btn_clear->setText("Очистить");

        // Text timer
        ui->time->setText("00:00:00");

        // Timer
        timer->setObjectName("timer");
    }
    ~MainWindow() { delete ui;}

private slots:
    void on_btn_clear_clicked() {
        ui->time->setText("00:00:00");
        ui->tb_show_ct->clear();
    }

    void timer_start() {
    }

    void on_btn_start_stop_toggled(bool) {
        if (ui->btn_start_stop->isChecked()) {
            ui->btn_start_stop->setText("Стоп");
            ui->btn_circle->setEnabled(true);
            timer->start_timer();

        } else {
            ui->btn_start_stop->setText("Старт");
            ui->btn_circle->setEnabled(false);
            timer->stop_timer();
        }
    }

    void on_btn_circle_clicked() {
        ui->tb_show_ct->append("Круг: " + QString("N") + ", Время: " + "M");
    }

private:
    Ui::MainWindow* ui;
    Stopwatch* timer;
};