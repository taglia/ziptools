/**********************************************************************

	--- Qt Architect generated file ---

	File: config_dlgData.h
	Last generated: Tue Mar 16 12:30:10 1999

	DO NOT EDIT!!!  This file will be automatically
	regenerated by qtarch.  All changes will be lost.

 *********************************************************************/

#ifndef config_dlgData_included
#define config_dlgData_included

#include <qdialog.h>
#include <qlined.h>

class config_dlgData : public QDialog
{
    Q_OBJECT

public:

    config_dlgData
    (
        QWidget* parent = NULL,
        const char* name = NULL
    );

    virtual ~config_dlgData();

public slots:


protected slots:

    virtual void echo_br();
    virtual void cancel_click();
    virtual void sfdisk_br();
    virtual void save_click();
    virtual void mkdosfs_br();
    virtual void mke2fs_br();
    virtual void delete_click();
    virtual void dd_br();

protected:
    QLineEdit* sfdisk_pos;
    QLineEdit* dd_pos;
    QLineEdit* mkdosfs_pos;
    QLineEdit* mke2fs_pos;
    QLineEdit* echo_pos;

};

#endif // config_dlgData_included