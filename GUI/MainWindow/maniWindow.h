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

class maniWindow : public QWidget
{
private:
    //Classes
    myQCustomPlot* ClassCustomPlot;
    settings*      ClassSettings;
    zoomSettings*  ClassZoomSettings;


    QGroupBox* grbLeftComponent;
    QGroupBox* grbForm;


    //functions
    void init_classes();
    void setLeftComponents();
    void setRightComponents();
    void setForm();


public:
    maniWindow();
};

#endif // MANIWINDOW_H
