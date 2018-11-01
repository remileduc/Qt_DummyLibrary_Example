#ifndef DUMMYLIB_HPP
#define DUMMYLIB_HPP

#include <QtGlobal>
#include <QWidget>

#if defined(DummyLib_EXPORT)
	# define DummyLib_Shared Q_DECL_EXPORT
#elif defined(DummyLib_IMPORT)
	# define DummyLib_Shared Q_DECL_IMPORT
#endif

#ifndef DummyLib_Shared
	#define DummyLib_Shared
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
