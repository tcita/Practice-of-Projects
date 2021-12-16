#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QWidget>
#include <QScrollArea>
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
  QTranslator *translator = new QTranslator();

  // Init panel & widgets
  QWidget *mainPanel = new QWidget();
  QWidget *articleTypeSelectPanel = new QWidget();
  QWidget *articlePanel = new QWidget();
  QWidget *typingPanel = new QWidget();
  QWidget *typingPanelStatusWidget = new QWidget();
  QWidget *typingPanelTypingWidget = new QWidget();
  // QScrollArea *typingPanelTypingWidget = new QScrollArea();
  QWidget *testPanel = new QWidget();

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
  QAction *articleTypeSelectPanelAction = new QAction(QAction::tr("article Type Select Panel"));
  QAction *typingPanelAction = new QAction(QAction::tr("Typing Panel"));

  // Init button
  QPushButton *articleTypeSelectPanelButton = new QPushButton(QPushButton::tr("article"));
  QPushButton *articlePanelHealthButton = new QPushButton(QPushButton::tr("Health"));
  QPushButton *articlePanelSportButton = new QPushButton(QPushButton::tr("Sport"));
  QPushButton *articlePanelTravelButton = new QPushButton(QPushButton::tr("Travel"));
  QPushButton *articlePanelWorldButton = new QPushButton(QPushButton::tr("World"));
  QPushButton *typingPanelButton = new QPushButton(QPushButton::tr("Typing"));
  QPushButton *testPanelButton = new QPushButton(QPushButton::tr("Test"));

  // Init text edit
  QTextBrowser *articlePanelTextBrowser = new QTextBrowser();

  // Construtor
  MainWindow(QTranslator *translator);

  // Set language
  void setLanguage(const std::string &languageType);

  // Switch to main panel
  void switchToMainPanel();
  // Switch to typing panel
  void switchToTypingPanel();
  // Switch to article type select Panel
  void switchToArticleTypeSelectPanel();
  // Switch to article panel
  void switchToArticlePanel(const std::string &articleType);
  // Switch to test Panel
  void switchToTestPanel();
};

#endif
