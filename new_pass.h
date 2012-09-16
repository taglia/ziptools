/**********************************************************************

	--- Qt Architect generated file ---

	File: new_pass.h
	Last generated: Tue Mar 9 11:12:28 1999

 *********************************************************************/

#ifndef new_pass_included
#define new_pass_included

#include "new_passData.h"

class new_pass : public new_passData
{
    Q_OBJECT

public:

    new_pass
    (
        QWidget* parent = NULL,
        const char* name = NULL,
	char* buf_arg = NULL
    );

    virtual ~new_pass();

private:
    char *buf;

private slots:
    virtual void ok_click();
    virtual void cancel_click(); 

};
#endif // new_pass_included
