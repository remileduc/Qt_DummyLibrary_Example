#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <QDebug>
#include <QObject>

class Dummy : public QObject
{
	Q_OBJECT

public:
	Dummy(QObject *parent = nullptr) : QObject(parent) {}

public slots:
	void dummySlot() { qDebug() << "\n\tSignal has correctly been sent, received by Dummy QObject :)\n"; }
};

#endif // DUMMY_HPP
