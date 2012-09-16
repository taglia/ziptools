/**********************************************************************

	--- Qt Architect generated file ---

	File: config_dlg.cc
	Last generated: Wed Mar 10 16:24:20 1999

 *********************************************************************/

#include "config_dlg.h"

#include <qfile.h>
#include <qfileinfo.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qdatastream.h>
#include <qiodevice.h>

#define Inherited config_dlgData

config_dlg::config_dlg
(
	QWidget* parent,
	const char* name,
	struct fmt_config *fcfg = NULL
)
	:
	Inherited( parent, name )
{
  setCaption( "ZipTools" );

  if( fcfg == NULL )
    return;

  fmt_cfg = fcfg;

  if(readConfig(this, fmt_cfg))
     {
       sfdisk_pos->setText( *(fmt_cfg->sfdisk_pos) );
       dd_pos->setText( *(fmt_cfg->dd_pos) );
       mke2fs_pos->setText( *(fmt_cfg->mke2fs_pos) );
       mkdosfs_pos->setText( *(fmt_cfg->mkdosfs_pos) );
       echo_pos->setText( *(fmt_cfg->echo_pos) );
     }
}


config_dlg::~config_dlg()
{
}

void config_dlg::delete_click()
{
  QFile f;
  f.remove("/etc/ziptools.conf");
  fmt_cfg->ok=false;
  done(0);
  return;
}

void config_dlg::cancel_click()
{
  readConfig(this, fmt_cfg);
  done(0);
  return;
}

void config_dlg::save_click()
{
  fmt_cfg->sfdisk_pos->setStr(sfdisk_pos->text());
  fmt_cfg->dd_pos->setStr(dd_pos->text());
  fmt_cfg->mke2fs_pos->setStr(mke2fs_pos->text());
  fmt_cfg->mkdosfs_pos->setStr(mkdosfs_pos->text());
  fmt_cfg->echo_pos->setStr(echo_pos->text());

  if( !chkpos() )
    return;

  fmt_cfg->ok = fmt_cfg->e2_ok | fmt_cfg->dos_ok;

  QFile f("/etc/ziptools.conf");
  if ( f.open(IO_WriteOnly) ) 
    {    // file opened successfully
      QDataStream s( &f );        // use a data stream
      s << *(fmt_cfg->sfdisk_pos);
      s << *(fmt_cfg->dd_pos);
      s << *(fmt_cfg->mke2fs_pos);
      s << *(fmt_cfg->mkdosfs_pos);
      s << *(fmt_cfg->echo_pos);
      f.close();
    }

  done(0);
  return;
}

bool config_dlg::chkpos()
{
  QFileInfo f;

  f.setFile( *(fmt_cfg->sfdisk_pos) );
  if( !f.exists() )
    {
      QMessageBox::warning( this, "ZipTools",
			    "sfdisk does not exist !" );
      return false;
    }

  f.setFile( *(fmt_cfg->dd_pos) );
  if( !f.exists() )
    {
      QMessageBox::warning( this, "ZipTools",
			    "dd does not exist !" );
      return false;
    }

  if( !fmt_cfg->mke2fs_pos->isEmpty() )
    {
      f.setFile( *(fmt_cfg->mke2fs_pos) );
      if( !f.exists() )
	{
	  QMessageBox::warning( this, "ZipTools",
				"mke2fs does not exist !\n"
				"If you don't need ext2 "
				"filesystem leave this field void.");
	  return false;
	}
      fmt_cfg->e2_ok = true;
    }
  else fmt_cfg->e2_ok = false;
  
  if( !fmt_cfg->mkdosfs_pos->isEmpty() )
    {
      f.setFile( *(fmt_cfg->mkdosfs_pos) );
      if( !f.exists() )
	{
	  QMessageBox::warning( this, "ZipTools",
				"mkdosfs does not exist !\n"
				"If you don't need fat leave "
				"this field void." );
	  return false;
	}
      fmt_cfg->dos_ok = true;
    }
  else fmt_cfg->dos_ok = false;

  f.setFile( *(fmt_cfg->echo_pos) );
  if( !f.exists() )
    {
      QMessageBox::warning( this, "ZipTools",
			    "echo does not exist !" );
      return false;
    }

  return true;
}

void config_dlg::sfdisk_br()
{
  sfdisk_pos->setText( QFileDialog::getOpenFileName("/sbin") );
}

void config_dlg::dd_br()
{
  dd_pos->setText( QFileDialog::getOpenFileName("/bin") );
}

void config_dlg::mke2fs_br()
{
  mke2fs_pos->setText( QFileDialog::getOpenFileName("/sbin") );
}

void config_dlg::mkdosfs_br()
{
  mkdosfs_pos->setText( QFileDialog::getOpenFileName("/sbin") );
}

void config_dlg::echo_br()
{
  echo_pos->setText( QFileDialog::getOpenFileName("/bin") );
}

bool readConfig(QWidget *parent, struct fmt_config *c)
{
  QFileInfo cinfo("/etc/ziptools.conf");
  if( !cinfo.exists() )
    return false;
  if( cinfo.ownerId() != 0 )
    {
      QMessageBox::warning( parent, "ZipTools",
			    "Config file not owned by root !" );
      return false;
    }

  QFile f("/etc/ziptools.conf");
  if ( f.open( IO_ReadOnly ) ) 
    {    // file opened successfully
      QDataStream s( &f );        // use a data stream
      s >> *(c->sfdisk_pos);
      s >> *(c->dd_pos);
      s >> *(c->mke2fs_pos);
      s >> *(c->mkdosfs_pos);
      s >> *(c->echo_pos);
      f.close();
      
      if( c->mke2fs_pos->isEmpty()  )
	c->e2_ok = false;
      else c->e2_ok = true;
      if( c->mkdosfs_pos->isEmpty() )
	c->dos_ok = false;
      else c->dos_ok = true;

      c->ok = c->e2_ok | c->dos_ok;
      return true;
    }
  return false;
}
