#pragma once

#include "Model\AbstractQueryModel.h"

/** A model class for Series level query data.
 */
class SeriesQueryModel : public AbstractQueryModel {

public:

	SeriesQueryModel();
	~SeriesQueryModel();

	virtual void insertDICOMDataset( DICOMDataset dataset );

};
