#pragma once

#include "AbstractQueryModel.h"

/** A model class for Basic Worklist Management level query data.
 */
class BasicWorklistQueryModel : public AbstractQueryModel
{

public:

	BasicWorklistQueryModel(const bool &bSCP);
	~BasicWorklistQueryModel();

	virtual void insertDICOMDataset( DICOMDataset dataset );

//	virtual QVariant data( const QModelIndex &index, int role ) const;

};
