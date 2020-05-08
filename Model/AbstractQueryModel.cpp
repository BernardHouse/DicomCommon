#include "AbstractQueryModel.h"

AbstractQueryModel::AbstractQueryModel( int rows, int columns, int uniqueColumn )
	: QStandardItemModel( rows, columns ) {
    this->uniqueColumn = uniqueColumn;
}

AbstractQueryModel::~AbstractQueryModel() {
	clearModel();
}

int AbstractQueryModel::getUniqueColumn() {
	QMutexLocker locker( &mutex );
	return uniqueColumn;
}

void AbstractQueryModel::clearModel() {
	QMutexLocker locker( &mutex );
	for ( int row = 0; row < rowCount(); row++ ) {
		for ( int col = 0; col < columnCount(); col++ ) {
			delete item( row, col );
		}
	}
	removeRows( 0, rowCount() );
}
