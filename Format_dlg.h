/**********************************************************************

	--- Qt Architect generated file ---

	File: Format_dlg.h
	Last generated: Tue Mar 9 11:13:05 1999

 *********************************************************************/

#ifndef Format_dlg_included
#define Format_dlg_included

#include "Format_dlgData.h"
#include "config_dlg.h"

class Format_dlg : public Format_dlgData
{
    Q_OBJECT

public:

    Format_dlg
    (
        QWidget* parent = NULL,
        const char* name = NULL,
	const char* dev_name_arg = NULL,
	const struct fmt_config *fmt_cfg_arg = NULL
    );

    virtual ~Format_dlg();

private:

    char dev_name[50];
    struct fmt_config *fmt_cfg;

    int system(const char *command);

private slots:

    virtual void format_click();
    virtual void cancel_click();

};
#endif // Format_dlg_included
