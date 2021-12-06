#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Crawler.h"
#include <QMainWindow>
#include <QTranslator>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>
#include <QTextBrowser>
#include <QToolBar>

// The application main window
class MainWindow : public QMainWindow
{
public:
  Crawler crawler;
  QTranslator *translator = new QTranslator();

  // Init panel & widgets
  QWidget *mainPanel = new QWidget();
  QWidget *articalTypeSelectPanel = new QWidget();
  QWidget *articalPanel = new QWidget();
  QWidget *typingPanel = new QWidget();

  // Init menu bar
  QMenuBar *mainMenuBar = this->menuBar();
  QMenu *settingMenu = new QMenu(QMenu::tr("Setting"));
  QMenu *languageMenu = new QMenu(QMenu::tr("Language"));
  QMenu *switchMenu = new QMenu(QMenu::tr("Switch To"));

  // Init menu action
  QAction *enUsAction = new QAction(QAction::tr("English(US)"));
  QAction *zhCnAction = new QAction(QAction::tr("Chinese(Simplified)"));
  QAction *zhTwAction = new QAction(QAction::tr("Chinese(Traditional)"));
  QAction *mainPanelAction = new QAction(QAction::tr("Main Panel"));
  QAction *articalTypeSelectPanelAction = new QAction(QAction::tr("Artical Type Select Panel"));
  QAction *typingPanelAction = new QAction(QAction::tr("Typing Panel"));

  // Init toolbar
  // QToolBar *articalPanelToolBar = this->addToolBar("articalPanelToolBar");

  // Init button
  QPushButton *articalTypeSelectPanelButton = new QPushButton(QPushButton::tr("Artical"));
  QPushButton *articalPanelHealthButton = new QPushButton(QPushButton::tr("Health"));
  QPushButton *articalPanelSportButton = new QPushButton(QPushButton::tr("Sport"));
  QPushButton *articalPanelTravelButton = new QPushButton(QPushButton::tr("Travel"));
  QPushButton *articalPanelWorldButton = new QPushButton(QPushButton::tr("World"));
  QPushButton *typingPanelButton = new QPushButton(QPushButton::tr("Typing"));

  // Init text edit
  QTextBrowser *articalPanelTextBrowser = new QTextBrowser();

  // Construtor
  MainWindow(QTranslator *translator);

  // Set language
  void setLanguage(const std::string &languageType);

  // Switch to main panel
  void switchToMainPanel();
  // Switch to typing panel
  void switchToTypingPanel();
  // Switch to artical type select Panel
  void switchToArticalTypeSelectPanel();
  // Switch to artical panel
  void switchToArticalPanel(const std::string &articalType);
};

#endif
