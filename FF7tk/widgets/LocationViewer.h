/****************************************************************************/
//    copyright 2013  Chris Rizzitello <sithlord48@gmail.com>               //
//                                                                          //
//    This file is part of FF7tk                                            //
//                                                                          //
//    FF7tk is free software: you can redistribute it and/or modify         //
//    it under the terms of the GNU General Public License as published by  //
//    the Free Software Foundation, either version 3 of the License, or     //
//    (at your option) any later version.                                   //
//                                                                          //
//    FF7tk is distributed in the hope that it will be useful,              //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of        //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          //
//    GNU General Public License for more details.                          //
/****************************************************************************/
#ifndef LOCATIONVIEWER_H
#define LOCATIONVIEWER_H

#include "qglobal.h"
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    #include <QtWidgets>
#else
    #include <QtGui>
#endif
// Include FF7tk Items.
#include "../static_data/FF7Location.h"
class LocationViewer : public QWidget
{
    Q_OBJECT
public:
    explicit LocationViewer(QWidget *parent = 0);


signals:
    
public slots:
    void setAdvancedMode(bool AdvancedMode);

private slots:
    void itemChanged(int currentRow,int currentColumn,int prevRow, int prevColumn);

private:
    void init_display(void);
    void init_connections(void);


    QTableWidget *locationTable;
    FF7Location *Locations;
    QLabel * lblLocationPreview;
    bool advancedMode;
    bool showPreview;
};

#endif // LOCATIONVIEWER_H
