#include "BasicWorklistManagementSCPbasedFileSet.h"

#include "Defines.h"

#include <QtCore\QDir>
#include <QtCore\QTextStream>

BasicWorklistManagementSCPbasedFileSet::BasicWorklistManagementSCPbasedFileSet() {
	log = Logger::instance();
	settings = SettingsManager::instance();
	wlmscpfs = NULL;
}

BasicWorklistManagementSCPbasedFileSet::~BasicWorklistManagementSCPbasedFileSet() {
	quit();
	wait();
}

void BasicWorklistManagementSCPbasedFileSet::setDataFilesPath(const QString &qsPath, QStringList matchingKeys)
{
	m_qsDataFilesPath = qsPath;
	m_qslMatchingKeys = matchingKeys;
}

void BasicWorklistManagementSCPbasedFileSet::run() {
	log->dbg( "Starting thread BasicWorklistManagementSCPbasedFileSet..." );
	int ret = startServerProcess();
	if ( !ret ) {
		// e.g., notify somebody
	}
	log->dbg( "Terminating thread BasicWorklistManagementSCPbasedFileSet..." );
}

int BasicWorklistManagementSCPbasedFileSet::startServerProcess() {

    wlmscpfs = new QProcess();

	QStringList arguments;
	arguments << QString("-v"); // verbose mode by default
	if ( settings->getOption( "serverDebugMode" ) == "true" )
	{
		arguments << QString("-d");
	}
	if ( settings->getOption( "localServerFork" ) == "true" )
	{
		arguments << QString("--fork"); // multi-process mode
	}
	else
	{
		arguments << QString("--single-process");
	}
	if( m_qsDataFilesPath == "" )
		m_qsDataFilesPath = settings->getOption( "activeWLMSCPdirectory" );
	//2020042701 arguments << QString("-dfp " + m_qsDataFilesPath);
	arguments << QString("-dfp") << m_qsDataFilesPath;

	// merge stdout and stderr and redirect them
	wlmscpfs->setProcessChannelMode( QProcess::MergedChannels );
    wlmscpfs->setStandardOutputFile( settings->getOption( "serverOutputLog" ) );

	arguments << settings->getOption( "localPort" );

	log->dbg( "Starting process wlmscpfs..." );
	wlmscpfs->start( EDAP_DCMTK_WLMSCPFS_EXE, arguments );

	if ( !wlmscpfs->waitForStarted( 30000 ) ) {
		log->dbg( "Failed to initialize process wlmscpfs" );
		return -1;
	}

	log->dbg( "Thread BasicWorklistManagementSCPbasedFileSet entering into event loop..." );
	int ret = exec();

	if ( wlmscpfs->state() == QProcess::Running ) {
		log->dbg( "Killing process wlmscpfs..." );
		wlmscpfs->kill();			
		wlmscpfs->waitForFinished( 10000 );
	} else {
		log->dbg( "Process wlmscpfs finished" );
	}
	delete wlmscpfs;
	wlmscpfs = NULL;	

	return ret;

}

bool BasicWorklistManagementSCPbasedFileSet::isRunning() {
	if ( wlmscpfs != NULL && wlmscpfs->state() == QProcess::Running ) {
		return true;
	} else {
		return false;
	}
}
