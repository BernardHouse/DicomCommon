#pragma once

#include "Util\Logger.h"
#include "Util\SettingsManager.h"

#include <QtCore\QProcess>
#include <QtCore\QThread>

/** A threaded network class for Store SCP.
 */
class StoreCSP : public QThread {

	Q_OBJECT

public:

	StoreCSP();
	~StoreCSP();

	bool isRunning();
	virtual void run();

private:

	int startServerProcess();

	Logger* log;
	SettingsManager* settings;
	QProcess* storescp;

};

