#pragma once
#include <QTimer>
#include <QDebug>

class StopWatch : public QTimer {
	Q_OBJECT
public:
	StopWatch();
	~StopWatch() { delete timer; }

	void start_timer(void) { timer->start(100); }
	void stop_timer(void) { timer->stop(); }
	void clear();

public slots:
	QString sendCircleTime(void);
	QString sendShowTime(void);

signals:
	void sig_circleTime(QString);
	void sig_showTime(QString);

private:
	QTimer* timer;
	short int m, s, ms, t_m, t_s, t_ms;
	short int circle;
	QString showTimer;
	QString circle_and_time;

	// methods
	void update();
};