/**********************************************************************

	--- Qt Architect generated file ---

	File: main_dlg.cc
	Last generated: Tue Mar 9 11:12:48 1999

 *********************************************************************/

#include "main_dlg.h"
#include "Format_dlg.h"
#include "old_pass.h"
#include "new_pass.h"
#include "config_dlg.h"
#include "ziptools.xpm"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <qmessagebox.h>
#include <qpopupmenu.h>
#include <qpixmap.h>

#define Inherited main_dlgData

main_dlg::main_dlg
(
	QWidget* parent,
	const char* name
)
	:
	Inherited( parent, name )
{
  int rs;

  QPixmap pmap((const char **)ziptools);

  icona->setPixmap(pmap);

  fmt_cfg.ok = false;
  fmt_cfg.sfdisk_pos  = new QString(101);
  fmt_cfg.dd_pos      = new QString(101);
  fmt_cfg.mke2fs_pos  = new QString(101);
  fmt_cfg.mkdosfs_pos = new QString(101);
  fmt_cfg.echo_pos = new QString(101);

  Zip = new zip("/dev/sda");
  rs = Zip->testMode();

  if(Zip->error() == zip::ok)
    {
      switch(rs)
	{
	case RW:
	  rw_Button->setChecked(TRUE);
	  cur_mode->setText("rw");
	  break;
	case RO:
	  ro_Button->setChecked(TRUE);
	  cur_mode->setText("ro");
	  break;
	case PWRO:
	  pwro_Button->setChecked(TRUE);
	  cur_mode->setText("pwro");
	  break;
	case PW:
	  pw_Button->setChecked(TRUE);
	  cur_mode->setText("pw");
	  break;
	}
    }
  else
    {
      delete Zip;
      Zip=NULL;
      dev_name->setCurrentItem(8);
    }

  QPopupMenu *menu = new QPopupMenu;
  menu->insertItem( "Change Mode", this , SLOT(ch_click()) );
  menu->insertItem( "Eject Disk", this , SLOT(ej_click()) );
  menu->insertSeparator();
  menu->insertItem( "Configure", this , SLOT(config_click()) );
  menu->insertItem( "Format Disk", this , SLOT(format_click()) );
  menu->insertSeparator();
  menu->insertItem( "Quit", this , SLOT(quit_click()) );

  mbar->insertItem( "Menu" , menu );

  rs = readConfig(this, &fmt_cfg);
  if(rs)
    fmt_cfg.ok=true;
}


main_dlg::~main_dlg()
{
}

void main_dlg::ch_click()
{
  char oldpass[34] = "" , newpass[34] = "";
  int oldmode , newmode;

  if(!Zip)
    {
      QMessageBox::warning( this, "ZipTools",
			    "No device selected !" );
      return;
    }

  oldmode = Zip->testMode();
  if( error( Zip->error() ) )
      return;
  
  if( rw_Button->isChecked() )
    newmode = RW;
  else if( ro_Button->isChecked() )
    newmode = RO;
  else if( pwro_Button->isChecked() )
    newmode = PWRO;
  else
    newmode = PW;

  if( 1 & oldmode )
    {
      old_pass pw( this , 0 , oldpass );
      if( pw.exec() <= 0 )
	return;
    }
  
  if( 1 & newmode )
    {
      new_pass pw2( this , 0 , newpass );
      if( pw2.exec() <= 0 )
	return;
    }

  Zip->setMode( newmode , oldpass , newpass );
  if( error( Zip->error() ) )
    {
      oldmode = Zip->testMode();
      if( error( Zip->error() ) )
	{
	  rw_Button->setChecked(FALSE);
	  ro_Button->setChecked(FALSE);
	  pwro_Button->setChecked(FALSE);
	  pw_Button->setChecked(FALSE);
	  cur_mode->setText("");
	  dev_name->setCurrentItem(8);

	  delete Zip;
	  Zip=NULL;
	}
      switch(oldmode)
	{
	case RW:
	  rw_Button->setChecked(TRUE);
	  cur_mode->setText("rw");
	  break;
	case RO:
	  ro_Button->setChecked(TRUE);
	  cur_mode->setText("ro");
	  break;
	case PWRO:
	  pwro_Button->setChecked(TRUE);
	  cur_mode->setText("pwro");
	  break;
	case PW:
	  pw_Button->setChecked(TRUE);
	  cur_mode->setText("pw");
	  break;
	}
    }
  switch(newmode)
    {
    case RW:
      cur_mode->setText("rw");
      break;
    case RO:
      cur_mode->setText("ro");
      break;
    case PWRO:
      cur_mode->setText("pwro");
      break;
    case PW:
      cur_mode->setText("pw");
      break;
    }
}

void main_dlg::dev_changed(const char* dname)
{
  int rs;
  
  rw_Button->setChecked(FALSE);
  ro_Button->setChecked(FALSE);
  pwro_Button->setChecked(FALSE);
  pw_Button->setChecked(FALSE);
  cur_mode->setText("");

  if( !strcmp( dname , "--device--" ) )
    {
      if(Zip)
	{
	  delete Zip;
	  Zip = NULL;
	}
      return;
    }

  if(Zip)
    {
      delete Zip;
      Zip = NULL;
    }
  Zip = new zip(dname);

  if( error( Zip->error() ) )
    {
      dev_name->setCurrentItem(8);
      delete Zip;
      Zip = NULL;
      return;
    }

  rs = Zip->testMode();
  if( error( Zip->error() ) )
    {
      delete Zip;
      Zip = NULL;
      dev_name->setCurrentItem(8);
      return;
    }

  rs = Zip->testMode();
  if( error( Zip->error() ) )
    {
      return;
    }
  switch(rs)
    {
    case RW:
      rw_Button->setChecked(TRUE);
      cur_mode->setText("rw");
      break;
    case RO:
      ro_Button->setChecked(TRUE);
      cur_mode->setText("ro");
      break;
    case PWRO:
      pwro_Button->setChecked(TRUE);
      cur_mode->setText("pwro");
      break;
    case PW:
      pw_Button->setChecked(TRUE);
      cur_mode->setText("pw");
      break;
    }
}

void main_dlg::quit_click()
{
  if(!Zip)
    {
      emit fine();
      return;
    }

  if( (rw_Button->isChecked() && strcmp(cur_mode->text(),"rw")) ||
      (ro_Button->isChecked() && strcmp(cur_mode->text(),"ro")) ||
      (pwro_Button->isChecked() && strcmp(cur_mode->text(),"pwro")) ||
      (pw_Button->isChecked() && strcmp(cur_mode->text(),"pw")) )
    switch( QMessageBox::information( this , "ZipTools" , 
				  "Change mode before quitting ?",
				  "Yes" ,
				  "No" ,
				  "Cancel" , 
				  0, 2) )
      {
      case 0:
	ch_click();
      case 1:
	break;
      case 2:
	return;
      }

  if( Zip->modeChanged() )
    switch( QMessageBox::information( this , "ZipTools" , 
				      "The mode has been changed,\n"
				      "the disk has to be ejected." , 
				      "Eject now" ,
				      "Quit" ,
				      "Cancel" , 
				      0, 2) )
      {
      case 0:
	Zip->eject(TRUE);
      case 1:
	break;
      }
  delete Zip;
  emit fine();
}

void main_dlg::ej_click()
{
  if(!Zip)
    {
      QMessageBox::warning( this, "ZipTools",
			    "No device selected !" );
      return;
    }
  Zip->eject(TRUE);
  delete Zip;
  Zip=0;

  rw_Button->setChecked(FALSE);
  ro_Button->setChecked(FALSE);
  pwro_Button->setChecked(FALSE);
  pw_Button->setChecked(FALSE);
  cur_mode->setText("");
  dev_name->setCurrentItem(8);
}

void main_dlg::format_click()
{ 
  int rs;
  char tempname[30];

  if( !fmt_cfg.ok )
    {
      QMessageBox::warning( this, "ZipTools",
			    "You haven't configured the program yet !" );
      return;
    }

  if(!Zip)
    {
      QMessageBox::warning( this, "ZipTools",
			    "No device selected !" );
      return;
    }

  rs = Zip->testMode();
  if( error( Zip->error() ) )
    return;
  
  if( rs != RW )
    {
      QMessageBox::information( this, "ZipTools",
				"The disk is not in Read Write mode !");
      return;
    }

  if( Zip->modeChanged() )
    {
      QMessageBox::information( this, "ZipTools",
				"Protection mode changed !\n"
				"You have to eject and reload the disk before formatting.");
      return;
    }

  Zip->deviceName(tempname);
  delete Zip;
  Zip=0;
  Format_dlg format(this, "", tempname , &fmt_cfg);
  format.exec();
  Zip = new zip(tempname);
}

bool main_dlg::error( zip::err code )
{
  switch(code)
    {
    case zip::non_zip:
      QMessageBox::warning( this, "ZipTools",
			    "Device is not an IOMEGA ZIP drive !" );
      return TRUE;
    case zip::inquiry:
      QMessageBox::warning( this, "ZipTools",
			    "Inquiry ioctl error !" );
      return TRUE;
    case zip::mot:
      QMessageBox::warning( this, "ZipTools",
			    "Motor control ioctl error !" );
      return TRUE;
    case zip::door:
      QMessageBox::warning( this, "ZipTools",
			    "Unlock door ioctl error !" );
      return TRUE;
    case zip::ioctl_err:
      QMessageBox::warning( this, "ZipTools",
			    "Non-sense ioctl error !" );
      return TRUE;
    case zip::prot_err:
      QMessageBox::warning( this, "ZipTools",
			    "Set protection mode ioctl error" );
      return TRUE;
    case zip::non_scsi:
      QMessageBox::warning( this, "ZipTools",
			    "Not a raw SCSI device !" );
      return TRUE;
    case zip::mtab_access:
      QMessageBox::warning( this, "ZipTools",
			    "Unable to access /etc/mtab !" );
      return TRUE;
    case zip::mounted:
      QMessageBox::warning( this, "ZipTools",
			    "Device is mounted !" );
      return TRUE;
    case zip::open_err:
      QMessageBox::warning( this, "ZipTools",
			    "Unable to open device !" );
      return TRUE;
    case zip::ok:
      return FALSE;
    }
}

void main_dlg::config_click()
{
  if( getuid() != 0 )
    {
      QMessageBox::information( 0, "ZipTools",
			     "To configure this program you must be root (no suid).");
      return;
    }

  config_dlg cd(this, "conf", &fmt_cfg);
  cd.exec();
}
