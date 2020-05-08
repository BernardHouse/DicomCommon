#pragma once

#include "..\..\DicomCommon\Util\Logger.h"
#include "Util\SettingsManager.h"

#include <QtCore\QProcess>
#include <QtCore\QThread>

/** A threaded network class for worklist management SCP base on data files set.
 */
class BasicWorklistManagementSCPbasedFileSet : public QThread {

	Q_OBJECT

public:

	BasicWorklistManagementSCPbasedFileSet();
	~BasicWorklistManagementSCPbasedFileSet();
	void setDataFilesPath(const QString &qsPath, QStringList matchingKeys);
	bool isRunning();
	virtual void run();

private:

	int startServerProcess();

	Logger* log;
	SettingsManager* settings;
	QProcess* wlmscpfs;
	QString m_qsDataFilesPath;
	QStringList m_qslMatchingKeys;

};

