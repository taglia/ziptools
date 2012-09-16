/**********************************************************************

	--- Qt Architect generated file ---

	File: old_pass.h
	Last generated: Tue Mar 9 11:13:25 1999

 *********************************************************************/

#ifndef old_pass_included
#define old_pass_included

#include "old_passData.h"

class old_pass : public old_passData
{
    Q_OBJECT

public:

    old_pass
    (
        QWidget* parent = NULL,
        const char* name = NULL,
	char* buf_arg = NULL
    );

    virtual ~old_pass();

private:

    char *buf;

private slots:

    virtual void ok_click();
    virtual void cancel_click(); 

};
#endif // old_pass_included
