#pragma once

#include <QtGui/QTreeView>
#include <QtGui/QTableView>
#include <QtGui\QMessageBox>
#include <QtGui/QApplication>


/** A static helper class
 */
class Tools {

public:

	static bool isOneTreeViewLineSelected(const QTreeView *tv, QWidget *qw=NULL )
	{	
		bool bIsOneLineSelected = tv->selectionModel()->hasSelection();
		if( bIsOneLineSelected == false && qw != NULL )
		{
			QMessageBox::warning(qw,"EDAPdicom", QApplication::tr("You must select a element before !!"), QMessageBox::Ok);
		}
		return bIsOneLineSelected;
	}
	static bool isOneTableViewLineSelected(const QTableView *tv, QWidget *qw=NULL )
	{	
		bool bIsOneLineSelected = tv->selectionModel()->hasSelection();
		if( bIsOneLineSelected == false && qw != NULL )
		{
			QMessageBox::warning(qw,"EDAPdicom", QApplication::tr("You must select a element before !!"), QMessageBox::Ok);
		}
		return bIsOneLineSelected;
	}
	static QString upperCaseFirst(const QString qsToModify )
	{	//separation de la string en word et non word
		QRegExp regExp("\\W\\w");
		QString qsModified = qsToModify;
		int pos=-1;
		qsModified = qsModified.toLower();
		QChar * base = qsModified.data();
		QChar * ch;
		do
		{
			pos++;
			ch = base + pos;
			pos = qsModified.indexOf(regExp, pos);
			*ch = ch->toUpper();
		}while(pos >= 0);
		return qsModified;
	}

	static QString removeStringBetween(const QString &_qsToModify, const QString &_qsFirst, const QString &_qsEnd)
	{	
		QString qsModified = _qsToModify;
		int posFirst = _qsToModify.indexOf(_qsFirst, 0);
		if( posFirst > 0 )
		{
			int posEnd = _qsToModify.indexOf(_qsEnd, posFirst);
			if( posEnd > 0 )
			{
				qsModified = qsModified.remove(posFirst, (posEnd-posFirst+1));
				qsModified = qsModified.trimmed();
			}
		}
		return qsModified;
	}

};
