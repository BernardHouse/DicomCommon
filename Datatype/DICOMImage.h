#pragma once

#include "DICOMDataset.h"
#include "..\..\DicomCommon\Util\Logger.h"

#include <QString>
#include <QStringList>
#include <QPixmap>

/** A DICOM image with tag-value pairs and (possible) pixel data.
 */ 
class DICOMImage {

public:

	DICOMImage();
	DICOMImage( QString file );
	DICOMImage( const DICOMImage& copy );
	DICOMImage& operator=( const DICOMImage& right );

	void init( QString file );
	void clean();

	bool isEmpty();
	QString getJPIPReference();
	QString getFile();
	QByteArray getDataDump();
	QPixmap* getPixmap();
	QString getAttributeValue( QString tag );

	~DICOMImage();

private:

	void readDataFromFile();

	Logger* log;
	QString file;
	QByteArray dataDump;
	QPixmap pixmap;
	QString jpipReference;

};
