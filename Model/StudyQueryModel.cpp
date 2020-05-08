#include "StudyQueryModel.h"

StudyQueryModel::StudyQueryModel() : AbstractQueryModel( 0, 5, 4 ) {
	setHeaderData( 0, Qt::Horizontal, "ID" );
	setHeaderData( 1, Qt::Horizontal, "Date" );
	setHeaderData( 2, Qt::Horizontal, "Time" );
	setHeaderData( 3, Qt::Horizontal, "Description" );
	setHeaderData( 4, Qt::Horizontal, "UNIQUE ID (HIDDEN)" );
}

StudyQueryModel::~StudyQueryModel() {
}

void StudyQueryModel::insertDICOMDataset( DICOMDataset dataset ) {

	QMutexLocker locker( &mutex );

	QStandardItem* item;
	QList<QStandardItem*> items;

	item = new QStandardItem( dataset.getValue( "0020,0010" ) ); // StudyID
	items.append( item );

	item = new QStandardItem( dataset.getValue( "0008,0020" ) ); // StudyDate
	items.append( item );

	item = new QStandardItem( dataset.getValue( "0008,0030" ) ); // StudyTime
	items.append( item );

	item = new QStandardItem( dataset.getValue( "0008,1030" ) ); // StudyDescription
	items.append( item );

	// finally, for further queries, set the PATIENT level UID,
	// which is specified in the Q/R Service Class definition
	// (DICOM Part 4, Annex C)
	item = new QStandardItem( dataset.getValue( "0020,000d" ) ); // StudyInstanceUID
	items.append( item );

	appendRow( items );

}
