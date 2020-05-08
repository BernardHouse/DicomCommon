#include "SqliteDatabase.h"
#include <QFile>
#include <QMessageBox>

CSqliteDatabase::CSqliteDatabase(void) 
{
}

CSqliteDatabase::~CSqliteDatabase(void)
{
//	CloseDatabase();
}

CSqliteDatabase::DBStatus CSqliteDatabase::DBopen(const QString &qsDatabasePathAndName)
{
	m_DB = QSqlDatabase::addDatabase("QSQLITE");
	m_DB.setDatabaseName(qsDatabasePathAndName);
    if (!m_DB.open()) 
	{
		m_DBStatus = DBnotOpened;
		m_qsLastErrorExplaination = m_DB.lastError().text();
	}
	else
	{
		if(m_DB.tables(QSql::Tables).size()!=0)
			m_DBStatus = DBopened;	
		else
		{
			m_DBStatus = DBnotOpened;
			m_qsLastErrorExplaination = m_DB.lastError().text();
		}
	}

	return m_DBStatus;
}

void CSqliteDatabase::CloseDatabase(void)
{
	if(m_DB.isOpen())
	{ 
		m_DB.close();
		QSqlDatabase::removeDatabase("QSQLITE");
	}
}

QString CSqliteDatabase::DBexplainMeLastError(void)
{
	return m_qsLastErrorExplaination;
}

QString CSqliteDatabase::DBlastErrorStr(void)
{
	return m_DB.lastError().text();
}

QStringList CSqliteDatabase::DBtables(QSql::TableType tblType)
{
	return m_DB.tables(tblType);
}


bool CSqliteDatabase::testIfNoErrorOccurs(const QSqlQuery &query)
{
	bool bRet = true;
	QSqlError error;

	error = query.lastError();
	if( error.type() != QSqlError::NoError )
	{
		bRet = false;
		m_qsLastErrorExplaination = "QSqlError = " + error.text();
	}
	return bRet;
}


bool CSqliteDatabase::DBexecScript(QString qsScriptFile)
{
	bool bRet = false;
	//la fonction .read utilisee avec sqlite3.exe ne fonctionne pas
	QFile qfSchema(qsScriptFile);
	m_qsLastErrorExplaination = "";
	if( qfSchema.open(QFile::ReadOnly) == true )
	{
		QStringList qslSQLcommands;
		qslSQLcommands = QString(qfSchema.readAll()).split(";");
		QSqlQuery query;
		for( short i=0; (i < qslSQLcommands.count()) && (bRet == true ); i++ )
		{	//on filtre les commentaires
			//if( (qslSQLcommands.value(i).left(2) != "/*") && (qslSQLcommands.value(i).right(2) == "*/"))
			{	//on filtre les chaines presque vides
				if( qslSQLcommands.value(i).length() > 3 )
				{
					query = m_DB.exec(qslSQLcommands.value(i));

					bRet = testIfNoErrorOccurs(query);
				}
			}
		}
		qfSchema.close();
	}
	else
	{
		m_qsLastErrorExplaination = "Cannot open file " + qsScriptFile;
		bRet = false;
	}
	return bRet;
}

bool CSqliteDatabase::CreateDataBase(const QString &qsDatabasePathAndName)
{
	bool bRet = true;
	m_DB = QSqlDatabase::addDatabase("QSQLITE");
	m_DB.setDatabaseName(qsDatabasePathAndName);

	if (!m_DB.open()) {
		QMessageBox::critical(0, qApp->tr("Cannot open database"),
			qApp->tr("Unable to establish a database connection.\n"
						"This example needs SQLite support. Please verify "
						"the sqldrivers directory exists  "
						"with sqlite4.dll file.\n\n"
						"Click Cancel to exit."), QMessageBox::Cancel);
		return false;
	}

	bRet = CreateTables();
    return bRet;
}

bool CSqliteDatabase::ReadAllTables(void)
{
	bool bRet = false;
	QStringList qslTables = DBtables(QSql::Tables);
	if( qslTables.size() > 0 )
	{
		bRet = true;
	}

	return bRet;
}

int CSqliteDatabase::getMaxId(const QString &qsTable, const QString &qsIdFieldName)
{
	int iRet = -1;
	bool bRet = false;
	QSqlQuery query;
	QString qsToExec = QString("select %0 from %1 order by %2 desc limit 1").arg(qsIdFieldName).arg(qsTable).arg(qsIdFieldName);
	if( (bRet = query.exec(qsToExec)) == true )
	{
		if(  query.next() == true )
			iRet = query.value(0).toInt();
	}
	return iRet;
}


//----------------------------------------------------------------------------
// permet de lire la ligne de commamde qui a permis de creer la table
// et de stocker dans une liste les clefs uniques
//----------------------------------------------------------------------------
bool CSqliteDatabase::getUniqueConstraintTableSchema(const QString &qsTableName, QList<CSqliteDatabase::structUniqueKey> &qsLst)
{
	bool bRet = false;  
    QString qsExec = "select sql from sqlite_master where type = 'table' and name = '" + qsTableName + "'";
	QSqlQuery query;
	query = m_DB.exec(qsExec);
	QStringList qslSQLfields;
	QStringList qslSQLcontraints;
	QStringList qslSQLkeys;
	CSqliteDatabase::structUniqueKey sUniqueKey;
	unsigned char ucId=0;
	if( query.first() == true )
	{
		QString qsUNIQUE = "UNIQUE";
		QString qsResult = query.value(0).toString();
		qsResult = qsResult.replace('\t', ' ');
		qslSQLfields = qsResult.split(",");
		qslSQLcontraints = qsResult.split("CONSTRAINT");
		for( short i = 0; i < qslSQLcontraints.count(); i++ )
		{
			if( qslSQLcontraints.at(i).contains(qsUNIQUE) == true )
			{
				short indexU= qslSQLcontraints.at(i).indexOf(qsUNIQUE);
				if( indexU > 0 )
				{
					qsResult = qslSQLcontraints.at(i).mid(indexU+6, qslSQLcontraints.at(i).length() - (indexU + 6 + 1));
					short index1, index2;
					index1 = qsResult.indexOf("(");
					index2 = qsResult.indexOf(")");
					if( (index1 >= 0) && ( index2 >= 0) && ((index1+1) != (index2-1)))
					{
						unsigned char ucNbKey = 0;
						qsResult = qsResult.mid(index1+1, index2-(index1+1));
						qslSQLkeys = qsResult.split(",");
						sUniqueKey.ucId = ucId;
						do
						{
							sUniqueKey.qsFieldName = qslSQLkeys.at(ucNbKey);
							searchTypePosition(qslSQLfields, sUniqueKey);
							qsLst.append(sUniqueKey);
						}while(++ucNbKey < qslSQLkeys.count());
					}
					else
						QMessageBox::warning(NULL, "getUniqueConstraintTableSchema2", "indexU + 6 + 1 : enlever le + 1 ou index2-1 enlever -1");
					ucId++;
				}
			}
		}
	}
	if( qsLst.size() > 0 )
		bRet = true;
 	return bRet;
}

//----------------------------------------------------------------------------
bool CSqliteDatabase::searchTypePosition(const QStringList qslFields, CSqliteDatabase::structUniqueKey &sUKey)
{
 	bool bRet = false;
	for( short i = 0; (i < qslFields.count()) && (bRet == false); i++ )
	{
		//20131213 attention il faut eviter les nom contenant deja un autre champ
		// exemple PatientID et Patient
		if( qslFields.at(i).contains(sUKey.qsFieldName) == true )
		{
			sUKey.ucFieldPosition = i;
			if( (qslFields.at(i).toUpper().contains("INTEGER") == true)
				|| (qslFields.at(i).contains("SMALLINT") == true) )
			{
				sUKey.qsFieldType = "INTEGER";
			}
			else if( (qslFields.at(i).toUpper().contains("VARCHAR") == true)
				|| (qslFields.at(i).toUpper().contains("TEXT") == true) 
				|| (qslFields.at(i).toUpper().contains("CHAR") == true) )
			{
				sUKey.qsFieldType = "VARCHAR";
			}
			bRet = true;
		}
	}
	return bRet;
}


//----------------------------------------------------------------------------
// permet de lire la ligne de commamde qui a permis de creer la table
// et de stocker dans une liste la structure complete de la table
//----------------------------------------------------------------------------
QList<CSqliteDatabase::structTable> CSqliteDatabase::DBgetStructTableWithDetails(QString qsTableName)
{
	QSqlRecord tbl_record;

	structTable sTable;
	if( m_lstStructTable.isEmpty() == false )
	{
		m_lstStructTable.clear();
	}
	
	tbl_record = m_DB.record(qsTableName);

    QString qsExec = "select sql from sqlite_master where type = 'table' and name = '" + qsTableName + "'";
	QSqlQuery query;
	query = m_DB.exec(qsExec);
	QStringList qslSQLfields;
	unsigned short usSize=1;
	if( query.first() == true )
	{
		QString qsResult = query.value(0).toString();
		qsResult = qsResult.replace('\t', ' ');
		qslSQLfields = qsResult.split(",");
		//il faut remettre en forme les enregistrements avec DECIMAL car ils ont une virgule
		//donc ils ont ete splites
		for( short i = 0; i < qslSQLfields.count(); i++ )
		{
			if(qslSQLfields.at(i).toUpper().contains("DECIMAL") == true )
			{
				QString qsNew;
				qsNew = qslSQLfields.at(i) + QString::fromAscii(".") + qslSQLfields.at(i+1);
				qslSQLfields.replace(i, qsNew);
				qslSQLfields.removeAt(i+1);
			}
		}
		for( short i = 0; (i < tbl_record.count()) && (i < qslSQLfields.count()); i++ )
		{
			if( qslSQLfields.at(i).toUpper().contains("INTEGER") == true )
			{
				sTable.qsFieldType = "INTEGER";
				usSize=10;
			}
			else if(qslSQLfields.at(i).toUpper().contains("SMALLINT") == true )
			{
				sTable.qsFieldType = extractSize("SMALLINT", qslSQLfields.at(i), usSize);
			}
			else if(qslSQLfields.at(i).toUpper().contains("DECIMAL") == true )
			{
				sTable.qsFieldType = extractSize("DECIMAL", qslSQLfields.at(i), usSize);
			}
			else if(qslSQLfields.at(i).toUpper().contains("NUMBER") == true )
			{
				sTable.qsFieldType = extractSize("NUMBER", qslSQLfields.at(i), usSize);
			}
			else if(qslSQLfields.at(i).toUpper().contains("BOOL") == true )
			{
				sTable.qsFieldType = "BOOL";
				usSize=2;
			}
			else if(qslSQLfields.at(i).toUpper().contains("DATE") == true )
			{
				sTable.qsFieldType = "DATE";
				usSize=10;
			}
			else if( qslSQLfields.at(i).toUpper().contains("VARCHAR") == true )
			{
				sTable.qsFieldType = extractSize("VARCHAR", qslSQLfields.at(i), usSize);
			}
			else if(qslSQLfields.at(i).toUpper().contains("CHAR") == true )
			{
				sTable.qsFieldType = extractSize("CHAR", qslSQLfields.at(i), usSize);
			}

			sTable.qsFieldName = tbl_record.fieldName(i);
			sTable.byFieldSize = usSize;
			m_lstStructTable.append(sTable);
		}
	}
	return m_lstStructTable;
}


//----------------------------------------------------------------------------
QString CSqliteDatabase::extractSize(const QString qsType, const QString qsInput, unsigned short &usSizeResult)
{
	QString qsRet = "????", qsResult;
	short index;
	index = qsInput.toUpper().indexOf(qsType);
	if( index > 0 )
	{
		qsResult = qsInput.mid(index+qsType.length(), qsInput.length() - (index + qsType.length()));
		short index1, index2;
		index1 = qsResult.indexOf("(");
		index2 = qsResult.indexOf(")");
		if( (index1 >= 0) && ( index2 >= 0) && ((index1+1) != (index2)))
		{
			qsResult = qsResult.mid(index1+1, index2-(index1+1));
			qsRet = qsType + " " + qsResult;
			if( qsType == "DECIMAL" )
			{
				usSizeResult = 10;
			}
			else
			{
				if( (usSizeResult = qsResult.toUShort()) < 2 )
					usSizeResult = 2; //sinon on voit rien
			}
		}
		else
			usSizeResult = 1;
	}
	else
		usSizeResult = 1;
	return qsRet;
}

//----------------------------------------------------------------------------
bool CSqliteDatabase::testExistenceElement(const QString &qsTable, QList<CSqliteDatabase::structTable> qlstFieldsStruct, QMap<QString, QString> qsMapFieldsValues)
{
	QString qsExec;
	QSqlQuery queryInsert;
	bool bExist = false;
	//test unique key
	QList<CSqliteDatabase::structUniqueKey> qsListUniqueSchema;
	if( getUniqueConstraintTableSchema(qsTable, qsListUniqueSchema) == true )
	{
		QSqlQuery queryTest;
		qsExec = "SELECT " + qsListUniqueSchema.at(0).qsFieldName;
		for( short i = 1; i < qsListUniqueSchema.count(); i++ )
		{
			qsExec = qsExec + "," + qsListUniqueSchema.at(i).qsFieldName;
		}
		qsExec = qsExec + " FROM " + qsTable + " WHERE ";
		qsExec = qsExec + qsListUniqueSchema.at(0).qsFieldName + "=";
		if( qsListUniqueSchema.at(0).qsFieldType.toUpper() == "VARCHAR" )
		{
			qsExec = qsExec + "'" + qsMapFieldsValues[qsListUniqueSchema.at(0).qsFieldName] + "'";
		}
		else
		{
			qsExec = qsExec + qsMapFieldsValues[qsListUniqueSchema.at(0).qsFieldName];
		}
		for( short i = 1; i < qsListUniqueSchema.count(); i++ )
		{
			qsExec = qsExec + " AND " + qsListUniqueSchema.at(i).qsFieldName + "=";
			if( qsListUniqueSchema.at(i).qsFieldType.toUpper() == "VARCHAR" )
			{
				qsExec = qsExec + "'" + qsMapFieldsValues[qsListUniqueSchema.at(i).qsFieldName] + "'";
			}
			else
			{
				qsExec = qsExec + qsMapFieldsValues[qsListUniqueSchema.at(i).qsFieldName];
			}
		}
		queryTest = m_DB.exec(qsExec);
		if( queryTest.first() == true )
		{//these data already exist we dont insert
			bExist = true;
		}
	}
	return bExist;
}

//----------------------------------------------------------------------------
QMap<QString, QString> CSqliteDatabase::copyTableStructToQMap(const QString &qsTable)
{
	QMap<QString, QString> qMapTableFields;
	QList<CSqliteDatabase::structTable> qlstTableStruct = DBgetStructTableWithDetails(qsTable);
	for( int i=0; i < qlstTableStruct.count(); i++ )
	{
		qMapTableFields.insert(qlstTableStruct.at(i).qsFieldName, "NULL");
	}
	return qMapTableFields;
}

//----------------------------------------------------------------------------
bool CSqliteDatabase::insertOrReplaceIntoTable(const QString &qsTable, QList<CSqliteDatabase::structTable> qlstFieldsStruct, QMap<QString, QString> qsMapFieldsValues)
{
	bool bRet = false;
	QString qsExec;
	QSqlQuery queryInsert;

	//insert or replace data
	/*qsExec = "INSERT OR REPLACE INTO " + qsTable + " (" + qlstFieldsStruct.at(0).qsFieldName;

	for( short j = 1; j < qlstFieldsStruct.count(); j++)
	{
		qsExec = qsExec + ", " + qlstFieldsStruct.at(j).qsFieldName;
	}
	qsExec = qsExec + ") VALUES (";*/

	qsExec = "INSERT OR REPLACE INTO " + qsTable + " VALUES (";
	for( short i = 0; i < qlstFieldsStruct.count(); i++ )
	{
		if( qsMapFieldsValues.contains(qlstFieldsStruct.at(i).qsFieldName) == true )
		{
			if( i == 0 )
			{
				if( qlstFieldsStruct.at(i).qsFieldType.toUpper().contains("CHAR") == true )
				{
					qsExec = qsExec + "'" + qsMapFieldsValues.value(qlstFieldsStruct.at(i).qsFieldName).trimmed().replace("'", "''") + "'";
				}
				else
				{
					qsExec = qsExec + qsMapFieldsValues.value(qlstFieldsStruct.at(i).qsFieldName);
				}
			}
			else
			{
				if(  qlstFieldsStruct.at(i).qsFieldType.toUpper().contains("DATE") == true )
				{
					qsExec = qsExec + ", '" + qsMapFieldsValues.value(qlstFieldsStruct.at(i).qsFieldName) + "'";
				}
				else if(qlstFieldsStruct.at(i).qsFieldType.toUpper().contains("CHAR") == true )
				{
					qsExec = qsExec + ", '" + qsMapFieldsValues.value(qlstFieldsStruct.at(i).qsFieldName).trimmed().replace("'", "''") + "'";
				}
				else
				{
					qsExec = qsExec + ", " + qsMapFieldsValues.value(qlstFieldsStruct.at(i).qsFieldName);
				}
			}
		}
		else
		{
			qsExec = qsExec + ", NULL";
		}
	}
	qsExec = qsExec + ")";

	queryInsert = m_DB.exec(qsExec);

	if( (bRet = testIfNoErrorOccurs(queryInsert)) == false )
	{
		m_qsLastErrorExplaination += "\n" + qsExec;
	}
	return bRet;
}