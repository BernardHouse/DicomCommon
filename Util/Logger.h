#pragma once

#include <QMutex>

/** A logger class.
 */
class Logger {

public:

	static Logger* instance();
	virtual ~Logger();

	void dbg( QString msg );
	void dbg( const char* str, ... );

protected:

	QMutex mutex;

private:

	Logger();
	Logger& operator=( Logger& ); // disallowed
	Logger( const Logger& ); // disallowed

	static Logger loggerSingleton;

};
