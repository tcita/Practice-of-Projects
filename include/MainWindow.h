#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Crawler.h"
#include <vector>
#include <stack>
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
#include <QMessageBox>
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
  QAction *previousPanelAction;
  std::stack<QWidget*> panelHistory;
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

  // About window
  QWidget *aboutWindow;
  QVBoxLayout *aboutWindowLayout;
  QLabel *aboutWindowInfoLabel1;
  QLabel *aboutWindowInfoLabel2;
  QLabel *aboutWindowInfoLabel3;
  QPushButton *aboutWindowOkButton;

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
  QWidget *articlePanelLeftPanel;
  QGridLayout *articlePanelLeftPanelLayout;
  QTextBrowser *articlePanelTextBrowser;
  QTextBrowser *articlePanelTranslateTextBrowser;
  int articlePanelTextBrowserSelectRequestID;
  QWidget *articlePanelRightPanel;
  QGridLayout *articlePanelRightPanelLayout;
  QTextBrowser *articlePanelStatisticsTextBrowser;

  // Typing panel
  QWidget *typingPanel;
  QGridLayout *typingPanelLayout;
  // QWidget *typingPanelStatusWidget;
  QWidget *typingPanelTypingWidget;
  QVBoxLayout *typingPanelTypingWidgetLayout;

  // Testing panel
  QScrollArea *testingPanel;
  QWidget *testingInnerPanel;
  QVBoxLayout *testingInnerPanelLayout;
  QPushButton *testingInnerPanelSubmitButton;

  // Testing result panel
  QScrollArea *testingResultPanel;
  QWidget *testingResultInnerPanel;
  QVBoxLayout *testingResultInnerPanelLayout;
  QLabel *testingResultTitleLabel;

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
  // Switch central widget to given widget
  void switchToPanel(QWidget *panel);
  // Switch panel back accroding to the panel history
  void switchToPreviousPanel();

private:
  //
  QGroupBox* createSingleChoiceQuestion(const std::string &question, const std::vector<std::string> &candidateAnswers);
  //
  QGroupBox* createMultipleChoiceQuestion(const std::string &question, const std::vector<std::string> &candidateAnswers);
};

#endif
