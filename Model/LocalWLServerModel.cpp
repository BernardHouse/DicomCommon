#include "LocalWLServerModel.h"
#include "Defines.h"

LocalWLServerModel::LocalWLServerModel() {

	this->log = Logger::instance();
	this->settings = SettingsManager::instance();

	setFilter( QDir::Files );
	QStringList nameFilters;
	nameFilters << "*.wl";
	setNameFilters( nameFilters );

	m_pbwlmSCPfs = new BasicWorklistManagementSCPbasedFileSet();
	m_Process_bwlmSCPfs = NULL;

}

LocalWLServerModel::~LocalWLServerModel() {
	if ( m_pbwlmSCPfs != NULL ) {
		delete m_pbwlmSCPfs;
	}
}

QModelIndex LocalWLServerModel::getRootIndex() {
	return this->index( settings->getOption( "activeLocalAETdirectory" ) );	
}

/*
DICOMImage LocalWLServerModel::getImage( QString SOPInstanceUID ) {

	log->dbg( "Locating image on local storage..." );
	DICOMImage image;
	
	// iterate the active storage, look for newest file first (most of the
	// time we are looking for the newest)
	QDir storageDir( settings->getOption( "activeLocalAETdirectory" ) );
    storageDir.setFilter( QDir::Files | QDir::Hidden | QDir::NoSymLinks );	
	storageDir.setSorting( QDir::Time );
	QStringList nameFilters;
	nameFilters << "*.dcm";
	storageDir.setNameFilters( nameFilters );

    QFileInfoList list = storageDir.entryInfoList();

	bool matchFound = false;
	for ( int i = 0; i < list.size(); i++ ) {
        QFileInfo fileInfo = list.at( i );
		image.init( fileInfo.canonicalFilePath() );
		if ( image.getAttributeValue( "0008,0018" ) == SOPInstanceUID ) {
			matchFound = true;
			break;
		}
	}

	if ( !matchFound ) {
		log->dbg( "Error: local server image not matched." );
		image.clean();
	}

	return image;

}

void LocalWLServerModel::imageRetrieved( QString SOPInstanceUID ) {
	refreshContent();
}

void LocalWLServerModel::refreshContent() {	
	refresh( getRootIndex() );
}

QVariant LocalWLServerModel::data( const QModelIndex& index, int role ) const {
	if ( role == Qt::DecorationRole ) {
        return QVariant();
	} else {
		return QDirModel::data( index, role );
	}
}
*/



bool LocalWLServerModel::isServerRunning() {
	return m_pbwlmSCPfs->isRunning();
}

void LocalWLServerModel::startServer() {
	m_pbwlmSCPfs->start();
}

void LocalWLServerModel::stopServer() {
	m_pbwlmSCPfs->exit( 0 );
}

/*bool LocalWLServerModel::removeImage( QString fileInStorage ) {

    QString storageDir = QDir::toNativeSeparators( settings->getOption( "activeLocalAETdirectory" ) );

	// first, delete the desired file

	QString file( storageDir + fileInStorage );
	log->dbg( "Deleting file: " + file + "..." );
	if ( !QFile::remove( file ) ) {
		log->dbg( "Error: could not delete file: " + file );
		return false;
	}

	// then delete existing 'index.dat' file

	log->dbg( "Deleting file: " + storageDir + "index.dat..." );
	if ( !QFile::remove( storageDir + "index.dat" ) ) {
		log->dbg( "Warning: could not delete file: index.dat" );
	}

	// finally, re-register all server images

	m_Process_bwlmSCPfs = new QProcess();

	QStringList arguments;
	arguments << storageDir;
	arguments << storageDir + "*.dcm";

	log->dbg( "Starting process m_Process_bwlmSCPfs..." );
	m_Process_bwlmSCPfs->start( EDAP_DCMTK_DCMQRIDX_EXE, arguments );

	if ( !m_Process_bwlmSCPfs->waitForStarted( 30000 ) ) {
		log->dbg( "Failed to initialize process m_Process_bwlmSCPfs" );
		return false;
	}

	if ( !m_Process_bwlmSCPfs->waitForFinished( 600000 ) ) {
		log->dbg( "Process m_Process_bwlmSCPfs timed out" );
		return false;
	}

	log->dbg( "Process m_Process_bwlmSCPfs finished" );
	delete m_Process_bwlmSCPfs;
	m_Process_bwlmSCPfs = NULL;

	return true;

}

bool LocalWLServerModel::addDICOMImage( QString filename ) {

    QString storageDir = QDir::toNativeSeparators( settings->getOption( "activeLocalAETdirectory" ) );

	// first, copy the desired file into the storage directory

	int idx = filename.lastIndexOf( QRegExp( "[\\/]" ) );
	Q_ASSERT( idx != -1 );
	QString targetFile = storageDir + filename.mid( idx );
	log->dbg( "Copying file: " + filename + "..." );
	if ( !QFile::copy( filename, targetFile ) ) {
		log->dbg( "Error: could not copy file: " + filename );
		return false;
	}

	// then, register the new image into the storage

	m_Process_bwlmSCPfs = new QProcess();

	QStringList arguments;
	arguments << storageDir;
	arguments << targetFile;

	log->dbg( "Starting process m_Process_bwlmSCPfs..." );
	m_Process_bwlmSCPfs->start( EDAP_DCMTK_DCMQRIDX_EXE, arguments );

	if ( !m_Process_bwlmSCPfs->waitForStarted( 30000 ) ) {
		log->dbg( "Failed to initialize process m_Process_bwlmSCPfs" );
		return false;
	}

	if ( !m_Process_bwlmSCPfs->waitForFinished( 600000 ) ) {
		log->dbg( "Process m_Process_bwlmSCPfs timed out" );
		return false;
	}

	log->dbg( "Process m_Process_bwlmSCPfs finished" );
	delete m_Process_bwlmSCPfs;
	m_Process_bwlmSCPfs = NULL;

	return true;

}
*/