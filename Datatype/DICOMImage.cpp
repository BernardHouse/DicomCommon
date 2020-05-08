#include "DICOMImage.h"

#include "Util\DICOMFile.h"

DICOMImage::DICOMImage() {
	log = Logger::instance();
	jpipReference.clear();
}

DICOMImage::DICOMImage( QString file ) {
	this->file = file;
	log = Logger::instance();
	jpipReference.clear();
    readDataFromFile();
}

DICOMImage::DICOMImage( const DICOMImage& copy ) {
	file = copy.file;
	dataDump = copy.dataDump;
	pixmap = copy.pixmap;
	jpipReference = copy.jpipReference;
}

DICOMImage& DICOMImage::operator=( const DICOMImage& right ) {
	file = right.file;
	dataDump = right.dataDump;
	pixmap = right.pixmap;
	jpipReference = right.jpipReference;
	return *this;
}

DICOMImage::~DICOMImage() {
	clean();
}

void DICOMImage::init( QString file ) {
	clean();
	this->file = file;	
    readDataFromFile();
}

void DICOMImage::clean() {
	file.clear();
	dataDump.clear();
	jpipReference.clear();
	pixmap = QPixmap();
}

bool DICOMImage::isEmpty() {
	return dataDump.isEmpty();
}

QString DICOMImage::getFile() {
	return file;
}

QByteArray DICOMImage::getDataDump() {
	return dataDump;
}

QPixmap* DICOMImage::getPixmap() {
	return &pixmap;
}

void DICOMImage::readDataFromFile() {
	DICOMFile dcmFile( file );	
	dataDump = dcmFile.getDataDump();
	// if we have a Pixel Data Provider URL tag (0028,7fe0), set the pixmap
	// to a pre-created pixmap
	jpipReference = getAttributeValue( tagPixelDataProviderURL );
	if ( jpipReference.isEmpty() )
	{
		QString photom = getAttributeValue( tagPhotometricInterpretation ); 
		if ( photom == "MONOCHROME1" || photom == "MONOCHROME2" )
		{
			if( (getAttributeValue(tagWindowCenter) != "") && (getAttributeValue(tagWindowWidth) != "") )
				pixmap = dcmFile.getPixmap( true );
			else
				pixmap = dcmFile.getPixmap( false );		
		}
		else
		{
			pixmap = dcmFile.getPixmap( false );		
		}
	}
	else
	{
		pixmap = QPixmap( ":/Icon/jpip-text.png" );		
	}
}

QString DICOMImage::getAttributeValue( QString tag )
{	
	QString value ="";//20131119    
	QList<QByteArray> rows = dataDump.split( '\n' );
	for ( int i = 0; i < rows.count(); i++ )
	{
		QRegExp rx( "^\\(" + tag + "\\)" );
		rx.setCaseSensitivity( Qt::CaseInsensitive );
		if ( rx.indexIn( rows[i] ) != -1 )
		{
			rx.setPattern( "^\\(" + tag + "\\).*\\[(.*)\\]" );					
			if ( rx.indexIn( rows[i] ) != -1 )
			{
				value = rx.cap( 1 );
			}
			else
			{
				rx.setPattern( "^\\(" + tag + "\\)....(.*)#" );					
				if ( rx.indexIn( rows[i] ) != -1 )
				{
					value = rx.cap( 1 ).trimmed();					
				}
			}
		}
	}	
	return value;
}

QString DICOMImage::getJPIPReference() {
	return jpipReference;
}