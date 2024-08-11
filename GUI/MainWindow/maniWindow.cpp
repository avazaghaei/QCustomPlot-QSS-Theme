#include "maniWindow.h"


maniWindow::maniWindow()
{

    init_classes();
    setLeftComponents();
    setRightComponents();
    setForm();
}

void maniWindow::init_classes()
{
    ClassCustomPlot   = myQCustomPlot::getInstance();
    ClassSettings     = settings::getInstance();
    ClassZoomSettings = zoomSettings::getInstance();
}

void maniWindow::setLeftComponents()
{
    QVBoxLayout* vbl = new QVBoxLayout();
    vbl->addWidget(ClassCustomPlot->ClassCustomPlot);
    vbl->addLayout(ClassZoomSettings->hblForm);

    grbLeftComponent = new QGroupBox("QCustomPlot");
    grbLeftComponent->setLayout(vbl);
}

void maniWindow::setRightComponents()
{
    QHBoxLayout* grl = new QHBoxLayout();
    grl->addWidget(grbLeftComponent,       5);
    grl->addWidget(ClassSettings->grbForm, 1);

    grbForm = new QGroupBox();
    grbForm->setLayout(grl);
}

void maniWindow::setForm()
{
    QGridLayout* l = new QGridLayout;
    l->addWidget(grbForm);

    this->setLayout(l);
    this->show();

    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
}
