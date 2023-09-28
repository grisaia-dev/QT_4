#pragma once
#include <QMainWindow>
#include "StopWatch.hpp"
#include "ui_MainWindow.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow() { delete ui; }

private slots:
    void on_btn_clear_clicked();
    void on_btn_start_stop_toggled(bool);
    void on_btn_circle_clicked();

    // Для отображения круга и времени его прохождения
    void ctSignal(QString);
    void ctSendSignal(void);

    // Для отоброжения времени секундомера
    void timeSignal(QString);
    void timeSendSignal(void);
private:
    Ui::MainWindow* ui;
    StopWatch* timer;
};