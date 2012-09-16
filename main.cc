#include <qapplication.h>
#include <qobject.h>
#include <qmessagebox.h>

#include <unistd.h>

#include "main_dlg.h"


main(int argc, char *argv[])
{
  QApplication app( argc , argv );

  if( geteuid() != 0 )
    {
      QMessageBox::critical( 0, "ZipTools",
			    "This program must be executed by root\n"
			     "or owned by root and made \"chmod u+s\"");
      return -1;
    }

  main_dlg md(0,"main_dialog");

  QObject::connect( &md , SIGNAL(fine()) , &app , SLOT(quit()) );
  
  app.setMainWidget( &md );
  md.show();

  return app.exec();
}
