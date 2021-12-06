#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>
#include <QTextEdit>

// The application main window
class MainWindow : public QMainWindow
{
public:
  QTranslator *translator = new QTranslator();

  // Init widgets
  QWidget *mainPanel = new QWidget();
  QWidget *articalPanel = new QWidget();
  QWidget *healthPanel = new QWidget();
  QWidget *sportPanel = new QWidget();
  QWidget *travelPanel = new QWidget();
  QWidget *worldPanel = new QWidget();
  QWidget *typingPanel = new QWidget();

  // Init menu
  QMenu *settingMenu = this->menuBar()->addMenu(QMenu::tr("Setting"));
  QMenu *languageMenu = settingMenu->addMenu(QMenu::tr("Language"));
  QMenu *switchToMenu = this->menuBar()->addMenu(QMenu::tr("Switch To"));

  // Init menu action
  QAction *zhTwAction = languageMenu->addAction(QAction::tr("Chinese (Traditional)"));
  QAction *zhCnAction = languageMenu->addAction(QAction::tr("Chinese (Simplified)"));
  QAction *mainPanelAction = switchToMenu->addAction(QAction::tr("Main Panel"));
  QAction *articalPanelAction = switchToMenu->addAction(QAction::tr("Artical Panel"));
  QAction *typingPanelAction = switchToMenu->addAction(QAction::tr("Typing Panel"));

  // Init toolbar
  // QToolBar *articalPanelToolBar = new QToolBar("articalPanelToolBar");

  // Init button
  QPushButton *articalPanelButton = new QPushButton(QPushButton::tr("Artical"));
  QPushButton *healthPanelButton = new QPushButton(QPushButton::tr("Health"));
  QPushButton *sportPanelButton = new QPushButton(QPushButton::tr("Sport"));
  QPushButton *travelPanelButton = new QPushButton(QPushButton::tr("Travel"));
  QPushButton *worldPanelButton = new QPushButton(QPushButton::tr("World"));
  QPushButton *typingPanelButton = new QPushButton(QPushButton::tr("Typing"));

  // Init text edit
  QTextEdit *healthPanelTextEdit = new QTextEdit();
  QTextEdit *sportPanelTextEdit = new QTextEdit();
  QTextEdit *travelPanelTextEdit = new QTextEdit();
  QTextEdit *worldPanelTextEdit = new QTextEdit();

  // Construtor
  MainWindow(QTranslator *translator);

  // Set language to zh_tw
  // void setLanguageZhTw();
  void setLanguageZhTw(int n); //debug!!
  // Set language to zh_cn
  void setLanguageZhCn();

  // Change to main panel
  void changeMainPanel();
  // Change to typing panel
  void changeTypingPanel();
  // Change to artical panel
  void changeArticalPanel();
  // Change to health panel
  void changeHealthPanel();
  // Change to sport panel
  void changeSportPanel();
  // Change to travel panel
  void changeTravelPanel();
  // Change to world panel
  void changeWorldPanel();
};

#endif
