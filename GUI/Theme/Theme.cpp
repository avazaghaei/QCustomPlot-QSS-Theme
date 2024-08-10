#include "Theme.h"

Theme::Theme(QWidget *parent) : QWidget(parent)
{
    strAddressCustomQSS   = ":/QSS/Source/Folder_QSS/Custom_QSS/";
    strAddressStandardQSS = ":/QSS/Source/Folder_QSS/Standard_QSS/";
    initMenu();
    setMenu();
    setConnection();

//    actDiffnes->toggled(true);
    actPrevious = actDiffnes;
    actDiffnes->setChecked(true);


}

void Theme::initMenu()
{
    menuThemeParent     = new QMenu("Theme");
    menuThemeChildDark  = new QMenu("Dark");
    menuThemeChildLight = new QMenu("Light");

    menuThemeParent->addMenu(menuThemeChildDark);
    menuThemeParent->addMenu(menuThemeChildLight);

}

void Theme::setMenu()
{
    QAction** listActionDark[11] =
    {
        //dark
        &actDiffnes  , &actFibrary, &actConsoleStyle, &actChatbee,
        &actCombinear, &actDarkeum, &actPhotoxo     , &actSpyBot,
        &actTakezo   , &actWebmas , &actWStartpage,
    };
    for (int counterAct=0; counterAct<11; counterAct++)
    {
        *listActionDark[counterAct] = new QAction;
        (*listActionDark[counterAct])->setCheckable(true);
        (*listActionDark[counterAct])->setText("Dark " + QString::number(counterAct + 1));
        menuThemeChildDark->addAction(*listActionDark[counterAct]);
    }



    QAction** listActionLight[9] =
    {
        //light
        &actElegantDark, &actMacOS , &actClocker, &actDtor,
        &actExcelOffice, &actMailsy, &actMedize , &actPicPax,
        &actToolery
    };
    for (int counterAct=0; counterAct<9; counterAct++)
    {
        *listActionLight[counterAct] = new QAction;
        (*listActionLight[counterAct])->setCheckable(true);
        (*listActionLight[counterAct])->setText("Light " + QString::number(counterAct + 1));
        menuThemeChildLight->addAction(*listActionLight[counterAct]);
    }
}

void Theme::setConnection()
{
    connect(actDiffnes     , &QAction::toggled, this, &Theme::slotDiffnes);
    connect(actFibrary     , &QAction::toggled, this, &Theme::slotFibrary);
    connect(actConsoleStyle, &QAction::toggled, this, &Theme::slotConsoleStyle);
    connect(actElegantDark , &QAction::toggled, this, &Theme::slotElegantDark);
    connect(actMacOS       , &QAction::toggled, this, &Theme::slotMacOS);
    connect(actChatbee     , &QAction::toggled, this, &Theme::slotChatbee);
    connect(actClocker     , &QAction::toggled, this, &Theme::slotClocker);
    connect(actCombinear   , &QAction::toggled, this, &Theme::slotCombinear);
    connect(actDarkeum     , &QAction::toggled, this, &Theme::slotDarkeum);
    connect(actDtor        , &QAction::toggled, this, &Theme::slotDtor);
    connect(actExcelOffice , &QAction::toggled, this, &Theme::slotExcelOffice);
    connect(actMailsy      , &QAction::toggled, this, &Theme::slotMailsy);
    connect(actMedize      , &QAction::toggled, this, &Theme::slotMedize);
    connect(actPhotoxo     , &QAction::toggled, this, &Theme::slotPhotoxo);
    connect(actPicPax      , &QAction::toggled, this, &Theme::slotPicPax);
    connect(actSpyBot      , &QAction::toggled, this, &Theme::slotSpyBot);
    connect(actTakezo      , &QAction::toggled, this, &Theme::slotTakezo);
    connect(actToolery     , &QAction::toggled, this, &Theme::slotToolery);
    connect(actWebmas      , &QAction::toggled, this, &Theme::slotWebmas);
    connect(actWStartpage  , &QAction::toggled, this, &Theme::slotWStartpage);
}

void Theme::slotDiffnes()
{
    file.setFileName(strAddressStandardQSS + "Diffnes.qss");
    uncheckedPreviousAction(actDiffnes);
    setStyleSheet();

}

void Theme::slotFibrary()
{
    file.setFileName(strAddressStandardQSS + "Fibrary.qss");
    uncheckedPreviousAction(actFibrary);
    setStyleSheet();

}

void Theme::slotConsoleStyle()
{
    file.setFileName(strAddressCustomQSS + "ConsoleStyle.qss");
    uncheckedPreviousAction(actConsoleStyle);
    setStyleSheet();

}

void Theme::slotElegantDark()
{
    file.setFileName(strAddressCustomQSS + "ElegantDark.qss");
    uncheckedPreviousAction(actElegantDark);
    setStyleSheet();

}

void Theme::slotMacOS()
{
    file.setFileName(strAddressCustomQSS + "MacOS.qss");
    uncheckedPreviousAction(actMacOS);
    setStyleSheet();
}

void Theme::slotChatbee()
{
    file.setFileName(strAddressStandardQSS + "Chatbee.qss");
    uncheckedPreviousAction(actChatbee);
    setStyleSheet();
}

void Theme::slotClocker()
{
    file.setFileName(strAddressStandardQSS + "Clocker.qss");
    uncheckedPreviousAction(actClocker);
    setStyleSheet();
}

void Theme::slotCombinear()
{
    file.setFileName(strAddressStandardQSS + "Combinear.qss");
    uncheckedPreviousAction(actCombinear);
    setStyleSheet();
}

void Theme::slotDarkeum()
{
    file.setFileName(strAddressStandardQSS + "Darkeum.qss");
    uncheckedPreviousAction(actDarkeum);
    setStyleSheet();
}

void Theme::slotDtor()
{
    file.setFileName(strAddressStandardQSS + "Dtor.qss");
    uncheckedPreviousAction(actDtor);
    setStyleSheet();
}

void Theme::slotExcelOffice()
{
    file.setFileName(strAddressStandardQSS + "ExcelOffice.qss");
    uncheckedPreviousAction(actExcelOffice);
    setStyleSheet();
}

void Theme::slotMailsy()
{
    file.setFileName(strAddressStandardQSS + "MailSy.qss");
    uncheckedPreviousAction(actMailsy);
    setStyleSheet();
}

void Theme::slotMedize()
{
    file.setFileName(strAddressStandardQSS + "Medize.qss");
    uncheckedPreviousAction(actMedize);
    setStyleSheet();
}

void Theme::slotPhotoxo()
{
    file.setFileName(strAddressStandardQSS + "Photoxo.qss");
    uncheckedPreviousAction(actPhotoxo);
    setStyleSheet();
}

void Theme::slotPicPax()
{
    file.setFileName(strAddressStandardQSS + "PicPax.qss");
    uncheckedPreviousAction(actPicPax);
    setStyleSheet();
}

void Theme::slotSpyBot()
{
    file.setFileName(strAddressStandardQSS + "SpyBot.qss");
    uncheckedPreviousAction(actSpyBot);
    setStyleSheet();
}

void Theme::slotTakezo()
{
    file.setFileName(strAddressStandardQSS + "Takezo.qss");
    uncheckedPreviousAction(actTakezo);
    setStyleSheet();
}

void Theme::slotToolery()
{
    file.setFileName(strAddressStandardQSS + "Toolery.qss");
    uncheckedPreviousAction(actToolery);
    setStyleSheet();
}

void Theme::slotWebmas()
{
    file.setFileName(strAddressStandardQSS + "Webmas.qss");
    uncheckedPreviousAction(actWebmas);
    setStyleSheet();
}

void Theme::slotWStartpage()
{
    file.setFileName(strAddressStandardQSS + "Wstartpage.qss");
    uncheckedPreviousAction(actWStartpage);
    setStyleSheet();
}

void Theme::setStyleSheet()
{
    file.open(QFile::ReadOnly);

    QString styleSheet = file.readAll();

    QApplication* app;
    app->setStyleSheet(styleSheet);

    file.close();
}

void Theme::uncheckedPreviousAction(QAction *act)
{
    if(actPrevious != act)
    {
        actPrevious->setCheckable(false);
        actPrevious->setCheckable(true);
        actPrevious = act;
    }
    else
    {
        actPrevious->setChecked(true);
    }
}
