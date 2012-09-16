/**********************************************************************

	--- Qt Architect generated file ---

	File: Format_dlg.cc
	Last generated: Tue Mar 9 11:13:05 1999

 *********************************************************************/

#include "Format_dlg.h"
#include "ziptool.h"

#include <qmessagebox.h>
#include <qprogressdialog.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define Inherited Format_dlgData

Format_dlg::Format_dlg
(
	QWidget* parent,
	const char* name,
	const char* dev_name_arg,
	const struct fmt_config *fmt_cfg_arg
)
	:
	Inherited( parent, name )
{
	setCaption( "ZipTools: Disk format" );
	strcpy( dev_name , dev_name_arg );
	if(!fmt_cfg_arg)
	  return;
	fmt_cfg = (struct fmt_config *)fmt_cfg_arg;
}


Format_dlg::~Format_dlg()
{
}

void Format_dlg::cancel_click()
{
  done(0);
}

void Format_dlg::format_click()
{
  int rs;
  char cmd[500];

  if( !strcmp( fs_type->currentText() , "ext2" ) &&
      !fmt_cfg->e2_ok )
    {
      QMessageBox::critical( this, "ZipTools",
			     "You haven't configured the "
			     "program for ext2 formatting !");
      return;
    }

  if( !strcmp( fs_type->currentText() , "dos" ) &&
      !fmt_cfg->dos_ok )
    {
      QMessageBox::critical( this, "ZipTools",
			     "You haven't configured the "
			     "program for dos formatting !");
      return;
    }


  if( QMessageBox::warning( this, "ZipTools",
			    "This is the last warning !\n"
			    "Everything on the disk will be destroyed !",
			    "&Format","&Cancel",0,0,1) == 1 )
      return;

  if( strcmp( fs_type->currentText() , "ext2" ) )
    {
      sprintf( cmd , "%s -e \"0 0\n0 0\n0 0\n0,,6\" | %s -D %s > /dev/null 2>&1",
	       (const char *)(*(fmt_cfg->echo_pos)),
	       (const char *)(*(fmt_cfg->sfdisk_pos)),
	       dev_name );
      rs = system(cmd);
      if(rs != 0)
	{
	  QMessageBox::critical( this, "ZipTools",
				    "Cannot partition the disk !");
	  done(0);
	  return;
	}

      sprintf( cmd , "%s if=/dev/zero of=%s4 bs=512 count=1 > /dev/null 2>&1",
	       (const char *)(*(fmt_cfg->dd_pos)),
	       dev_name );
      rs = system(cmd);
      if(rs != 0)
	{
	  QMessageBox::critical( this, "ZipTools",
				    "Error in making the partition DOS compatible !");
	  done(0);
	  return;
	}

      sprintf( cmd , "%s %s4 > /dev/null 2>&1",
	       (const char *)(*(fmt_cfg->mkdosfs_pos)),
	       dev_name );
      rs = system(cmd);
      if(rs != 0)
	{
	  QMessageBox::critical( this, "ZipTools",
				 "Error in creating the DOS file system !");
	  done(0);
	  return;
	}
    }
  else
    {
      sprintf( cmd , "%s -e \"0,,83\n0 0\n0 0\n0 0\" | %s -L %s > /dev/null 2>&1",
	       (const char *)(*(fmt_cfg->echo_pos)),
	       (const char *)(*(fmt_cfg->sfdisk_pos)),
	       dev_name );
      rs = system(cmd);
      if(rs != 0)
	{
	  QMessageBox::critical( this, "ZipTools",
				 "Cannot partition the disk !");
	  done(0);
	  return;
	}

      sprintf( cmd , "%s %s1 > /dev/null 2>&1",
	       (const char *)(*(fmt_cfg->mke2fs_pos)),
	       dev_name );
      rs = system(cmd);
      if(rs != 0)
	{
	  QMessageBox::critical( this, "ZipTools",
				 "Error in creating the ext2 file system !");
	  done(0);
	  return;
	}
    }
  done(0);
}

int Format_dlg::system(const char *command)
{
  int pid, status;

  if (command == 0)
    return 1;
  pid = fork();
  if (pid == -1)
    return -1;
  if (pid == 0) {
    char *argv[4];
    argv[0] = "sh";
    argv[1] = "-c";
    argv[2] = (char *)command;
    argv[3] = 0;
    char *env[1];
    env[0] = 0;
    execve("/bin/sh", argv, env);
    exit(127);
  }
  do {
    if (waitpid(pid, &status, 0) == -1)
      {
	if (errno != EINTR)
	  return -1;
      }
    else
      return status;
  } while(1);
}
