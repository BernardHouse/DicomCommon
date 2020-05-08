#include "ImageJExporter.h"

#include <QtCore\QDateTime>
#include <QtCore\QDir>
#include <QtCore\QFile>
#include <QtCore\QProcess>
#include <QtCore\QUuid>
#include <QtGui\QMessageBox>

ImageJExporter* ImageJExporter::instance() {
	return &exporterSingleton;
}

ImageJExporter::ImageJExporter() {
    settings = SettingsManager::instance();
	log = Logger::instance();
}

ImageJExporter::~ImageJExporter() {
	// delete each temp file
	for ( int i = 0; i < tempFileList.size(); i++ ) {
		QFile::remove( tempFileList[i] );		
	}
}

void ImageJExporter::exportToImageJ( QWidget* parent, DICOMImage* image ) {

	QMutexLocker locker( &mutex );

	QString program = settings->getOption( "ImageJExecutable" );
	if ( program.isEmpty() ) {
		QMessageBox::information(
			parent,
			"JVSdicom",
			"Please specify ImageJ executable\nlocation in Preferences.",
			QMessageBox::Ok );
		return;
	}

	QString tempFile( QDir::tempPath() + "/" + QUuid::createUuid().toString() + ".bmp" );
	image->getPixmap()->save( tempFile );
	tempFileList.append( tempFile );

	QProcess ImageJ;
	QStringList arguments;
	arguments << "-eval";
	QString eval = "open('" + QDir::toNativeSeparators( tempFile ) + "');";
	eval += settings->getOption( "ImageJStartupParameters" );
	arguments << eval.replace( "\\", "\\\\" );

	log->dbg( "Starting ImageJ process (detached)..." );
	bool success = ImageJ.startDetached( program, arguments, QDir::currentPath() );

	if ( !success ) {
		log->dbg( "Error: failed to initialize ImageJ process" );
		QMessageBox::critical(
			parent,
			"JVSdicom",
			"Unable to initialize ImageJ.",
			QMessageBox::Ok );
		return;
	}

}

// static member initialization
ImageJExporter ImageJExporter::exporterSingleton;
