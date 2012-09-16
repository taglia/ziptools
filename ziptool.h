#ifndef ziptool_included
#define ziptool_included

/* this is ugly and should not be here - but the SCSI include files are
   moving around ...
*/
#define SCSI_IOCTL_SEND_COMMAND 1

#define RW   0
#define RO   2
#define PWRO 3
#define PW   5

class zip
{

 public:

  zip( const char *name = NULL );
  virtual ~zip();

  enum err { ok , non_zip , inquiry , mot , door , ioctl_err , prot_err ,
	     non_scsi , mtab_access , mounted , open_err };

  int testMode();
  void setMode( int mod , const char* oldpass , const char* newpass );
  void eject( bool ej );
  bool modeChanged();
  err error();
  void deviceName( char* name );

 private:

  int zfd;
  char devName[30];
  bool ejectOnQuit;
  err errorCode;
  bool changed;
  struct sdata {
    int  inlen;
    int  outlen;
    char cmd[256];
  } scsi_cmd;

  bool is_mounted();
  bool is_raw_scsi();
  bool is_zip();
  bool motor( int mode );
  bool unlockdoor();
  void ejectDisk();
  
};

#endif
