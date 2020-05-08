#pragma once

#include "Model\AbstractQueryModel.h"

/** A model class for Patient level query data.
 */
class PatientQueryModel : public AbstractQueryModel {

public:

	PatientQueryModel();
	~PatientQueryModel();

	virtual void insertDICOMDataset( DICOMDataset dataset );

};
