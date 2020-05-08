#pragma once

#include "..\..\DicomCommon\Datatype\DICOMDataset.h"

#include <QtCore\QList>
#include <QtCore\QMutex>
#include <QtGui\QStandardItemModel>

/** An abstract base class for client models, which contain query results
 *  for different DICOM query levels (i.e., Patient, Study, Series, and
 *  Image) within the QueryView.
 */
class AbstractQueryModel : public QStandardItemModel {

	Q_OBJECT

public:

	AbstractQueryModel( int rows, int columns, int uniqueColumn );
	virtual ~AbstractQueryModel();

	void clearModel();
	int getUniqueColumn();	

//	virtual	QVariant data( const QModelIndex &index, int role ) const = 0;
	
public slots:

    virtual void insertDICOMDataset( DICOMDataset dataset ) = 0;

protected:

	QMutex mutex;
	int uniqueColumn;

};
