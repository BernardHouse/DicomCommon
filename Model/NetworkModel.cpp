#include "NetworkModel.h"
#include "Defines.h"

//--------------------- Worklist ------------------------------------------------------------
NetworkWorklistServerModel::NetworkWorklistServerModel() : AbstractQueryModel( 0, 6, 0 )
{
	setHeaderData( ServerIdColumn			, Qt::Horizontal, "UNIQUE WLSid");
	setHeaderData( ServerNameColumn			, Qt::Horizontal, tr("Remote Server name") );
	setHeaderData( ServerAETitleColumn		, Qt::Horizontal, tr("Remote AETitle") );
	setHeaderData( ServerIPHostnameColumn	, Qt::Horizontal, tr("Remote Ip or hostname") );
	setHeaderData( ServerPortNumberColumn	, Qt::Horizontal, tr("Remote Port number") );
	setHeaderData( ServerEnableColumn		, Qt::Horizontal, tr("Enabled") );
//	setHeaderData( ServerHospitalIdColumn	, Qt::Horizontal, tr("Hospital Id") );
				   
}

NetworkWorklistServerModel::~NetworkWorklistServerModel()
{
}

void NetworkWorklistServerModel::insertDICOMDataset( DICOMDataset dataset )
{
	QMutexLocker locker( &mutex );

	QStandardItem* item;
	QList<QStandardItem*> items;

	item = new QStandardItem( dataset.getValue(txtWLSid, false));
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtServerName, false) );	 
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtAETitle, false));			 
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtIPAddHostname, false));	 
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtPortNumber, false));		
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtEnabled, false));		
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	appendRow( items );

}

/*QVariant NetworkWorklistServerModel::data( const QModelIndex &index, int role ) const
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


//--------------------- Store Image ------------------------------------------------------------
NetworkStoreImageServerModel::NetworkStoreImageServerModel() : AbstractQueryModel( 0, 6, 0 )
{
	setHeaderData( ServerIdColumn			, Qt::Horizontal, "UNIQUE SISid" );
	setHeaderData( ServerNameColumn			, Qt::Horizontal, tr("Remote Server name") );
	setHeaderData( ServerAETitleColumn		, Qt::Horizontal, tr("Remote AETitle") );
	setHeaderData( ServerIPHostnameColumn	, Qt::Horizontal, tr("Remote Ip or hostname") );
	setHeaderData( ServerPortNumberColumn	, Qt::Horizontal, tr("Remote Port number") );
	setHeaderData( ServerEnableColumn		, Qt::Horizontal, tr("Enabled") );
//	setHeaderData( ServerHospitalIdColumn	, Qt::Horizontal, tr("Hospital Id") );
}

NetworkStoreImageServerModel::~NetworkStoreImageServerModel()
{
}

void NetworkStoreImageServerModel::insertDICOMDataset( DICOMDataset dataset )
{
	QMutexLocker locker( &mutex );

	QStandardItem* item;
	QList<QStandardItem*> items;

	item = new QStandardItem( dataset.getValue(txtSISid, false));		
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtServerName, false));	 
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtAETitle, false));			 
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtIPAddHostname, false));	 
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtPortNumber, false));		
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	item = new QStandardItem( dataset.getValue(txtEnabled, false));		
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	items.append( item );

	appendRow( items );

}


/*
QVariant NetworkStoreImageServerModel::data( const QModelIndex &index, int role ) const
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