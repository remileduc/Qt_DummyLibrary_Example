#include <iostream>

#include <QApplication>

#include <DummyLib.hpp>

#include "Dummy.hpp"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	DummyLib mainWidget;
	Dummy dumb;

	QObject::connect(&mainWidget, &DummyLib::dummySignal, []() -> void { std::cout << "\n\tSignal has correctly been sent :)\n"; });
	QObject::connect(&mainWidget, &DummyLib::dummySignal, &dumb, &Dummy::dummySlot);
	QObject::connect(&mainWidget, SIGNAL(dummySignal()), &dumb, SLOT(dummySlot()));
	mainWidget.sendDummySignal();

	mainWidget.show();
	return app.exec();
}
