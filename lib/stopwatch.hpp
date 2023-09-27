#pragma once
#include <QTimer>
#include <QDebug>

class StopWatch : public QTimer {
	Q_OBJECT
public:
	StopWatch();
	~StopWatch() { delete timer; }

	void start_timer(void) { timer->start(); }
	void stop_timer(void) { timer->stop(); }
	//int getM() { return m; }
	//int getS() { return s; }
	//int getMS() { return ms; }
	void clear();

public slots:
	QString update();
	QString sendCircleTime(void);

signals:
	void sig_circleTime(QString);
	void sig_updateTime(QString);

private:
	QTimer* timer;
	short int m, s, ms, t_m, t_s, t_ms;
	short int circle;
	QString showText;
	QString circle_and_time;
};