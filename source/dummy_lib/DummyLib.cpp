#include <QLabel>
#include <QVBoxLayout>

#include <DummyStatic.hpp>

#include "DummyLib.hpp"

DummyLib::DummyLib(QWidget * parent) : QWidget(parent)
{
	auto *layout = new QVBoxLayout(this);
	layout->addWidget(new QLabel("Check the console to see if the signal has correctly been sent", this));
}

void DummyLib::sendDummySignal()
{
	DummyStatic::dummyStaticFunction();
	emit dummySignal();
}
