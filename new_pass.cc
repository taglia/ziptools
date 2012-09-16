/**********************************************************************

	--- Qt Architect generated file ---

	File: new_pass.cc
	Last generated: Tue Mar 9 11:12:28 1999

 *********************************************************************/

#include "new_pass.h"

#include <qmessagebox.h>

#define Inherited new_passData

new_pass::new_pass
(
	QWidget* parent,
	const char* name,
	char* buf_arg
)
	:
	Inherited( parent, name )
{
  if( buf_arg == NULL)
    {
      done(0);
      return;
    }
  buf = buf_arg;
}


new_pass::~new_pass()
{
}

void new_pass::ok_click()
{ 
  if(strcmp( pass->text() , repass->text() ))
    {
      QMessageBox::warning( this, "ZipTools",
			    "You typed different passwords !" );
      return;
    }
  strcpy( buf , pass->text());
  done(1);
}

void new_pass::cancel_click()
{
  done(0);
}
