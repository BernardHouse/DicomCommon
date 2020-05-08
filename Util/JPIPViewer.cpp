#include "JPIPViewer.h"

#include <QtCore\QDateTime>
#include <QtCore\QDir>
#include <QtCore\QFile>
#include <QtCore\QProcess>
#include <QtGui\QMessageBox>

JPIPViewer* JPIPViewer::instance() {
	return &viewerSingleton;
}

JPIPViewer::JPIPViewer() {
    settings = SettingsManager::instance();
	log = Logger::instance();
}

JPIPViewer::~JPIPViewer() {
}

void JPIPViewer::invokeViewer( QWidget* parent, QString jpipReference ) {

	QMutexLocker locker( &mutex );

	QString program = settings->getOption( "JPIPViewerExecutable" );
	if ( program.isEmpty() ) {
		QMessageBox::information(
			parent,
			"JVSdicom",
			"Please specify a JPIP viewer executable\nlocation in Preferences.",
			QMessageBox::Ok );
		return;
	}

	QProcess jpipViewer;
	QStringList arguments;	
	arguments << jpipReference;
	
	log->dbg( "Starting JPIP viewer process (detached)..." );
	bool success = jpipViewer.startDetached( program, arguments, QDir::currentPath() );

	if ( !success ) {
		log->dbg( "Error: failed to initialize external JPIP viewer process" );
		QMessageBox::critical(
			parent,
			"JVSdicom",
			"Unable to invoke external JPIP viewer.",
			QMessageBox::Ok );
		return;
	}

}

// static member initialization
JPIPViewer JPIPViewer::viewerSingleton;
