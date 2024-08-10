#include "settings.h"

settings *settings::getInstance()
{
    static settings* instance = nullptr;
    if(instance == nullptr)
        instance = new settings;
    return instance;
}

settings::settings()
{
    initLabels();
    initCheckBoxes();
    initSpinBoxes();
    initRadioButtons();
    initPushButtons();
    initGroupBoxes();

    setForm();
    setConnections();
}

void settings::initLabels()
{
    lblYaxisPlacement = new QLabel("Y-axis Placement:");
    lblScalingMode    = new QLabel("Scaling Mode:");
    lblXaxisRange     = new QLabel("X-axis Range:");
    lblYaxisRange     = new QLabel("Y-axis Range:");
    lblDeltaX         = new QLabel("Delta X:");
    lblDeltaY         = new QLabel("Delta Y:");

    const int n = 6;
    QLabel* lstLabels[n] =
    {
        lblYaxisPlacement, lblScalingMode, lblXaxisRange, lblYaxisRange, lblDeltaX, lblDeltaY
    };


    for(int i=0; i < n; ++i)
    {

        lstLabels[i]->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }
}

void settings::initCheckBoxes()
{
    chkbCustomTicks  = new QCheckBox("Custom Ticks");
    chkbEnablePointSelection   = new QCheckBox("Enable point selection mode");
    chkbReverseXaxis = new QCheckBox("Reverse x axis");
}


void settings::initSpinBoxes()
{
    dsbMaximumX   = new QDoubleSpinBox;
    dsbMinimumX   = new QDoubleSpinBox;
    dsbMaximumY   = new QDoubleSpinBox;
    dsbMinimumY   = new QDoubleSpinBox;
    sbCustomTicks = new QSpinBox;
    sbWidth       = new QSpinBox;
    sbHeight      = new QSpinBox;

    const int nn = 3;
    QSpinBox* lstSpinBoxes[nn] =
    {
        sbCustomTicks, sbWidth, sbHeight};

    for(int i = 0; i < nn; ++i)
    {
        lstSpinBoxes[i]->setAlignment(Qt::AlignLeft);
    }

    const int n = 4;
    QDoubleSpinBox* lstDoubleSpinBoxes[n] =
    {
        dsbMaximumX, dsbMinimumX, dsbMaximumY, dsbMinimumY
    };

    for(int i = 0; i < n; ++i)
    {
        lstDoubleSpinBoxes[i]->setAlignment(Qt::AlignLeft);
    }

    dsbMinimumX->setRange(0, 10000);
    dsbMaximumX->setRange(0, 10000);

    dsbMinimumY->setRange(0, 10000);
    dsbMaximumY->setRange(0, 10000);

    dsbMinimumX->setDisabled(true);
    dsbMaximumX->setDisabled(true);
    dsbMinimumY->setDisabled(true);
    dsbMaximumY->setDisabled(true);
}

void settings::initRadioButtons()
{
    rdBtnLeftAxis    = new QRadioButton("Left");
    rdBtnRightAxis   = new QRadioButton("Right");
    rdBtnAutoScale   = new QRadioButton("Auto Scale");
    rdBtnCustomScale = new QRadioButton("Custom Scale");

    QButtonGroup *rdBtnGroupPlacement = new QButtonGroup();
    QButtonGroup *rdBtnGroupScale     = new QButtonGroup();

    rdBtnGroupPlacement->addButton(rdBtnLeftAxis);
    rdBtnGroupPlacement->addButton(rdBtnRightAxis);

    rdBtnGroupScale->addButton(rdBtnAutoScale);
    rdBtnGroupScale->addButton(rdBtnCustomScale);

    rdBtnAutoScale->setChecked(true);
    rdBtnLeftAxis->setChecked(true);
}

void settings::initPushButtons()
{
    btnSavePlotImage = new QPushButton("Save Plot Image");
}

void settings::initGroupBoxes()
{
    grbForm = new QGroupBox();

    grbForm->setTitle("Settinhgs");
}

void settings::setForm()
{
    QGridLayout* grl = new QGridLayout();

    grl = new QGridLayout();
    grl->addWidget(lblYaxisPlacement , 0, 0);
    grl->addWidget(rdBtnLeftAxis     , 0, 1);
    grl->addWidget(rdBtnRightAxis    , 0, 2);

    grl->addWidget(lblScalingMode    , 1, 0);
    grl->addWidget(rdBtnAutoScale    , 1, 1);
    grl->addWidget(rdBtnCustomScale  , 1, 2);

    grl->addWidget(lblXaxisRange     , 2, 0);
    grl->addWidget(dsbMinimumX       , 2, 1);
    grl->addWidget(dsbMaximumX       , 2, 2);

    grl->addWidget(lblYaxisRange     , 3, 0);
    grl->addWidget(dsbMinimumY       , 3, 1);
    grl->addWidget(dsbMaximumY       , 3, 2);

    grl->addWidget(chkbCustomTicks   , 4, 0);
    grl->addWidget(sbCustomTicks     , 4, 1);

    grl->addWidget(chkbEnablePointSelection, 5, 0);
    grl->addWidget(lblDeltaX         , 5, 1);
    grl->addWidget(lblDeltaY         , 5, 2);

    grl->addWidget(chkbReverseXaxis  , 6, 0);

    grl->addWidget(btnSavePlotImage  , 7, 0);
    grl->addWidget(sbWidth           , 7, 1);
    grl->addWidget(sbHeight          , 7, 2);

    grbForm->setLayout(grl);

}

void settings::setConnections()
{
    {
        connect(rdBtnRightAxis, &QRadioButton::clicked, this, &settings::signalRightYAxis);
        connect(rdBtnLeftAxis,  &QRadioButton::clicked, this, &settings::signalLeftYAxis);
    }
    {
        connect(rdBtnCustomScale, &QRadioButton::clicked, this, &settings::slotRadioButtonCustomScale);
        connect(rdBtnAutoScale,   &QRadioButton::clicked, this, &settings::slotRadioButtonAutoScale);

        connect(dsbMinimumX, SIGNAL(valueChanged(double)), this, SLOT(slotSpinBox()));
        connect(dsbMaximumX, SIGNAL(valueChanged(double)), this, SLOT(slotSpinBox()));
        connect(dsbMinimumY, SIGNAL(valueChanged(double)), this, SLOT(slotSpinBox()));
        connect(dsbMaximumY, SIGNAL(valueChanged(double)), this, SLOT(slotSpinBox()));
    }
    {
        //custom Ticks
        connect(chkbCustomTicks, &QCheckBox::clicked,       this, &settings::slotSetTicks);
        connect(sbCustomTicks  , SIGNAL(valueChanged(int)), this, SLOT(slotSetTicks()));
    }
    {
        //save Image
        connect(btnSavePlotImage, &QCheckBox::clicked, this, &settings::slotSavePlotImage);
    }
    {
        //reverse x-axis
        connect(chkbReverseXaxis, &QCheckBox::clicked, this, &settings::slotReverseXAxis);
    }
    {
        //Enable point selection mode
        connect(chkbEnablePointSelection, &QCheckBox::clicked, this, &settings::signalEnablePointSelection);
    }
}

void settings::slotRadioButtonCustomScale()
{
    dsbMinimumX->setDisabled(false);
    dsbMaximumX->setDisabled(false);
    dsbMinimumY->setDisabled(false);
    dsbMaximumY->setDisabled(false);
}

void settings::slotSpinBox()
{
    double minX = dsbMinimumX->value();
    double maxX = dsbMaximumX->value();
    double minY = dsbMinimumY->value();
    double maxY = dsbMaximumY->value();

    emit signalSpinBox(minX, maxX, minY, maxY);
}

void settings::slotRadioButtonAutoScale()
{
    dsbMinimumX->setDisabled(true);
    dsbMaximumX->setDisabled(true);
    dsbMinimumY->setDisabled(true);
    dsbMaximumY->setDisabled(true);

    emit signalRadioButtonAutoScale();
}

void settings::slotSetTicks()
{
    if(chkbCustomTicks->isChecked())
    {

        signalSetTicks(sbCustomTicks->value());
    }
    else
    {
        signalSetTicks(0);
    }
}

void settings::slotSavePlotImage()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "/home/jana/untitled.png",
                                tr("Images (*.png *.xpm *.jpg)"));


    int width  = sbWidth->value();
    int height = sbHeight->value();
    signalSavePloImage(fileName, width, height, 1.0, -1);
}

void settings::slotReverseXAxis()
{
    if(chkbReverseXaxis->isChecked())
    {
        signalReverseXAxis(true);
    }
    else
    {
        signalReverseXAxis(false);
    }
}

void settings::slotSetValueDelta(double x, double y)
{
    lblDeltaX->setText("Delta X : " + QString::number(x));
    lblDeltaY->setText("Delta Y : " + QString::number(y));
}

void settings::slotReverseXAxisMenuRequest()
{
    chkbReverseXaxis->setChecked(!chkbReverseXaxis->isChecked());
    chkbReverseXaxis->clicked();
}

void settings::slotAddedPoint()
{
    if(rdBtnAutoScale->isChecked())
    {
        rdBtnAutoScale->clicked();
    }
}

