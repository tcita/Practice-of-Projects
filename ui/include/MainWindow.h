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
  QMenu *helpMenu;
  QAction *aboutAction;

  // About dialog
  QWidget *aboutDialog;
  QVBoxLayout *aboutDialogLayout;
  QLabel *aboutDialogInfoLabel;
  QPushButton *aboutDialogOkButton;

  // Central widget
  QStackedLayout *centralWidgetLayout;

  // Main panel
  QWidget *mainPanel;
  QGridLayout *mainPanelLayout;
  QPushButton *articleTypeSelectPanelButton;
  QPushButton *typingPanelButton;
  QPushButton *testingPanelButton;
  QPushButton *translatePanelButton;

  // Artical type select panel
  QWidget *articleTypeSelectPanel;
  QGridLayout *articleTypeSelectPanelLayout;
  QPushButton *articlePanelHealthButton;
  QPushButton *articlePanelSportButton;
  QPushButton *articlePanelTravelButton;
  QPushButton *articlePanelWorldButton;

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
  QWidget *testingPanel;
  QWidget *testingPanelSubPanel;

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

  // Translate panel translate to destination text edit
  void translatePanelTranslateToDest();
  // Translate panel translate to source text edit
  void translatePanelTranslateToSrc();
  // Pop up the about window
  void popUpAboutWindow();
};

#endif
