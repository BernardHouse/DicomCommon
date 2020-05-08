#pragma once

#include <QtGui\QBrush>
#include <QtGui\QPalette>

/** A static helper class for modifying QPalette class.
 */
class FontManager {

public:

	enum Color {
		COLOR_RED,
		COLOR_GREEN,
		COLOR_BLUE,
		COLOR_BLACK		
	};

	static QPalette getPalette( Color windowTextColor ) {
		QPalette palette;
		QBrush brush;
		switch ( windowTextColor ) {
			case FontManager::COLOR_RED:
				brush.setColor( QColor( 255, 0, 0, 255 ) );
				brush.setStyle( Qt::SolidPattern );
				palette.setBrush( QPalette::Active, QPalette::WindowText, brush );
				palette.setBrush( QPalette::Inactive, QPalette::WindowText, brush );
				break;
			case FontManager::COLOR_GREEN:
				brush.setColor( QColor( 0, 85, 0, 255 ) );
				brush.setStyle( Qt::SolidPattern );
				palette.setBrush( QPalette::Active, QPalette::WindowText, brush );
				palette.setBrush( QPalette::Inactive, QPalette::WindowText, brush );
				break;
			case FontManager::COLOR_BLUE:
				brush.setColor( QColor( 0, 0, 255, 255 ) );
				brush.setStyle( Qt::SolidPattern );
				palette.setBrush( QPalette::Active, QPalette::WindowText, brush );
				palette.setBrush( QPalette::Inactive, QPalette::WindowText, brush );
				break;
			case FontManager::COLOR_BLACK:
				brush.setColor( QColor( 0, 0, 0, 255 ) );
				brush.setStyle( Qt::SolidPattern );
				palette.setBrush( QPalette::Active, QPalette::WindowText, brush );
				palette.setBrush( QPalette::Inactive, QPalette::WindowText, brush );
				break;
			default:
				break;
		}
		return palette;
	}
};
