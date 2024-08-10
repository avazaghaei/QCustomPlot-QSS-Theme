#include "zoomSettings.h"

zoomSettings *zoomSettings::getInstance()
{
    static zoomSettings* instance = nullptr;
    if(instance == nullptr)
        instance = new zoomSettings;
    return instance;
}

zoomSettings::zoomSettings()
{
    initPushButtons();
    initGroupBoxes();
    initSpacer();
    setForm();

    setConnections();
}

void zoomSettings::initPushButtons()
{
    btnZoomIn        = new QPushButton("Zoom In");
    btnZoomOut       = new QPushButton("Zoom Out");
    btnResetZoom     = new QPushButton("Reset Zoom");
    btnAreaSelection = new QPushButton("Area Selection");
}

void zoomSettings::initGroupBoxes()
{
    grbForm = new QGroupBox();
    grbForm->setTitle("Zoom Settinhgs");
}

void zoomSettings::initSpacer()
{
    spacerZoomSettings = new QSpacerItem(40, 130, QSizePolicy::Expanding, QSizePolicy::Minimum);
}

void zoomSettings::setForm()
{
    QGridLayout* grl = new QGridLayout();

    grl->addItem(spacerZoomSettings, 0, 0);

    grl->addWidget(btnZoomIn       , 1, 0);
    grl->addWidget(btnResetZoom    , 1, 1);

    grl->addWidget(btnZoomOut      , 2, 0);
    grl->addWidget(btnAreaSelection, 2, 1);

    grbForm->setLayout(grl);
}

void zoomSettings::setConnections()
{
    connect(btnZoomIn,        &QPushButton::clicked, this, &zoomSettings::signalZoomIn);
    connect(btnZoomOut,       &QPushButton::clicked, this, &zoomSettings::signalZoomOut);
    connect(btnAreaSelection, &QPushButton::clicked, this, &zoomSettings::signalAreaSelection);
    connect(btnResetZoom,     &QPushButton::clicked, this, &zoomSettings::signalResetZoom);
}
