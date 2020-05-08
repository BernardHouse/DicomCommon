#pragma once
#include <QtSql>
#include "..\CommonDefines.h"
#include <QMap>

class CSqliteDatabase
{
public:
	QSqlDatabase m_DB;
	CSqliteDatabase(void);
	virtual ~CSqliteDatabase(void);
	typedef enum { DBNoThing = 0, DBnotValid = 1, DBnotOpened = 2, DBopened = 3} DBStatus;
	DBStatus DBopen(const QString &qsDatabasePathAndName);
	QString DBlastErrorStr(void);
	QStringList DBtables(QSql::TableType tblType);
	QString DBexplainMeLastError(void);

	bool CreateDataBase(const QString &qsDatabasePathAndName);
	bool ReadAllTables(void);
	void CloseDatabase(void);
	QString m_DBName;

	DBStatus m_DBStatus;
	typedef struct tagUniqueKey
	{
		unsigned char ucId;
		QString	qsFieldName;
		QString qsFieldType;
		unsigned char ucFieldPosition;

	}structUniqueKey;

	typedef struct tagTable
	{
		QString	qsFieldName;
		QString qsFieldType;
		unsigned char byFieldSize;

	}structTable;

	bool getUniqueConstraintTableSchema(const QString &qsTableName, QList<CSqliteDatabase::structUniqueKey> &qsLst);
	QList<CSqliteDatabase::structTable> DBgetStructTableWithDetails(QString qsTableName);
	QMap<QString, QString> copyTableStructToQMap(const QString &qsTable);
	bool testExistenceElement(const QString &qsTable, QList<CSqliteDatabase::structTable> qlstFieldsStruct, QMap<QString, QString> qsMapFieldsValues);
	bool insertOrReplaceIntoTable(const QString &qsTable, QList<CSqliteDatabase::structTable> qlstFieldsStruct, QMap<QString, QString> qsMapFieldsValues);

	int getMaxId(const QString &qsTable, const QString &qsIdFieldName);
	bool DBexecScript(QString qsScriptFile);

	virtual bool CreateTables(void)=0;


private:
	QList<structTable> m_lstStructTable;
	QString m_qsLastErrorExplaination;
	bool testIfNoErrorOccurs(const QSqlQuery &query);
	bool searchTypePosition(const QStringList qslFields, structUniqueKey &sUKey);
	QString extractSize(const QString qsType, const QString qsInput, unsigned short &usSizeResult);

};
