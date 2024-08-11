#ifndef MANIWINDOW_H
#define MANIWINDOW_H

#include <QWidget>
/*!
  Core libraries that are needed
 */
#include <QGridLayout>

/*!
  Custom classes for efficient handling
 */
#include <GUI/QCustomPlot/myQCustomPlot.h>
#include <GUI/Settings/settings.h>
#include <GUI/Settings/zoomSettings.h>
#include "GUI/Theme/Theme.h"

class maniWindow : public QWidget
{
private:
    //Classes
    myQCustomPlot* ClassCustomPlot;
    settings*      ClassSettings;
    zoomSettings*  ClassZoomSettings;
    Theme*         ClassTheme;

    //menu
    QMenuBar* menuBar;
    QMenu*    menu;

    QGroupBox* grbLeftComponent;


    //functions
    void init_classes();
    void initMenuBar();
    void initMenu();
    void setMenuBar();
    void setLeftComponents();
    void setForm();


public:
    maniWindow();
};

#endif // MANIWINDOW_H
