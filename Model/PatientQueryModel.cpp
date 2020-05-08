#include "PatientQueryModel.h"

PatientQueryModel::PatientQueryModel() : AbstractQueryModel( 0, 5, 4 ) {
	setHeaderData( 0, Qt::Horizontal, "ID" );
	setHeaderData( 1, Qt::Horizontal, "Name" );
	setHeaderData( 2, Qt::Horizontal, "Sex" );
	setHeaderData( 3, Qt::Horizontal, "Birth Date" );
	setHeaderData( 4, Qt::Horizontal, "UNIQUE ID (HIDDEN)" );
}

PatientQueryModel::~PatientQueryModel() {
}

void PatientQueryModel::insertDICOMDataset( DICOMDataset dataset ) {

	QMutexLocker locker( &mutex );

	QStandardItem* item;
	QList<QStandardItem*> items;

	item = new QStandardItem( dataset.getValue( "0010,0020" ) ); // PatientID
	items.append( item );

	item = new QStandardItem( dataset.getValue( "0010,0010" ) ); // PatientsName
	items.append( item );

	item = new QStandardItem( dataset.getValue( "0010,0040" ) ); // PatientsSex
	items.append( item );

	item = new QStandardItem( dataset.getValue( "0010,0030" ) ); // PatientsBirthDate
	items.append( item );

	// finally, for further queries, set the PATIENT level UID,
	// which is specified in the Q/R Service Class definition
	// (DICOM Part 4, Annex C)
	item = new QStandardItem( dataset.getValue( "0010,0020" ) ); // PatientID
	items.append( item );

	appendRow( items );

}
