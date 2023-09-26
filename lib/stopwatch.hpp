#pragma once
#include <QTimer>

class Stopwatch : public QObject {
	Q_OBJECT
public:
	Stopwatch(QObject* parent = nullptr) : QObject(parent), timer(new QTimer(this)) {}
	~Stopwatch() { delete timer; }

	void start_timer(void) { timer->start(1); }
	void stop_timer(void) { timer->stop(); }

private:
	QTimer* timer;
	int time;
};