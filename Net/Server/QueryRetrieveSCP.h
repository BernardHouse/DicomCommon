#pragma once

#include "..\..\DicomCommon\Util\Logger.h"
#include "Util\SettingsManager.h"

#include <QtCore\QProcess>
#include <QtCore\QThread>

/** A threaded network class for Query and Retrieve SCP.
 */
class QueryRetrieveSCP : public QThread {

	Q_OBJECT

public:

	QueryRetrieveSCP();
	~QueryRetrieveSCP();

	bool isRunning();
	virtual void run();

private:

	int startServerProcess();

	Logger* log;
	SettingsManager* settings;
	QProcess* dcmqrscp;

};

