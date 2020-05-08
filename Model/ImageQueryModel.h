#pragma once

#include "Model\AbstractQueryModel.h"

/** A model class for Image level query data.
 */
class ImageQueryModel : public AbstractQueryModel {

public:

	ImageQueryModel();
	~ImageQueryModel();

	virtual void insertDICOMDataset( DICOMDataset dataset );

};
