#include "DICOMDataset.h"

DICOMDataset::DICOMDataset()
{
}

DICOMDataset::DICOMDataset( const DICOMDataset& copy )
{
	data = copy.data;
}

DICOMDataset::~DICOMDataset()
{
}

bool DICOMDataset::isEmpty()
{
	return data.isEmpty();
}

void DICOMDataset::insertValue(QString tag, QString value, bool bUpper)
{
	// use uppercase presentation internally
	if( bUpper == true )
		data[ tag.toUpper() ] = value;
	else
		data[ tag ] = value;
}

QString DICOMDataset::getValue(QString tag, bool bUpper)
{
	// use uppercase presentation internally
	QString tagUpper = tag;
	if( bUpper == true )
		tagUpper = tag.toUpper();

	if ( data.contains( tagUpper ) )
	{
		return data[ tagUpper ];
	}
	else
	{
		return QString();
	}
}