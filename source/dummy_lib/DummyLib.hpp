#ifndef DUMMYLIB_HPP
#define DUMMYLIB_HPP

#include <QtGlobal>
#include <QWidget>

#if defined(DummyLib_EXPORT)
	# define DummyLib_Shared Q_DECL_EXPORT
#else
	# define DummyLib_Shared Q_DECL_IMPORT
#endif

class DummyLib_Shared DummyLib : public QWidget
{
	Q_OBJECT

public:
	DummyLib(QWidget *parent = nullptr);

public slots:
	void sendDummySignal();

signals:
	void dummySignal();
};

#endif // DUMMYLIB_HPP
