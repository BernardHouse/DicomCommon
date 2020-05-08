#include "SeriesQueryModel.h"

SeriesQueryModel::SeriesQueryModel() : AbstractQueryModel( 0, 4, 3 ) {
	setHeaderData( 0, Qt::Horizontal, "Number" );
	setHeaderData( 1, Qt::Horizontal, "Modality" );
	setHeaderData( 2, Qt::Horizontal, "Description" );
    setHeaderData( 3, Qt::Horizontal, "UNIQUE ID (HIDDEN)" );
}

SeriesQueryModel::~SeriesQueryModel() {
}

void SeriesQueryModel::insertDICOMDataset( DICOMDataset dataset ) { 

	QMutexLocker locker( &mutex );

	QStandardItem* item;
	QList<QStandardItem*> items;

	item = new QStandardItem( dataset.getValue( "0020,0011" ) ); // SeriesNumber
	items.append( item );

	item = new QStandardItem( dataset.getValue( "0008,0060" ) ); // Modality
	items.append( item );

	item = new QStandardItem( dataset.getValue( "0008,103e" ) ); // SeriesDescription
	items.append( item );

	// finally, for further queries, set the PATIENT level UID,
	// which is specified in the Q/R Service Class definition
	// (DICOM Part 4, Annex C)
	item = new QStandardItem( dataset.getValue( "0020,000e" ) ); // SeriesInstanceUID
	items.append( item );

	appendRow( items );

}
