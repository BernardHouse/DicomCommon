#pragma once

#include <QWidget.h>

/** The application's main class, containing the entry point.
 */
class EDAPdicom {

public:

	EDAPdicom();
	~EDAPdicom();

	bool checkExternalDependencies( QWidget* maindWnd );

private:

//	void registerMetatypes();


};
