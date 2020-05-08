#pragma once

#include "..\..\DicomCommon\Net\Server\BasicWorklistManagementSCPbasedFileSet.h"
#include "..\..\DicomCommon\Util\Logger.h"
#include "Util\SettingsManager.h"

#include <QMutex>
#include <QDirModel>

/** A model class for local server. Inherits QDirModel. Controlling the server
 *  is done through this class.
 */
class LocalWLServerModel : public QDirModel
{

	Q_OBJECT

public:

	LocalWLServerModel();
	~LocalWLServerModel();

	QModelIndex getRootIndex();
//	DICOMImage getImage( QString SOPInstanceUID );
//	bool removeImage( QString fileInStorage );
//	bool addDICOMImage( QString filename );
//	void imageRetrieved( QString SOPInstanceUID );
//	void refreshContent();	
	void startServer();
	void stopServer();
	bool isServerRunning();
//	virtual QVariant data( const QModelIndex& index, int role ) const;

private:

	QMutex mutex;
	Logger* log;
	SettingsManager* settings;
	BasicWorklistManagementSCPbasedFileSet* m_pbwlmSCPfs;
	QProcess* m_Process_bwlmSCPfs;

};
