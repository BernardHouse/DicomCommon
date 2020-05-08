#include "Logger.h"

#include <QDateTime>

#include <iostream>

Logger* Logger::instance() {
	return &loggerSingleton;
}

Logger::Logger() {
}

Logger::~Logger() {
}

void Logger::dbg( QString msg ) {
	dbg( msg.toStdString().c_str() );
}

void Logger::dbg( const char* msg, ... ) {

	QMutexLocker locker( &mutex );
    va_list args;
	va_start( args, msg );
	QString content;
	content.vsprintf( msg, args );
	va_end( args );
	
	// also print to stdout (should be redirected to debug console window)
	std::cout << QDateTime::currentDateTime().toString( "hh:mm:ss" ).toStdString() << ": ";
	std::cout << content.toStdString() << "\n";

}

// static member initialization
Logger Logger::loggerSingleton;
