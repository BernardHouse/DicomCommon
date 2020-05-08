#pragma once

// release
#ifdef NDEBUG

/*#define EDAP_SERVER_CONFIG_FILE  "dcmqrscp.cfg"

#define EDAP_DCMTK_DCMQRIDX_EXE  "dcmqridx.exe"
#define EDAP_DCMTK_ECHOSCU_EXE   "echoscu.exe"
#define EDAP_DCMTK_FINDSCU_EXE   "findscu.exe"
#define EDAP_DCMTK_MOVESCU_EXE   "movescu.exe"
#define EDAP_DCMTK_DCMQRSCP_EXE  "dcmqrscp.exe"
#define EDAP_DCMTK_DCMDUMP_EXE   "dcmdump.exe"
#define EDAP_DCMTK_DCMJ2PNM_EXE  "dcmj2pnm.exe"
#define EDAP_DCMTK_IMG2DCM_EXE   "img2dcm.exe"
#define EDAP_DCMTK_DUMP2DCM_EXE  "dump2dcm.exe"
#define EDAP_DCMTK_DCMODIFY_EXE  "dcmodify.exe"
*/
#define EDAP_DCMQRSCP_CONFIG_FILE  "D:\\DCMTK\\etc\\DCMTK\\dcmqrscp.cfg"
#define EDAP_STORESCP_CONFIG_FILE  "D:\\DCMTK\\etc\\DCMTK\\storescp.cfg"

#define EDAP_DCMTK_DCMQRIDX_EXE  "D:\\DCMTK\\bin\\Release\\dcmqridx.exe"
#define EDAP_DCMTK_ECHOSCU_EXE   "D:\\DCMTK\\bin\\Release\\echoscu.exe"
#define EDAP_DCMTK_FINDSCU_EXE   "D:\\DCMTK\\bin\\Release\\findscu.exe"
#define EDAP_DCMTK_MOVESCU_EXE   "D:\\DCMTK\\bin\\Release\\movescu.exe"
#define EDAP_DCMTK_DCMQRSCP_EXE  "D:\\DCMTK\\bin\\Release\\dcmqrscp.exe"
#define EDAP_DCMTK_DCMDUMP_EXE   "D:\\DCMTK\\bin\\Release\\dcmdump.exe"
#define EDAP_DCMTK_DCMJ2PNM_EXE  "D:\\DCMTK\\bin\\Release\\dcmj2pnm.exe"
#define EDAP_DCMTK_IMG2DCM_EXE   "D:\\DCMTK\\bin\\Release\\img2dcm.exe"
#define EDAP_DCMTK_DUMP2DCM_EXE  "D:\\DCMTK\\bin\\Release\\dump2dcm.exe"
#define EDAP_DCMTK_DCMODIFY_EXE  "D:\\DCMTK\\bin\\Release\\dcmodify.exe"
#define EDAP_DCMTK_STORESCP_EXE  "D:\\DCMTK\\bin\\Release\\storescp.exe"
#define EDAP_DCMTK_STORESCU_EXE  "D:\\DCMTK\\bin\\Release\\storescu.exe"
#define EDAP_DCMTK_WLMSCPFS_EXE  "D:\\DCMTK\\bin\\Release\\wlmscpfs.exe"
#endif

// debug
#ifndef NDEBUG
//BMA 20131022	NB use getenv(DCMTK_DIR) for dynamic path
#define EDAP_DCMQRSCP_CONFIG_FILE  "D:\\DCMTK\\etc\\DCMTK\\dcmqrscp.cfg"
#define EDAP_STORESCP_CONFIG_FILE  "D:\\DCMTK\\etc\\DCMTK\\storescp.cfg"
/*
#define EDAP_DCMTK_DCMQRIDX_EXE  "D:\\DCMTK\\bin\\Debug\\dcmqridx.exe"
#define EDAP_DCMTK_FINDSCU_EXE   "D:\\DCMTK\\bin\\Debug\\findscu.exe"
#define EDAP_DCMTK_MOVESCU_EXE   "D:\\DCMTK\\bin\\Debug\\movescu.exe"
#define EDAP_DCMTK_DCMQRSCP_EXE  "D:\\DCMTK\\bin\\Debug\\dcmqrscp.exe"
#define EDAP_DCMTK_DCMDUMP_EXE   "D:\\DCMTK\\bin\\Debug\\dcmdump.exe"
#define EDAP_DCMTK_DCMJ2PNM_EXE  "D:\\DCMTK\\bin\\Debug\\dcmj2pnm.exe"
#define EDAP_DCMTK_IMG2DCM_EXE   "D:\\DCMTK\\bin\\Debug\\img2dcm.exe"
#define EDAP_DCMTK_DUMP2DCM_EXE  "D:\\DCMTK\\bin\\Debug\\dump2dcm.exe"
#define EDAP_DCMTK_DCMODIFY_EXE  "D:\\DCMTK\\bin\\Debug\\dcmodify.exe"
*/
#define EDAP_DCMTK_DCMQRIDX_EXE  "D:\\DCMTK\\bin\\Release\\dcmqridx.exe"
#define EDAP_DCMTK_ECHOSCU_EXE   "D:\\DCMTK\\bin\\Release\\echoscu.exe"
#define EDAP_DCMTK_FINDSCU_EXE   "D:\\DCMTK\\bin\\Release\\findscu.exe"
#define EDAP_DCMTK_MOVESCU_EXE   "D:\\DCMTK\\bin\\Release\\movescu.exe"
#define EDAP_DCMTK_DCMQRSCP_EXE  "D:\\DCMTK\\bin\\Release\\dcmqrscp.exe"
#define EDAP_DCMTK_DCMDUMP_EXE   "D:\\DCMTK\\bin\\Release\\dcmdump.exe"
#define EDAP_DCMTK_DCMJ2PNM_EXE  "D:\\DCMTK\\bin\\Release\\dcmj2pnm.exe"
#define EDAP_DCMTK_IMG2DCM_EXE   "D:\\DCMTK\\bin\\Release\\img2dcm.exe"
#define EDAP_DCMTK_DUMP2DCM_EXE  "D:\\DCMTK\\bin\\Release\\dump2dcm.exe"
#define EDAP_DCMTK_DCMODIFY_EXE  "D:\\DCMTK\\bin\\Release\\dcmodify.exe"
#define EDAP_DCMTK_STORESCP_EXE  "D:\\DCMTK\\bin\\Release\\storescp.exe"
#define EDAP_DCMTK_STORESCU_EXE  "D:\\DCMTK\\bin\\Release\\storescu.exe"
#define EDAP_DCMTK_WLMSCPFS_EXE  "D:\\DCMTK\\bin\\Release\\wlmscpfs.exe"
#endif		

typedef enum { QSCUWorklist=0, QSCUImage }TypeQuerySCU;
typedef enum { ESCUWorklist=0, ESCUStore }TypeEchoSCU;
typedef enum { QDirCreate=0, QDirModify, QDirDelete }TypeQDirAction;

//DICOM tags
#define tagTransferSyntaxUID				"0002,0010"
//Basic Worklist Management
//SOP Common
#define tagSpecificCharacterSet				"0008,0005"		//CS Optional
#define tagSOPInstanceUID					"0008,0018" 	
//Scheduled Procedure Step
#define tagScheduledProcedureStepSequence	"0040,0100"		//SQ Requested
#define tagScheduledStationAETitle			"0040,0001"		//AE Requested
#define tagScheduledProcedureStepStartDate	"0040,0002"		//DA Requested
#define tagScheduledProcedureStepStartTime	"0040,0003"		//TM Requested
#define tagModality			 				"0008,0060"		//CS Requested
#define tagScheduledPerformingPhysicianName "0040,0006"		//PN Requested
#define tagScheduledProcedureStepDescription "0040,0007"	//LO Optional
#define tagScheduledStationName				"0040,0010"		//SH Optional
#define tagScheduledProcedureStepLocation	"0040,0011"		//SH Optional
#define tagPreMedication					"0040,0012"		//LO Optional
#define tagScheduledProcedureStepID			"0040,0009"		//SH Optional
#define tagRequestedContrastAgent			"0032,1070"		//LO Optional
//Requested Procedure
#define tagRequestedProcedureID				"0040,1001"		//SH Optional
#define tagRequestedProcedureDescription	"0032,1060"		//LO Optional
#define tagStudyInstanceUID					"0020,000D"		//UI Optional
#define tagRequestedProcedurePriority		"0040,1003"		//SH Optional
#define tagPatientTransportArrangements		"0040,1004"		//LO Optional
//Imaging Service Request
#define tagAccessionNumber	 				"0008,0050"		//SH Requested
#define tagRequestingPhysician 				"0032,1032"		//PN Optional
#define tagReferringPhysicianName			"0008,0090"		//PN Optional
//Visit Identification
#define tagAdmissionID						"0038,0010"		//LO Optional
//Visit Status
#define tagCurrentPatientLocation			"0038,0300"		//LO Optional
//Patient identification
#define tagPatientName						"0010,0010"		//PN Requested
#define tagPatientID 						"0010,0020"		//LO Requested
//Patient demographic
#define tagPatientBirthDate 				"0010,0030"		//DA Optional
#define tagPatientSex		  				"0010,0040"		//CS Optional
#define tagPatientWeight	  				"0010,1030"		//DS Optional
//Patient medical
#define tagMedicalAlerts 					"0010,2000"		//LO Optional
#define tagAllergies 						"0010,2110"		//LO Optional

#define tagStudyDescription					"0008,1030"
#define tagSeriesDescription				"0008,103E"
#define tagStudyID							"0020,0010"
#define tagSeriesNumber						"0020,0011"
#define tagInstanceNumber					"0020,0013"
#define tagStudyInstanceUID					"0020,000D"
#define tagSamplesPerPixel					"0028,0002"
#define tagPhotometricInterpretation		"0028,0004"
#define tagPixelSpacing						"0028,0030"
#define tagImagerPixelSpacing				"0018,1164"
#define tagNominalScannedPixelSpacing		"0018,2010"
#define tagImagePlanePixelSpacing			"3002,0011"
#define tagCompensatorPixelSpacing			"300a,00e9"
#define tagDetectorElementSpacing			"0018,7022"
#define tagPresentationPixelSpacing			"0070,0101"
#define tagObjectPixelSpacingInCenterOfBeam	"0018,9404"

#define tagWindowCenter						"0028,1050"
#define tagWindowWidth						"0028,1051"
#define tagPixelDataProviderURL				"0028,7FE0"

#define tagStartOfItem 						"FFFE,E000"		//- Requested
#define tagEndOfItems 						"FFFE,E00D"		//- Requested
#define tagEndOfSequence					"FFFE,E0DD"		//- Requested

//settings txt
#define txtRemoteAET				"remoteAET"
#define	txtRemoteAddress			"remoteAddress"
#define	txtRemotePort				"remotePort"

#define txtRemoteStoreAET			"remoteStoreAET"
#define	txtRemoteStoreAddress		"remoteStoreAddress"
#define	txtRemoteStorePort			"remoteStorePort"
#define	txtActiveImagesDirectory	"activeImagesDirectory"

//Tables txt
#define txtWLSid			"WLSid"
#define txtSISid			"SISid"
#define txtServerName		"ServerName"
#define txtAETitle			"AETitle"
#define txtIPAddHostname	"IPAddHostname"
#define txtPortNumber		"PortNumber"
#define txtEnabled			"Enabled"
#define txtHospitalId		"HospitalId"

//Filters txt
#define txtPatientNameFilter						"PatientNameFilter"
#define txtPatientIDFilter							"PatientIDFilter"
#define txtPatientSexFilter							"PatientSexFilter"
#define txtPatientBirthDateFilter					"PatientBirthDateFilter"
#define txtAccessionNumberFilter					"AccessionNumberFilter"
#define txtScheduledStationAETitleFilter			"ScheduledStationAETitleFilter"
#define txtModalityFilter							"ModalityFilter"
#define txtScheduledProcedureStepStartDateFilter	"ScheduledProcedureStepStartDateFilter"
#define txtScheduledProcedureStepStartTimeFilter	"ScheduledProcedureStepStartTimeFilter"
#define txtScheduledPerformingPhysiciansNameFilter	"ScheduledPerformingPhysiciansNameFilter"
#define txtScheduledProcedureStepSequence			"ScheduledProcedureStepSequence"
#define txtScheduledStationAETitle					"ScheduledStationAETitle"
#define txtModality									"Modality"
#define txtScheduledProcedureStepStartDate			"ScheduledProcedureStepStartDate"
#define txtScheduledPerformingPhysicianName			"ScheduledPerformingPhysicianName"
//ComboBox txt
#define txtAny										"Any"
#define txtDateOperator								"Enter by operator"
#define txtToDay									"ToDay"
#define txtThisWeek									"This Week"
#define txtThisMonth								"This Month"
#define txtThisYear									"This Year"
#define txtSince1Week								"Since 1 Week"
#define txtSince1Month								"Since 1 Month"
#define txtSince1Year								"Since 1 Year"


//Liste Server column
#define ServerIdColumn			0
#define ServerNameColumn		1
#define ServerAETitleColumn		2
#define ServerIPHostnameColumn	3
#define ServerPortNumberColumn	4
#define ServerEnableColumn		5
#define ServerHospitalIdColumn	6


//Worklist column
#define PatientNameColumn0							0						
#define PatientBirthDateColumn1						1
#define PatientIDColumn2							2
#define AccessionNumberColumn3						3
#define PatientSexColumn4							4
#define ModalityColumn5								5
#define ScheduledProcedureStepStartDateColumn6		6
#define ScheduledProcedureStepStartTimeColumn7		7
#define	ScheduledPerformingPhysiciansNameColumn8	8
#define SpecificCharacterSetColumn9					9
#define ScheduledProcedureStepSequenceColumn10		10
#define ScheduledStationAETitleColumn11				11
#define ScheduledProcedureStepDescriptionColumn12	12
#define ScheduledStationNameColumn13				13
#define ScheduledProcedureStepLocationColumn14		14
#define PreMedicationColumn15						15
#define ScheduledProcedureStepIDColumn16			16
#define RequestedContrastAgentColumn17				17
#define RequestedProcedureIDColumn18				18
#define RequestedProcedureDescriptionColumn19		19
#define StudyInstanceUIDColumn20					20
#define RequestedProcedurePriorityColumn21			21		
#define PatientTransportArrangementsColumn22		22
#define RequestingPhysicianColumn23					23
#define ReferingPhysicianNameColumn24				24
#define AdmissionIDColumn25							25
#define CurrentPatientLocationColumn26				26
#define PatientWeightColumn27						27
#define MedicalAlertsColumn28						28
#define ContrastAllergiesColumn29					29
#define WorklistIndexUniqueColumn	ContrastAllergiesColumn29+1
#define NbWorklistIndexColumn	WorklistIndexUniqueColumn+1

typedef struct tagServerTable
{
	int id;
	QString	Name;
	QString	AETitle;
	QString	IPHostname;
	int iPortNumber;
	bool bEnabled;
	int iHospitalId;
}structServerTable;

typedef struct WorklistMemberTable
{
	//SOP Common
	QString	SpecificCharacterSet;
	//Scheduled Procedure Step
	QString	ScheduledProcedureStepSequence	;
	QString ScheduledStationAETitle;			
	QString ScheduledProcedureStepStartDate;	
	QString ScheduledProcedureStepStartTime;	
	QString Modality;			 				
	QString ScheduledPerformingPhysicianName;
	QString ScheduledProcedureStepDescription;
	QString ScheduledStationName;				
	QString ScheduledProcedureStepLocation;	
	QString PreMedication;					
	QString ScheduledProcedureStepID;			
	QString RequestedContrastAgent;
	//Requested Procedure
	QString	RequestedProcedureID;			
	QString RequestedProcedureDescription;	
	QString StudyInstanceUID;				
	QString RequestedProcedurePriority;		
	QString PatientTransportArrangements;		
	//Imaging Service Request
	QString AccessionNumber;
	QString RequestingPhysician; 				
	QString ReferringPhysicianName;			
	//Visit Identification
	QString AdmissionID;			
	//Visit Status
	QString CurrentPatientLocation;
	//Patient identification
	QString PatientName;		
	QString PatientID;					
	//Patient demographic
	QString PatientBirthDate; 				
	QString PatientSex;	  				
	QString PatientWeight;	  				
	//Patient medical
	QString MedicalAlerts;					
	QString ContrastAllergies; 				
}structWorklistMemberTable;


#define UI_LENGTH 64
#define PN_LENGTH 64
#define LO_LENGTH 64
#define AE_LENGTH 16
#define SH_LENGTH 16
#define DS_LENGTH 16
