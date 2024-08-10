#ifndef THEME_H
#define THEME_H

#include <QWidget>
#include <QAction>
#include <QActionGroup>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QFile>
#include <QVBoxLayout>

class Theme : public QWidget
{
    Q_OBJECT
public:
    explicit Theme(QWidget *parent = nullptr);
    QMenu* menuThemeParent;
private:

    QString strAddressCustomQSS;
    QString strAddressStandardQSS;

    QMenu* menuThemeChildDark;
    QMenu* menuThemeChildLight;

    QFile   file;

    QAction* actDiffnes;
    QAction* actFibrary;
    QAction* actConsoleStyle;
    QAction* actElegantDark;
    QAction* actMacOS;
    QAction* actChatbee;
    QAction* actClocker;
    QAction* actCombinear;
    QAction* actDarkeum;
    QAction* actDtor;
    QAction* actExcelOffice;
    QAction* actMailsy;
    QAction* actMedize;
    QAction* actPhotoxo;
    QAction* actPicPax;
    QAction* actSpyBot;
    QAction* actTakezo;
    QAction* actToolery;
    QAction* actWebmas;
    QAction* actWStartpage;

    QAction* actPrevious;

private:
    void setMenu();
    void initMenu();
    void setMenubar();
    void setConnection();

    void setStyleSheet();

    void uncheckedPreviousAction(QAction* act);


private slots:
    void slotDiffnes();
    void slotFibrary();
    void slotConsoleStyle();
    void slotElegantDark();
    void slotMacOS();
    void slotChatbee();
    void slotClocker();
    void slotCombinear();
    void slotDarkeum();
    void slotDtor();
    void slotExcelOffice();
    void slotMailsy();
    void slotMedize();
    void slotPhotoxo();
    void slotPicPax();
    void slotSpyBot();
    void slotTakezo();
    void slotToolery();
    void slotWebmas();
    void slotWStartpage();
};

#endif // THEME_H
