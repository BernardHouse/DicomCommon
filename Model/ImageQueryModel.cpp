#include "ImageQueryModel.h"

ImageQueryModel::ImageQueryModel() : AbstractQueryModel( 0, 2, 1 ) {
	setHeaderData( 0, Qt::Horizontal, "Number" );
	setHeaderData( 1, Qt::Horizontal, "UNIQUE ID (HIDDEN)" );
}

ImageQueryModel::~ImageQueryModel() {
}

void ImageQueryModel::insertDICOMDataset( DICOMDataset dataset ) {

	QMutexLocker locker( &mutex );

	QStandardItem* item;
	QList<QStandardItem*> items;

	item = new QStandardItem( dataset.getValue( "0020,0013" ) ); // InstanceNumber
	items.append( item );

	// finally, for further queries, set the PATIENT level UID,
	// which is specified in the Q/R Service Class definition
	// (DICOM Part 4, Annex C)
	item = new QStandardItem( dataset.getValue( "0008,0018" ) ); // SOPInstanceUID
	items.append( item );

	appendRow( items );

}

