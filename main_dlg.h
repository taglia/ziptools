/**********************************************************************

	--- Qt Architect generated file ---

	File: main_dlg.h
	Last generated: Tue Mar 9 11:12:48 1999

 *********************************************************************/

#ifndef main_dlg_included
#define main_dlg_included

#include <qpopupmenu.h>

#include "main_dlgData.h"

#include "config_dlg.h"

#include "ziptool.h"

class main_dlg : public main_dlgData
{
    Q_OBJECT

public:

    main_dlg
    (
        QWidget* parent = NULL,
        const char* name = NULL
    );

    virtual ~main_dlg();

private:

    zip *Zip;
    struct fmt_config fmt_cfg;

    bool error( zip::err code );

private slots:

    virtual void ch_click();
    virtual void format_click();
    virtual void quit_click();
    virtual void dev_changed(const char* dname);
    virtual void ej_click();
    virtual void config_click();

signals:

    void fine(void);

};
#endif // main_dlg_included
