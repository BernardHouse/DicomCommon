#include "BasicWorklistQueryModel.h"
#include "..\CommonDefines.h"

BasicWorklistQueryModel::BasicWorklistQueryModel(const bool &bSCP) : AbstractQueryModel( 0, NbWorklistIndexColumn, WorklistIndexUniqueColumn )
{
	setHeaderData( PatientNameColumn0						, Qt::Horizontal, tr("Patient's name") );
	setHeaderData( PatientBirthDateColumn1					, Qt::Horizontal, tr("Birth Date") );
	setHeaderData( PatientIDColumn2							, Qt::Horizontal, tr("Patient ID") );
	setHeaderData( AccessionNumberColumn3					, Qt::Horizontal, tr("Accession number") );
	setHeaderData( PatientSexColumn4						, Qt::Horizontal, tr("Sex") );
	setHeaderData( ModalityColumn5							, Qt::Horizontal, tr("Modality") );
	setHeaderData( ScheduledProcedureStepStartDateColumn6	, Qt::Horizontal, tr("SPS Start date") );
	setHeaderData( ScheduledProcedureStepStartTimeColumn7	, Qt::Horizontal, tr("SPS Start time") );
	setHeaderData( ScheduledPerformingPhysiciansNameColumn8	, Qt::Horizontal, tr("Performing Physician"));
	setHeaderData( SpecificCharacterSetColumn9				, Qt::Horizontal, tr("Specific Character Set") );
	setHeaderData( ScheduledProcedureStepSequenceColumn10	, Qt::Horizontal, tr("ScheduledProcedureStepSequence") );	
	setHeaderData( ScheduledStationAETitleColumn11			, Qt::Horizontal, tr("ScheduledStationAETitle") );	
	setHeaderData( ScheduledProcedureStepDescriptionColumn12, Qt::Horizontal, tr("ScheduledProcedureStepDescription") );	
	setHeaderData( ScheduledStationNameColumn13				, Qt::Horizontal, tr("ScheduledStationName") );
	setHeaderData( ScheduledProcedureStepLocationColumn14	, Qt::Horizontal, tr("ScheduledProcedureStepLocation") );	
	setHeaderData( PreMedicationColumn15					, Qt::Horizontal, tr("PreMedication") );	
	setHeaderData( ScheduledProcedureStepIDColumn16			, Qt::Horizontal, tr("ScheduledProcedureStepID") );
	setHeaderData( RequestedContrastAgentColumn17			, Qt::Horizontal, tr("RequestedContrastAgent") );	
	setHeaderData( RequestedProcedureIDColumn18				, Qt::Horizontal, tr("RequestedProcedureID") );
	setHeaderData( RequestedProcedureDescriptionColumn19	, Qt::Horizontal, tr("RequestedProcedureDescription") );	
	setHeaderData( StudyInstanceUIDColumn20					, Qt::Horizontal, tr("StudyInstanceUID") );
	setHeaderData( RequestedProcedurePriorityColumn21		, Qt::Horizontal, tr("RequestedProcedurePriority") );	
	setHeaderData( PatientTransportArrangementsColumn22		, Qt::Horizontal, tr("PatientTransportArrangements") );
	setHeaderData( RequestingPhysicianColumn23				, Qt::Horizontal, tr("RequestingPhysician") );	
	setHeaderData( ReferingPhysicianNameColumn24			, Qt::Horizontal, tr("ReferringPhysicianName") );	
	setHeaderData( AdmissionIDColumn25						, Qt::Horizontal, tr("AdmissionID") );	
	setHeaderData( CurrentPatientLocationColumn26			, Qt::Horizontal, tr("CurrentPatientLocation") );	
	setHeaderData( PatientWeightColumn27					, Qt::Horizontal, tr("PatientWeight") );	
	setHeaderData( MedicalAlertsColumn28					, Qt::Horizontal, tr("MedicalAlerts") );	
	setHeaderData( ContrastAllergiesColumn29				, Qt::Horizontal, tr("ContrastAllergies") );	
	setHeaderData( WorklistIndexUniqueColumn				, Qt::Horizontal, "UNIQUE Patient ID (HIDDEN)" );
}

BasicWorklistQueryModel::~BasicWorklistQueryModel()
{
}

void BasicWorklistQueryModel::insertDICOMDataset( DICOMDataset dataset )
{

	QMutexLocker locker( &mutex );

	QStandardItem* item;
	QList<QStandardItem*> items;

	item = new QStandardItem( dataset.getValue(tagPatientName));		
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagPatientBirthDate) );	 
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagPatientID));			 
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagAccessionNumber));	 
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagPatientSex));	 
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagModality));		
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagScheduledProcedureStepStartDate) );	 
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagScheduledProcedureStepStartTime));			 
	items.append( item );
//
	item = new QStandardItem( dataset.getValue(tagScheduledPerformingPhysicianName) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagSpecificCharacterSet) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagScheduledProcedureStepSequence) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagScheduledStationAETitle) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagScheduledProcedureStepDescription) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagScheduledStationName) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagScheduledProcedureStepLocation) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagPreMedication) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagScheduledProcedureStepID) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagRequestedContrastAgent) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagRequestedProcedureID) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagRequestedProcedureDescription) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagStudyInstanceUID) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagRequestedProcedurePriority) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagPatientTransportArrangements) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagRequestingPhysician) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagReferringPhysicianName) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagAdmissionID) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagCurrentPatientLocation) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagPatientWeight) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagMedicalAlerts) );
	items.append( item );
	item = new QStandardItem( dataset.getValue(tagAllergies) );
	items.append( item );
//
	// finally, for further queries, set the PATIENT level UID,
	// which is specified in the Q/R Service Class definition
	// (DICOM Part 4, Annex C)
	item = new QStandardItem( dataset.getValue(tagPatientID));			
	items.append( item );

	appendRow( items );

}

/*
QVariant BasicWorklistQueryModel::data( const QModelIndex &index, int role ) const
{
    if ( index.isValid() && role == Qt::ForegroundRole )
    {
        if ( index.column() == 2 )
        {
            return QVariant( QColor( Qt::red ) );
        }
        return QVariant( QColor( Qt::black ) );
    }

    return QAbstractItemModel::data( index, role );
}*/