#pragma once

#include "AbstractQueryModel.h"

/** A model class for Network server management.
 */
class NetworkWorklistServerModel : public AbstractQueryModel
{

public:

	NetworkWorklistServerModel();
	~NetworkWorklistServerModel();

	virtual void insertDICOMDataset( DICOMDataset dataset );
//	virtual QVariant data( const QModelIndex &index, int role ) const;

};


class NetworkStoreImageServerModel : public AbstractQueryModel
{

public:

	NetworkStoreImageServerModel();
	~NetworkStoreImageServerModel();

	virtual void insertDICOMDataset( DICOMDataset dataset );
//	virtual QVariant data( const QModelIndex &index, int role ) const;

};
