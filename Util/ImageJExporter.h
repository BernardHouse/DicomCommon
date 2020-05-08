#pragma once

#include "Datatype\DICOMImage.h"
#include "Util\Logger.h"
#include "Util\SettingsManager.h"

#include <QtCore\QTimer>
#include <QtGui\QWidget>

/** A link class for exporting images to ImageJ.
 */
class ImageJExporter : QObject {

	Q_OBJECT

public:

	static ImageJExporter* instance();
	virtual ~ImageJExporter();

	void exportToImageJ( QWidget* parent, DICOMImage* image );

private:

	// Singleton
	ImageJExporter();
	ImageJExporter& operator=( ImageJExporter& ); // disallowed
	ImageJExporter( const ImageJExporter& ); // disallowed	
	static ImageJExporter exporterSingleton;
	
	QMutex mutex;
	QStringList tempFileList;
	SettingsManager* settings;
	Logger* log;	
	QWidget* parent;

};
