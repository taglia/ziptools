#include <stdio.h>
#include <mntent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "ziptool.h"

bool zip::is_mounted()
/* -1 = error,  0 = not mounted,  1 = mounted */
{  
  struct mntent *mp;
  FILE *mtab;
  
  mtab = setmntent("/etc/mtab","r");
  if (!mtab) return -1;
  while (mp=getmntent(mtab)) 
    if (!strncmp(mp->mnt_fsname,devName,8)) break;
  endmntent(mtab);
  return (mp != NULL);
}

bool zip::is_raw_scsi( )
{
  return ((strlen(devName) == 8) && (strncmp("/dev/sd",devName,7) == 0));
}

bool zip::is_zip( )
{
  char	id[25];
  int	i;
  
  scsi_cmd.inlen = 0;
  scsi_cmd.outlen = 40;
  scsi_cmd.cmd[0] = 0x12;		/* inquiry */
  scsi_cmd.cmd[1] = 0;
  scsi_cmd.cmd[2] = 0;
  scsi_cmd.cmd[3] = 0;
  scsi_cmd.cmd[4] = 40;
  scsi_cmd.cmd[5] = 0;
  
  if (ioctl(zfd,SCSI_IOCTL_SEND_COMMAND,(void *)&scsi_cmd))
    return -1;
  
  for(i=0;i<24;i++) id[i] = scsi_cmd.cmd[i+8];
  id[24] = 0;
  
  return(!strncmp(id,"IOMEGA  ZIP 100",15));
}

bool zip::motor( int mode )
{
  scsi_cmd.inlen = 0;
  scsi_cmd.outlen = 0;
  scsi_cmd.cmd[0] = 0x1b;		/* start/stop */
  scsi_cmd.cmd[1] = 0;
  scsi_cmd.cmd[2] = 0;
  scsi_cmd.cmd[3] = 0;
  scsi_cmd.cmd[4] = mode;
  scsi_cmd.cmd[5] = 0;
  
  if (ioctl(zfd,SCSI_IOCTL_SEND_COMMAND,(void *)&scsi_cmd))
    return 0;
  return 1;
}

bool zip::unlockdoor( )
{	
  scsi_cmd.inlen = 0;
  scsi_cmd.outlen = 0;
  scsi_cmd.cmd[0] = 0x1e;		/* prevent/allow media removal */
  scsi_cmd.cmd[1] = 0;
  scsi_cmd.cmd[2] = 0;
  scsi_cmd.cmd[3] = 0;
  scsi_cmd.cmd[4] = 0;
  scsi_cmd.cmd[5] = 0;
  
  if (ioctl(zfd,SCSI_IOCTL_SEND_COMMAND,(void *)&scsi_cmd))
    return 0;
  return 1;
}

void zip::ejectDisk ( )
{	
  if(!unlockdoor( ))
    errorCode = door;
  
  if(!motor(1))
    errorCode = mot;
  if(!motor(2))
    errorCode = mot;
}

void zip::deviceName( char* name )
{
  if( name != NULL )
    strcpy( name , devName );
}

bool zip::modeChanged()
{
  return changed;
}

int zip::testMode()
{
  int mod;
  
  scsi_cmd.inlen = 0;
  scsi_cmd.outlen = 256;
  scsi_cmd.cmd[0] = 6;		/* Iomega non-sense command */
  scsi_cmd.cmd[1] = 0;
  scsi_cmd.cmd[2] = 2;
  scsi_cmd.cmd[3] = 0;
  scsi_cmd.cmd[4] = 128;
  scsi_cmd.cmd[5] = 0;
  
  if (ioctl(zfd,SCSI_IOCTL_SEND_COMMAND,(void *)&scsi_cmd))
    errorCode = ioctl_err;
  
  return (scsi_cmd.cmd[21] & 0x0f);	/* protection code */
}

void zip::setMode( int mod , const char *oldpass , const char *newpass)
{
  int	i, len;

  if( testMode() == mod )
    return;

  if( errorCode != ok )
    return;
  
  changed = true;
  len = strlen(oldpass);
  
  scsi_cmd.inlen = len;
  scsi_cmd.outlen = 0;
  scsi_cmd.cmd[0] = 0x0c;
  scsi_cmd.cmd[1] = 0;
  scsi_cmd.cmd[2] = 0;
  scsi_cmd.cmd[3] = 0;
  scsi_cmd.cmd[4] = len;
  scsi_cmd.cmd[5] = 0;
  
  for(i=0;i<len;i++) scsi_cmd.cmd[6+i] = oldpass[i];
  
  if (ioctl(zfd,SCSI_IOCTL_SEND_COMMAND,(void *)&scsi_cmd))
    {
      errorCode = prot_err;
      return;
    }

  len = strlen(newpass);
  
  scsi_cmd.inlen = len;
  scsi_cmd.outlen = 0;
  scsi_cmd.cmd[0] = 0x0c;
  scsi_cmd.cmd[1] = mod;
  scsi_cmd.cmd[2] = 0;
  scsi_cmd.cmd[3] = 0;
  scsi_cmd.cmd[4] = len;
  scsi_cmd.cmd[5] = 0;
  
  for(i=0;i<len;i++) scsi_cmd.cmd[6+i] = newpass[i];
  
  if (ioctl(zfd,SCSI_IOCTL_SEND_COMMAND,(void *)&scsi_cmd))
    {
      errorCode = prot_err;
      return;
    }
}

void zip::eject( bool ej )
{
  ejectOnQuit = ej;
}

enum zip::err zip::error()
{
  return errorCode;
}

zip::zip( const char *name )
{
  int rs;

  zfd = 0;
  errorCode = ok;
  changed = false;
  ejectOnQuit = false;

  strcpy(devName , name);

  if (!is_raw_scsi())
    {
      errorCode = non_scsi;
      return;
    }

  rs = is_mounted();
  if (rs == -1)
    {
      errorCode = mtab_access;
      return;
    }
  if (rs == 1)
    {
      errorCode = mounted;
      return;
    }
  
  zfd = open(name,0);  
  if (zfd < 0)
    {
      errorCode = open_err;
      return;
    }

  rs = is_zip();
  if (rs==0)
    {
      errorCode = non_zip;
      close(zfd);
      return;
    }
  else if(rs==-1)
    {
      errorCode = inquiry;
      close(zfd);
      return;
    }
}

zip::~zip()
{
  if( ejectOnQuit )
    ejectDisk();
  close(zfd);
}
