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
#include <QStackedLayout>

// The application main window
class MainWindow : public QMainWindow
{
private:
  // Translater
  QTranslator *translator;

  // Menu
  QMenuBar *mainMenuBar;
  QMenu *settingMenu;
  QMenu *languageMenu;
  QAction *enUsAction;
  QAction *zhCnAction;
  QAction *zhTwAction;
  QMenu *switchToMenu;
  QAction *mainPanelAction;
  QAction *articleTypeSelectPanelAction;
  QAction *typingPanelAction;
  QAction *translatePanelAction;

  // Central widget
  QStackedLayout *centralWidgetLayout;

  // Main panel
  QWidget *mainPanel;
  QPushButton *articleTypeSelectPanelButton;
  QPushButton *typingPanelButton;
  QPushButton *testingPanelButton;
  QPushButton *translatePanelButton;

  // Artical type select panel
  QWidget *articleTypeSelectPanel;
  QPushButton *articlePanelHealthButton;
  QPushButton *articlePanelSportButton;
  QPushButton *articlePanelTravelButton;
  QPushButton *articlePanelWorldButton;

  // Artical panel
  QWidget *articlePanel;
  QTextBrowser *articlePanelTextBrowser;

  // Typing panel
  QWidget *typingPanel;
  // QWidget *typingPanelStatusWidget;
  QWidget *typingPanelTypingWidget;

  // Test panel
  QWidget *testingPanel;

  // Translate panel
  QWidget *translatePanel;

  /****************************************************************************************************
  * Functions
  ****************************************************************************************************/
public:
  // MainWindow(QTranslator *translator);
  MainWindow(QTranslator *translator);

private:
  // Translate all widgets
  void retranslate();
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
  // Switch to test panel
  void switchTotestingPanel();
  // Switch to translate panel
  void switchToTranslatePanel();
};

#endif
