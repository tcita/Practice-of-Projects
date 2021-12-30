#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Crawler.h"
#include <vector>
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
#include <QGroupBox>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>

// The application main window
class MainWindow : public QMainWindow
{
private:
  // Translater
  QTranslator *translator;

  // Crawler
  Crawler *crawler;

  // Menu
  QMenuBar *mainMenuBar;
  QMenu *settingMenu;
  QMenu *languageMenu;
  QAction *enUsAction;
  QAction *zhCnAction;
  QAction *zhTwAction;
  QMenu *switchToMenu;
  QAction *mainPanelAction;
  QAction *articleTypePanelAction;
  QAction *typingPanelAction;
  QAction *translatePanelAction;
  QMenu *helpMenu;
  QAction *aboutAction;

  // About dialog
  QWidget *aboutDialog;
  QVBoxLayout *aboutDialogLayout;
  QLabel *aboutDialogInfoLabel1;
  QLabel *aboutDialogInfoLabel2;
  QLabel *aboutDialogInfoLabel3;
  QPushButton *aboutDialogOkButton;

  // Main panel
  QWidget *mainPanel;
  QGridLayout *mainPanelLayout;
  QPushButton *articleTypePanelButton;
  QPushButton *typingPanelButton;
  QPushButton *testingPanelButton;
  QPushButton *translatePanelButton;

  // Artical type panel
  QWidget *articleTypePanel;
  QGridLayout *articleTypePanelLayout;
  QPushButton *worldSubTypePanelButton;

  // World sub type Panel
  QWidget *worldSubTypePanel;
  QGridLayout *worldSubTypePanelLayout;
  QPushButton *africaArticleTitlePanelButton;
  QPushButton *businessArticlePanelButton;

  // Article title article panel
  QWidget *articleTitlePanel;
  QVBoxLayout *articleTitlePanelLayout;

  // Artical panel
  QWidget *articlePanel;
  QGridLayout *articlePanelLayout;
  QTextBrowser *articlePanelTextBrowser;

  // Typing panel
  QWidget *typingPanel;
  QGridLayout *typingPanelLayout;
  // QWidget *typingPanelStatusWidget;
  QWidget *typingPanelTypingWidget;
  QVBoxLayout *typingPanelTypingWidgetLayout;

  // Test panel
  QScrollArea *testingPanel;
  QWidget *testingInnerPanel;
  QVBoxLayout *testingInnerPanelLayout;

  // Translate panel
  QWidget *translatePanel;
  QGridLayout *translatePanelLayout;
  QGroupBox *translatePanelSrcGroupBox;
  QVBoxLayout *translatePanelSrcGroupBoxLayout;
  QTextEdit *translatePanelSrcTextEdit;
  QWidget *translatePanelMidWidget;
  QVBoxLayout *translatePanelMidWidgetLayout;
  QPushButton *translatePanelToDestButton;
  QPushButton *translatePanelToSrcButton;
  QGroupBox *translatePanelDestGroupBox;
  QVBoxLayout *translatePanelDestGroupBoxLayout;
  QTextEdit *translatePanelDestTextEdit;

  /****************************************************************************************************
  * Functions
  ****************************************************************************************************/
public:
  MainWindow(QTranslator *translator, Crawler *crawler);

private:
  // Translate all widgets
  void retranslate();
  // Set language
  void setLanguage(const std::string &languageType);
  // Set article title to article title panel
  void setArticleTitles(const std::vector<std::string> &articleTitles);
  // Set article to article text browser
  void setArticle(const std::string &article);
  // Translate panel translate to destination text edit
  void translatePanelTranslateToDest();
  // Translate panel translate to source text edit
  void translatePanelTranslateToSrc();
  // Pop up the about window
  void popUpAboutWindow();
  // Switch central widget
  void switchCentralWidget(QWidget *panel);

  //
  QGroupBox* createSingleChoiceQuestion(const std::string &question, const std::vector<std::string> &candidateAnswers);
  //
  QGroupBox* createMultipleChoiceQuestion(const std::string &question, const std::vector<std::string> &candidateAnswers);
};

#endif
