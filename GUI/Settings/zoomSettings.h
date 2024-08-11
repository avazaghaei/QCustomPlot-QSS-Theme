#ifndef ZOOMSETTINGS_H
#define ZOOMSETTINGS_H

/*!
  Core libraries that are needed
 */
#include <QObject>
#include <QPushButton>
#include <QGroupBox>
#include <QGridLayout>


class zoomSettings : public QObject
{
    Q_OBJECT
private:
//Variables

//GUI Elements

    //push buttons
    QPushButton* btnZoomIn;
    QPushButton* btnZoomOut;
    QPushButton* btnResetZoom;
    QPushButton* btnAreaSelection;

/***********************************************************/
//Functions

    /*!
     * \brief Instantiate custom push buttons
     */
    void initPushButtons();

    /*!
     * \brief Instantiate custom group boxes
     */
    void initGroupBoxes();

    /*!
     * \brief Configure complete form layout and components
     */
    void setForm();

    /*!
     * \brief Establish object relationships and dependencies
     */
    void setConnections();

public:
//GUI Elements

    /*!
     * \brief Expose object for external configuration
     */
    QGroupBox* grbForm;

    /*!
     * \brief Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.
     * Enforce single instance and global access point
     * \return
     */
    static zoomSettings* getInstance();


    zoomSettings();


    QHBoxLayout* hblForm;

signals:
    /*!
     * \brief Enable plot magnification
     */
    void signalZoomIn();

    /*!
     * \brief Enable plot reduction
     */
    void signalZoomOut();

    /*!
     * \brief Interactive plot area selection
     */
    void signalAreaSelection();

    /*!
     * \brief Interactive plot area selection
     */
    void signalResetZoom();
};

#endif // ZOOMSETTINGS_H
