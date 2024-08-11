#include "maniWindow.h"


maniWindow::maniWindow()
{

    init_classes();
    initMenuBar();
    initMenu();
    setMenuBar();
    setLeftComponents();
    setForm();
}

void maniWindow::init_classes()
{
    ClassCustomPlot   = myQCustomPlot::getInstance();
    ClassSettings     = settings::getInstance();
    ClassZoomSettings = zoomSettings::getInstance();
    ClassTheme        = new Theme();
}

void maniWindow::initMenuBar()
{
    menuBar = new QMenuBar;
    menuBar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
}

void maniWindow::initMenu()
{
    menu = new QMenu("Settings");
}

void maniWindow::setMenuBar()
{
    menu->addMenu(ClassTheme->menuThemeParent);
    menuBar->addMenu(menu);
}

void maniWindow::setLeftComponents()
{
    QVBoxLayout* vbl = new QVBoxLayout();
    vbl->addWidget(ClassCustomPlot->ClassCustomPlot);
    vbl->addLayout(ClassZoomSettings->hblForm);

    grbLeftComponent = new QGroupBox("QCustomPlot");
    grbLeftComponent->setLayout(vbl);
}

void maniWindow::setForm()
{
    QHBoxLayout* hbl = new QHBoxLayout();
    hbl->addWidget(grbLeftComponent,       5);
    hbl->addWidget(ClassSettings->grbForm, 1);

    QVBoxLayout* vbl = new QVBoxLayout();
    vbl->addWidget(menuBar);
    vbl->addLayout(hbl);
    this->setLayout(vbl);


    this->show();

    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
}
