#pragma once

#include "Model\AbstractQueryModel.h"

/** A model class for Study level query data.
 */
class StudyQueryModel : public AbstractQueryModel {

public:

	StudyQueryModel();
	~StudyQueryModel();

	virtual void insertDICOMDataset( DICOMDataset dataset );

};
