#include "StopWatch.hpp"

StopWatch::StopWatch() : timer(new QTimer(this)) {
	timer->setInterval(1);

	m = 0;
	s = 0;
	ms = 0;
	t_ms = 0;
	t_s = 0;
	t_m = 0;
	circle = 0;

	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

void StopWatch::clear() {
	m = 0;
	s = 0;
	ms = 0;
	t_ms = 0;
	t_s = 0;
	t_m = 0;
	circle = 0;
	showText.clear();
}

QString StopWatch::update() {
	ms++;
	if (ms >= 1000) {
		ms = 0;
		s++;
	}
	if (s >= 60) {
		s = 0;
		m++;
	}

	t_ms++;
	if (t_ms >= 1000) {
		t_ms = 0;
		t_s++;
	}
	if (t_s >= 60) {
		t_s = 0;
		t_m++;
	}

	showText = QString("%1:%2:%3").arg(m).arg(s).arg(ms);
	return showText;
}

QString StopWatch::sendCircleTime() {
	circle++;
	circle_and_time = QString("Круг: %1, Время: %2:%3:%4").arg(circle).arg(t_m).arg(t_s).arg(t_ms);
	t_m = 0;
	t_s = 0;
	t_ms = 0;
	return circle_and_time;
}