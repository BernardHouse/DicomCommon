#include "StoreCSP.h"

#include "Defines.h"

#include <QtCore\QDir>
#include <QtCore\QTextStream>

StoreCSP::StoreCSP() {
	log = Logger::instance();
	settings = SettingsManager::instance();
	storescp = NULL;
}

StoreCSP::~StoreCSP() {
	quit();
	wait();
}

void StoreCSP::run() {
	log->dbg( "Starting thread StoreCSP..." );
	int ret = startServerProcess();
	if ( !ret ) {
		// e.g., notify somebody
	}
	log->dbg( "Terminating thread StoreCSP..." );
}

int StoreCSP::startServerProcess() {

    storescp = new QProcess();

	QStringList arguments;
	arguments << "-v"; // verbose mode by default
	if ( settings->getOption( "serverDebugMode" ) == "true" ) {
		arguments << "-d";
	}
	if ( settings->getOption( "localServerFork" ) == "true" ) {
		arguments << "--fork"; // multi-process mode
	}
#ifndef NDEBUG
	arguments << "--allow-shutdown"; // allow remote shutdown in debug mode
#endif
	arguments << "-c" << EDAP_STORESCP_CONFIG_FILE;

	// merge stdout and stderr and redirect them
	storescp->setProcessChannelMode( QProcess::MergedChannels );
    storescp->setStandardOutputFile( settings->getOption( "serverOutputLog" ) );

	log->dbg( "Starting process storescp..." );
	storescp->start( EDAP_DCMTK_STORESCP_EXE, arguments );

	if ( !storescp->waitForStarted( 30000 ) ) {
		log->dbg( "Failed to initialize process storescp" );
		return -1;
	}

	log->dbg( "Thread StoreCSP entering into event loop..." );
	int ret = exec();

	if ( storescp->state() == QProcess::Running ) {
		log->dbg( "Killing process storescp..." );
		storescp->kill();			
		storescp->waitForFinished( 10000 );
	} else {
		log->dbg( "Process storescp finished" );
	}
	delete storescp;
	storescp = NULL;	

	return ret;

}

bool StoreCSP::isRunning()
{
	if ( storescp != NULL && storescp->state() == QProcess::Running )
	{
		return true;
	} else
	{
		return false;
	}
}
