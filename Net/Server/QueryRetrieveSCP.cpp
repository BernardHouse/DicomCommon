#include "QueryRetrieveSCP.h"

#include "Defines.h"

#include <QtCore\QDir>
#include <QtCore\QTextStream>

QueryRetrieveSCP::QueryRetrieveSCP() {
	log = Logger::instance();
	settings = SettingsManager::instance();
	dcmqrscp = NULL;
}

QueryRetrieveSCP::~QueryRetrieveSCP() {
	quit();
	wait();
}

void QueryRetrieveSCP::run() {
	log->dbg( "Starting thread QueryRetrieveSCP..." );
	int ret = startServerProcess();
	if ( !ret ) {
		// e.g., notify somebody
	}
	log->dbg( "Terminating thread QueryRetrieveSCP..." );
}

int QueryRetrieveSCP::startServerProcess() {

    dcmqrscp = new QProcess();

	QStringList arguments;
	arguments << "-v"; // verbose mode by default
	if ( settings->getOption( "serverVeryVerboseMode" ) == "true" ) {
		arguments << "-vv";
	}
	if ( settings->getOption( "serverDebugMode" ) == "true" ) {
		arguments << "-d";
	}
	if ( settings->getOption( "localServerFork" ) == "true" ) {
		arguments << "--fork"; // multi-process mode
	}
	if ( settings->getOption( "serverPublicMode" ) == "true" ) {
		arguments << "--public";
	}
#ifndef NDEBUG
	arguments << "--allow-shutdown"; // allow remote shutdown in debug mode
#endif
	arguments << "-c" << EDAP_DCMQRSCP_CONFIG_FILE;

	// merge stdout and stderr and redirect them
	dcmqrscp->setProcessChannelMode( QProcess::MergedChannels );
    dcmqrscp->setStandardOutputFile( settings->getOption( "serverOutputLog" ) );

	log->dbg( "Starting process dcmqrscp..." );
	dcmqrscp->start( EDAP_DCMTK_DCMQRSCP_EXE, arguments );

	if ( !dcmqrscp->waitForStarted( 30000 ) ) {
		log->dbg( "Failed to initialize process dcmqrscp" );
		return -1;
	}

	log->dbg( "Thread QueryRetrieveSCP entering into event loop..." );
	int ret = exec();

	if ( dcmqrscp->state() == QProcess::Running ) {
		log->dbg( "Killing process dcmqrscp..." );
		dcmqrscp->kill();			
		dcmqrscp->waitForFinished( 10000 );
	} else {
		log->dbg( "Process dcmqrscp finished" );
	}
	delete dcmqrscp;
	dcmqrscp = NULL;	

	return ret;

}

bool QueryRetrieveSCP::isRunning() {
	if ( dcmqrscp != NULL && dcmqrscp->state() == QProcess::Running ) {
		return true;
	} else {
		return false;
	}
}
