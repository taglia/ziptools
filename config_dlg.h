/**********************************************************************

	--- Qt Architect generated file ---

	File: config_dlg.h
	Last generated: Wed Mar 10 16:24:20 1999

 *********************************************************************/

#ifndef config_dlg_included
#define config_dlg_included

#include "config_dlgData.h"

struct fmt_config
{
  bool ok;
  bool dos_ok;
  bool e2_ok;
  QString *sfdisk_pos;
  QString *dd_pos;
  QString *mke2fs_pos;
  QString *mkdosfs_pos;
  QString *echo_pos;
};

bool readConfig(QWidget *, struct fmt_config *c);

class config_dlg : public config_dlgData
{
    Q_OBJECT

public:

    config_dlg
    (
        QWidget* parent = NULL,
        const char* name = NULL,
	struct fmt_config *fcfg = NULL
    );

    virtual ~config_dlg();

private:

    struct fmt_config *fmt_cfg;
    bool chkpos();

private slots:

    virtual void delete_click();
    virtual void cancel_click();
    virtual void save_click();
    virtual void sfdisk_br();
    virtual void dd_br();
    virtual void mke2fs_br();
    virtual void mkdosfs_br();
    virtual void echo_br();
 
};
#endif // config_dlg_included
