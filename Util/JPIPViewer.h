#pragma once

#include "Util\Logger.h"
#include "Util\SettingsManager.h"

#include <QtGui\QWidget>

/** A link class for opening JPIP referenced DICOM images with external
 *  JPIP viewing application.
 */
class JPIPViewer : QObject {

	Q_OBJECT

public:

	static JPIPViewer* instance();
	virtual ~JPIPViewer();

	void invokeViewer( QWidget* parent, QString jpipReference );

private:

	// Singleton
	JPIPViewer();
	JPIPViewer& operator=( JPIPViewer& ); // disallowed
	JPIPViewer( const JPIPViewer& ); // disallowed	
	static JPIPViewer viewerSingleton;
	
	QMutex mutex;
	SettingsManager* settings;
	Logger* log;	

};
