#pragma once

#include <QMap>
#include <QString>

/** A DICOM dataset. Currently has no support for sequences or multiple values.
 */ 
class DICOMDataset
{
public:
	/** Constructs a new, empty object.
	 *  @param none
	 *  @return none
	 */
	DICOMDataset();

	/** Constructs a new object from an existing one.
	 *  @param copy - [in] Existing object to be copied
	 *  @return none
	 */
	DICOMDataset( const DICOMDataset& copy );

	/** Returns true if the dataset is empty.
	 *  @param none
	 *  @return true if empty, false otherwise
	 */
	bool isEmpty();

	/** Inserts a new value into the dataset.
	 *  @param tag - [in] A DICOM tag
	 *  @param value - [in] The value of the tag
	 *  @return none
	 */
	void insertValue( QString tag, QString value, bool bUpper = true );

	/** Returns the value of a desired tag in the dataset. Empty is string is
	 *  returned if no match found.
	 *  @param tag - [in] A DICOM tag
	 *  @return The value of the given tag as a string
	 */
	QString getValue( QString tag, bool bUpper = true );

	/** Destructs the object.
	 *  @param none
	 *  @return none
	 */
	~DICOMDataset();

private:

	/// The DICOM dataset as a map
	QMap<QString,QString> data;

};
