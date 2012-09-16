/**********************************************************************

	--- Qt Architect generated file ---

	File: config_dlgData.cc
	Last generated: Tue Mar 16 12:30:10 1999

	DO NOT EDIT!!!  This file will be automatically
	regenerated by qtarch.  All changes will be lost.

 *********************************************************************/

#include <qpixmap.h>
#include <qlayout.h>
#include "config_dlgData.h"

#define Inherited QDialog

#include <qlabel.h>
#include <qpushbt.h>
#include <qframe.h>

config_dlgData::config_dlgData
(
	QWidget* parent,
	const char* name
)
	:
	Inherited( parent, name, TRUE, 0 )
{
	QFrame* qtarch_Frame_1;
	qtarch_Frame_1 = new QFrame( this, "Frame_1" );
	qtarch_Frame_1->setGeometry( 30, 60, 340, 230 );
	qtarch_Frame_1->setMinimumSize( 0, 0 );
	qtarch_Frame_1->setMaximumSize( 32767, 32767 );
	qtarch_Frame_1->setFocusPolicy( QWidget::NoFocus );
	qtarch_Frame_1->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_Frame_1->setFontPropagation( QWidget::NoChildren );
	qtarch_Frame_1->setPalettePropagation( QWidget::NoChildren );
	qtarch_Frame_1->setFrameStyle( 33 );

	sfdisk_pos = new QLineEdit( this, "LineEdit_1" );
	sfdisk_pos->setGeometry( 60, 100, 130, 30 );
	sfdisk_pos->setMinimumSize( 0, 0 );
	sfdisk_pos->setMaximumSize( 32767, 32767 );
	sfdisk_pos->setFocusPolicy( QWidget::StrongFocus );
	sfdisk_pos->setBackgroundMode( QWidget::PaletteBase );
	sfdisk_pos->setFontPropagation( QWidget::NoChildren );
	sfdisk_pos->setPalettePropagation( QWidget::NoChildren );
	sfdisk_pos->setText( "/sbin/sfdisk" );
	sfdisk_pos->setMaxLength( 30 );
	sfdisk_pos->setEchoMode( QLineEdit::Normal );
	sfdisk_pos->setFrame( TRUE );

	dd_pos = new QLineEdit( this, "LineEdit_3" );
	dd_pos->setGeometry( 60, 170, 130, 30 );
	dd_pos->setMinimumSize( 0, 0 );
	dd_pos->setMaximumSize( 32767, 32767 );
	dd_pos->setFocusPolicy( QWidget::StrongFocus );
	dd_pos->setBackgroundMode( QWidget::PaletteBase );
	dd_pos->setFontPropagation( QWidget::NoChildren );
	dd_pos->setPalettePropagation( QWidget::NoChildren );
	dd_pos->setText( "/bin/dd" );
	dd_pos->setMaxLength( 30 );
	dd_pos->setEchoMode( QLineEdit::Normal );
	dd_pos->setFrame( TRUE );

	mkdosfs_pos = new QLineEdit( this, "LineEdit_4" );
	mkdosfs_pos->setGeometry( 220, 170, 130, 30 );
	mkdosfs_pos->setMinimumSize( 0, 0 );
	mkdosfs_pos->setMaximumSize( 32767, 32767 );
	mkdosfs_pos->setFocusPolicy( QWidget::StrongFocus );
	mkdosfs_pos->setBackgroundMode( QWidget::PaletteBase );
	mkdosfs_pos->setFontPropagation( QWidget::NoChildren );
	mkdosfs_pos->setPalettePropagation( QWidget::NoChildren );
	mkdosfs_pos->setText( "/sbin/mkdosfs" );
	mkdosfs_pos->setMaxLength( 30 );
	mkdosfs_pos->setEchoMode( QLineEdit::Normal );
	mkdosfs_pos->setFrame( TRUE );

	QLabel* qtarch_Label_1;
	qtarch_Label_1 = new QLabel( this, "Label_1" );
	qtarch_Label_1->setGeometry( 50, 70, 100, 30 );
	qtarch_Label_1->setMinimumSize( 0, 0 );
	qtarch_Label_1->setMaximumSize( 32767, 32767 );
	qtarch_Label_1->setFocusPolicy( QWidget::NoFocus );
	qtarch_Label_1->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_Label_1->setFontPropagation( QWidget::NoChildren );
	qtarch_Label_1->setPalettePropagation( QWidget::NoChildren );
	qtarch_Label_1->setLineWidth( 2 );
	qtarch_Label_1->setText( "sfdisk location:" );
	qtarch_Label_1->setAlignment( 289 );
	qtarch_Label_1->setMargin( -1 );

	QLabel* qtarch_Label_2;
	qtarch_Label_2 = new QLabel( this, "Label_2" );
	qtarch_Label_2->setGeometry( 50, 140, 100, 30 );
	qtarch_Label_2->setMinimumSize( 0, 0 );
	qtarch_Label_2->setMaximumSize( 32767, 32767 );
	qtarch_Label_2->setFocusPolicy( QWidget::NoFocus );
	qtarch_Label_2->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_Label_2->setFontPropagation( QWidget::NoChildren );
	qtarch_Label_2->setPalettePropagation( QWidget::NoChildren );
	qtarch_Label_2->setText( "dd location:" );
	qtarch_Label_2->setAlignment( 289 );
	qtarch_Label_2->setMargin( -1 );

	QLabel* qtarch_Label_3;
	qtarch_Label_3 = new QLabel( this, "Label_3" );
	qtarch_Label_3->setGeometry( 210, 140, 100, 30 );
	qtarch_Label_3->setMinimumSize( 0, 0 );
	qtarch_Label_3->setMaximumSize( 32767, 32767 );
	qtarch_Label_3->setFocusPolicy( QWidget::NoFocus );
	qtarch_Label_3->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_Label_3->setFontPropagation( QWidget::NoChildren );
	qtarch_Label_3->setPalettePropagation( QWidget::NoChildren );
	qtarch_Label_3->setText( "mkdosfs location:" );
	qtarch_Label_3->setAlignment( 289 );
	qtarch_Label_3->setMargin( -1 );

	QLabel* qtarch_Label_4;
	qtarch_Label_4 = new QLabel( this, "Label_4" );
	qtarch_Label_4->setGeometry( 210, 70, 100, 30 );
	qtarch_Label_4->setMinimumSize( 0, 0 );
	qtarch_Label_4->setMaximumSize( 32767, 32767 );
	qtarch_Label_4->setFocusPolicy( QWidget::NoFocus );
	qtarch_Label_4->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_Label_4->setFontPropagation( QWidget::NoChildren );
	qtarch_Label_4->setPalettePropagation( QWidget::NoChildren );
	qtarch_Label_4->setText( "mke2fs location:" );
	qtarch_Label_4->setAlignment( 289 );
	qtarch_Label_4->setMargin( -1 );

	mke2fs_pos = new QLineEdit( this, "LineEdit_2" );
	mke2fs_pos->setGeometry( 220, 100, 130, 30 );
	mke2fs_pos->setMinimumSize( 0, 0 );
	mke2fs_pos->setMaximumSize( 32767, 32767 );
	mke2fs_pos->setFocusPolicy( QWidget::StrongFocus );
	mke2fs_pos->setBackgroundMode( QWidget::PaletteBase );
	mke2fs_pos->setFontPropagation( QWidget::NoChildren );
	mke2fs_pos->setPalettePropagation( QWidget::NoChildren );
	mke2fs_pos->setText( "/sbin/mke2fs" );
	mke2fs_pos->setMaxLength( 30 );
	mke2fs_pos->setEchoMode( QLineEdit::Normal );
	mke2fs_pos->setFrame( TRUE );

	QPushButton* qtarch_PushButton_3;
	qtarch_PushButton_3 = new QPushButton( this, "PushButton_3" );
	qtarch_PushButton_3->setGeometry( 30, 300, 100, 30 );
	qtarch_PushButton_3->setMinimumSize( 0, 0 );
	qtarch_PushButton_3->setMaximumSize( 32767, 32767 );
	connect( qtarch_PushButton_3, SIGNAL(clicked()), SLOT(save_click()) );
	qtarch_PushButton_3->setFocusPolicy( QWidget::TabFocus );
	qtarch_PushButton_3->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_PushButton_3->setFontPropagation( QWidget::NoChildren );
	qtarch_PushButton_3->setPalettePropagation( QWidget::NoChildren );
	qtarch_PushButton_3->setText( "Save" );
	qtarch_PushButton_3->setAutoRepeat( FALSE );
	qtarch_PushButton_3->setAutoResize( FALSE );

	QPushButton* qtarch_PushButton_4;
	qtarch_PushButton_4 = new QPushButton( this, "PushButton_4" );
	qtarch_PushButton_4->setGeometry( 270, 300, 100, 30 );
	qtarch_PushButton_4->setMinimumSize( 0, 0 );
	qtarch_PushButton_4->setMaximumSize( 32767, 32767 );
	connect( qtarch_PushButton_4, SIGNAL(clicked()), SLOT(cancel_click()) );
	qtarch_PushButton_4->setFocusPolicy( QWidget::TabFocus );
	qtarch_PushButton_4->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_PushButton_4->setFontPropagation( QWidget::NoChildren );
	qtarch_PushButton_4->setPalettePropagation( QWidget::NoChildren );
	qtarch_PushButton_4->setText( "Cancel" );
	qtarch_PushButton_4->setAutoRepeat( FALSE );
	qtarch_PushButton_4->setAutoResize( FALSE );

	QLabel* qtarch_Label_5;
	qtarch_Label_5 = new QLabel( this, "Label_5" );
	qtarch_Label_5->setGeometry( 20, 20, 360, 30 );
	qtarch_Label_5->setMinimumSize( 0, 0 );
	qtarch_Label_5->setMaximumSize( 32767, 32767 );
	qtarch_Label_5->setFocusPolicy( QWidget::NoFocus );
	qtarch_Label_5->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_Label_5->setFontPropagation( QWidget::NoChildren );
	qtarch_Label_5->setPalettePropagation( QWidget::NoChildren );
	qtarch_Label_5->setFrameStyle( 33 );
	qtarch_Label_5->setText( "Format needs to know the position of the following programs:" );
	qtarch_Label_5->setAlignment( 292 );
	qtarch_Label_5->setMargin( -1 );

	echo_pos = new QLineEdit( this, "LineEdit_5" );
	echo_pos->setGeometry( 60, 240, 130, 30 );
	echo_pos->setMinimumSize( 130, 30 );
	echo_pos->setMaximumSize( 130, 30 );
	echo_pos->setFocusPolicy( QWidget::StrongFocus );
	echo_pos->setBackgroundMode( QWidget::PaletteBase );
	echo_pos->setFontPropagation( QWidget::NoChildren );
	echo_pos->setPalettePropagation( QWidget::NoChildren );
	echo_pos->setText( "/bin/echo" );
	echo_pos->setMaxLength( 30 );
	echo_pos->setEchoMode( QLineEdit::Normal );
	echo_pos->setFrame( TRUE );

	QLabel* qtarch_Label_6;
	qtarch_Label_6 = new QLabel( this, "Label_6" );
	qtarch_Label_6->setGeometry( 50, 210, 100, 30 );
	qtarch_Label_6->setMinimumSize( 0, 0 );
	qtarch_Label_6->setMaximumSize( 32767, 32767 );
	qtarch_Label_6->setFocusPolicy( QWidget::NoFocus );
	qtarch_Label_6->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_Label_6->setFontPropagation( QWidget::NoChildren );
	qtarch_Label_6->setPalettePropagation( QWidget::NoChildren );
	qtarch_Label_6->setText( "echo location:" );
	qtarch_Label_6->setAlignment( 289 );
	qtarch_Label_6->setMargin( -1 );

	QPushButton* qtarch_PushButton_6;
	qtarch_PushButton_6 = new QPushButton( this, "PushButton_6" );
	qtarch_PushButton_6->setGeometry( 150, 80, 40, 15 );
	qtarch_PushButton_6->setMinimumSize( 40, 15 );
	qtarch_PushButton_6->setMaximumSize( 40, 15 );
	{
		QFont font( "helvetica", 8, 50, 0 );
		font.setStyleHint( (QFont::StyleHint)0 );
		font.setCharSet( (QFont::CharSet)0 );
		qtarch_PushButton_6->setFont( font );
	}
	connect( qtarch_PushButton_6, SIGNAL(clicked()), SLOT(sfdisk_br()) );
	qtarch_PushButton_6->setFocusPolicy( QWidget::NoFocus );
	qtarch_PushButton_6->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_PushButton_6->setFontPropagation( QWidget::NoChildren );
	qtarch_PushButton_6->setPalettePropagation( QWidget::NoChildren );
	qtarch_PushButton_6->setText( "Browse" );
	qtarch_PushButton_6->setAutoRepeat( FALSE );
	qtarch_PushButton_6->setAutoResize( FALSE );

	QPushButton* qtarch_PushButton_11;
	qtarch_PushButton_11 = new QPushButton( this, "PushButton_11" );
	qtarch_PushButton_11->setGeometry( 150, 220, 40, 15 );
	qtarch_PushButton_11->setMinimumSize( 40, 15 );
	qtarch_PushButton_11->setMaximumSize( 40, 15 );
	{
		QFont font( "helvetica", 8, 50, 0 );
		font.setStyleHint( (QFont::StyleHint)0 );
		font.setCharSet( (QFont::CharSet)0 );
		qtarch_PushButton_11->setFont( font );
	}
	connect( qtarch_PushButton_11, SIGNAL(clicked()), SLOT(echo_br()) );
	qtarch_PushButton_11->setFocusPolicy( QWidget::NoFocus );
	qtarch_PushButton_11->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_PushButton_11->setFontPropagation( QWidget::NoChildren );
	qtarch_PushButton_11->setPalettePropagation( QWidget::NoChildren );
	qtarch_PushButton_11->setText( "Browse" );
	qtarch_PushButton_11->setAutoRepeat( FALSE );
	qtarch_PushButton_11->setAutoResize( FALSE );

	QPushButton* qtarch_PushButton_12;
	qtarch_PushButton_12 = new QPushButton( this, "PushButton_12" );
	qtarch_PushButton_12->setGeometry( 310, 150, 40, 15 );
	qtarch_PushButton_12->setMinimumSize( 40, 15 );
	qtarch_PushButton_12->setMaximumSize( 40, 15 );
	{
		QFont font( "helvetica", 8, 50, 0 );
		font.setStyleHint( (QFont::StyleHint)0 );
		font.setCharSet( (QFont::CharSet)0 );
		qtarch_PushButton_12->setFont( font );
	}
	connect( qtarch_PushButton_12, SIGNAL(clicked()), SLOT(mkdosfs_br()) );
	qtarch_PushButton_12->setFocusPolicy( QWidget::NoFocus );
	qtarch_PushButton_12->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_PushButton_12->setFontPropagation( QWidget::NoChildren );
	qtarch_PushButton_12->setPalettePropagation( QWidget::NoChildren );
	qtarch_PushButton_12->setText( "Browse" );
	qtarch_PushButton_12->setAutoRepeat( FALSE );
	qtarch_PushButton_12->setAutoResize( FALSE );

	QPushButton* qtarch_PushButton_13;
	qtarch_PushButton_13 = new QPushButton( this, "PushButton_13" );
	qtarch_PushButton_13->setGeometry( 150, 150, 40, 15 );
	qtarch_PushButton_13->setMinimumSize( 40, 15 );
	qtarch_PushButton_13->setMaximumSize( 40, 15 );
	{
		QFont font( "helvetica", 8, 50, 0 );
		font.setStyleHint( (QFont::StyleHint)0 );
		font.setCharSet( (QFont::CharSet)0 );
		qtarch_PushButton_13->setFont( font );
	}
	connect( qtarch_PushButton_13, SIGNAL(clicked()), SLOT(dd_br()) );
	qtarch_PushButton_13->setFocusPolicy( QWidget::NoFocus );
	qtarch_PushButton_13->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_PushButton_13->setFontPropagation( QWidget::NoChildren );
	qtarch_PushButton_13->setPalettePropagation( QWidget::NoChildren );
	qtarch_PushButton_13->setText( "Browse" );
	qtarch_PushButton_13->setAutoRepeat( FALSE );
	qtarch_PushButton_13->setAutoResize( FALSE );

	QPushButton* qtarch_PushButton_14;
	qtarch_PushButton_14 = new QPushButton( this, "PushButton_14" );
	qtarch_PushButton_14->setGeometry( 310, 80, 40, 15 );
	qtarch_PushButton_14->setMinimumSize( 40, 15 );
	qtarch_PushButton_14->setMaximumSize( 40, 15 );
	{
		QFont font( "helvetica", 8, 50, 0 );
		font.setStyleHint( (QFont::StyleHint)0 );
		font.setCharSet( (QFont::CharSet)0 );
		qtarch_PushButton_14->setFont( font );
	}
	connect( qtarch_PushButton_14, SIGNAL(clicked()), SLOT(mke2fs_br()) );
	qtarch_PushButton_14->setFocusPolicy( QWidget::NoFocus );
	qtarch_PushButton_14->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_PushButton_14->setFontPropagation( QWidget::NoChildren );
	qtarch_PushButton_14->setPalettePropagation( QWidget::NoChildren );
	qtarch_PushButton_14->setText( "Browse" );
	qtarch_PushButton_14->setAutoRepeat( FALSE );
	qtarch_PushButton_14->setAutoResize( FALSE );

	QPushButton* qtarch_PushButton_15;
	qtarch_PushButton_15 = new QPushButton( this, "PushButton_15" );
	qtarch_PushButton_15->setGeometry( 150, 300, 100, 30 );
	qtarch_PushButton_15->setMinimumSize( 0, 0 );
	qtarch_PushButton_15->setMaximumSize( 32767, 32767 );
	connect( qtarch_PushButton_15, SIGNAL(clicked()), SLOT(delete_click()) );
	qtarch_PushButton_15->setFocusPolicy( QWidget::TabFocus );
	qtarch_PushButton_15->setBackgroundMode( QWidget::PaletteBackground );
	qtarch_PushButton_15->setFontPropagation( QWidget::NoChildren );
	qtarch_PushButton_15->setPalettePropagation( QWidget::NoChildren );
	qtarch_PushButton_15->setText( "Delete cfg file" );
	qtarch_PushButton_15->setAutoRepeat( FALSE );
	qtarch_PushButton_15->setAutoResize( FALSE );

	resize( 400,350 );
	setMinimumSize( 400, 350 );
	setMaximumSize( 400, 350 );
}


config_dlgData::~config_dlgData()
{
}
void config_dlgData::save_click()
{
}
void config_dlgData::cancel_click()
{
}
void config_dlgData::sfdisk_br()
{
}
void config_dlgData::echo_br()
{
}
void config_dlgData::mkdosfs_br()
{
}
void config_dlgData::dd_br()
{
}
void config_dlgData::mke2fs_br()
{
}
void config_dlgData::delete_click()
{
}
