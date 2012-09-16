/**********************************************************************

	--- Qt Architect generated file ---

	File: old_pass.cc
	Last generated: Tue Mar 9 11:13:25 1999

 *********************************************************************/

#include "old_pass.h"

#define Inherited old_passData

old_pass::old_pass
(
	QWidget* parent,
	const char* name,
	char* buf_arg
)
	:
	Inherited( parent, name )
{
  if(buf_arg == NULL)
    {
      done(0);
      return;
    }
  buf = buf_arg;
}


old_pass::~old_pass()
{
}

void old_pass::ok_click()
{
  if(!buf)
    done(-1);
  strcpy( buf , pass->text());
  done(1);
}

void old_pass::cancel_click()
{
  done(0);
}
