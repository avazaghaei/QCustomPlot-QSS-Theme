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
    setForm();

    setConnections();
}

void zoomSettings::initPushButtons()
{
    btnZoomIn        = new QPushButton("Zoom In");
    btnZoomOut       = new QPushButton("Zoom Out");
    btnResetZoom     = new QPushButton("Reset Zoom");
    btnAreaSelection = new QPushButton("Area Selection");

    const int n = 4;
    QPushButton* lstDoubleSpinBoxes[n] =
    {
        btnZoomIn, btnZoomOut, btnResetZoom, btnAreaSelection
    };

    for(int i = 0; i < n; ++i)
    {
        lstDoubleSpinBoxes[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    }
}

void zoomSettings::initGroupBoxes()
{
    grbForm = new QGroupBox();
    grbForm->setTitle("Zoom Settinhgs");
}

void zoomSettings::setForm()
{
    hblForm = new QHBoxLayout();

    hblForm->addWidget(btnZoomIn);
    hblForm->addWidget(btnResetZoom);
    hblForm->addWidget(btnZoomOut);
    hblForm->addWidget(btnAreaSelection);
}

void zoomSettings::setConnections()
{
    connect(btnZoomIn,        &QPushButton::clicked, this, &zoomSettings::signalZoomIn);
    connect(btnZoomOut,       &QPushButton::clicked, this, &zoomSettings::signalZoomOut);
    connect(btnAreaSelection, &QPushButton::clicked, this, &zoomSettings::signalAreaSelection);
    connect(btnResetZoom,     &QPushButton::clicked, this, &zoomSettings::signalResetZoom);
}
