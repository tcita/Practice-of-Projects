#include "MainWindow.h"
#include "Crawler.h"
#include "OnlineTranslator.h"
#include "LanguageTypes.h"
#include "ProjectInfo.h"
#include <iostream> //debug
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QTranslator>

MainWindow::MainWindow(QTranslator *translator)
  :translator(translator)
{
  /******************************************************************************************
  * Init member
  ******************************************************************************************/
  // Menu
  mainMenuBar = this->menuBar();
  settingMenu = new QMenu(mainMenuBar);
  languageMenu = new QMenu(settingMenu);
  enUsAction = new QAction(languageMenu);
  zhCnAction = new QAction(languageMenu);
  zhTwAction = new QAction(languageMenu);
  switchToMenu = new QMenu(mainMenuBar);
  mainPanelAction = new QAction(switchToMenu);
  articleTypePanelAction = new QAction(switchToMenu);
  typingPanelAction = new QAction(switchToMenu);
  translatePanelAction = new QAction(switchToMenu);
  helpMenu = new QMenu(mainMenuBar);
  aboutAction = new QAction(helpMenu);

  // About dialog
  aboutDialog = new QDialog(this);
  aboutDialogLayout = new QVBoxLayout(aboutDialog);
  aboutDialogInfoLabel1 = new QLabel(aboutDialog);
  aboutDialogInfoLabel2 = new QLabel(aboutDialog);
  aboutDialogInfoLabel3 = new QLabel(aboutDialog);
  aboutDialogOkButton = new QPushButton(aboutDialog);

  // Central widget
  this->setCentralWidget(new QWidget(this));
  centralWidgetLayout = new QStackedLayout(this->centralWidget());

  // Main panel
  mainPanel = new QWidget(this);
  mainPanelLayout = new QGridLayout();
  articleTypePanelButton = new QPushButton(mainPanel);
  typingPanelButton = new QPushButton(mainPanel);
  testingPanelButton = new QPushButton(mainPanel);
  translatePanelButton = new QPushButton(mainPanel);

  // Article type panel
  articleTypePanel = new QWidget();
  articleTypePanelLayout = new QGridLayout(articleTypePanel);
  articleTypePanelWorldButton = new QPushButton(articleTypePanel);

  // World sub type Panel
  worldSubTypePanel = new QWidget();
  worldSubTypePanelLayout = new QGridLayout(worldSubTypePanel);
  worldSubTypePanelAfricaButton = new QPushButton(worldSubTypePanel);

  // Africa article panel
  africaArticlePanel = new QWidget();
  africaArticlePanelLayout = new QGridLayout(africaArticlePanel);

  // Article panel
  articlePanel = new QWidget();
  articlePanelLayout = new QGridLayout(articlePanel);
  articlePanelTextBrowser = new QTextBrowser(articlePanel);

  // Typing panel
  typingPanel = new QWidget();
  typingPanelLayout = new QGridLayout(typingPanel);
  // typingPanelStatusWidget = new QWidget(typingPanel);
  typingPanelTypingWidget = new QWidget(typingPanel);
  typingPanelTypingWidgetLayout = new QVBoxLayout(typingPanelTypingWidget);

  // Test panel
  testingPanel = new QWidget();
  testingPanelSubPanel = new QWidget(testingPanel);

  // Translate panel
  translatePanel = new QWidget();
  translatePanelLayout = new QGridLayout(translatePanel);
  translatePanelSrcGroupBox = new QGroupBox();
  translatePanelSrcGroupBoxLayout = new QVBoxLayout(translatePanelSrcGroupBox);
  translatePanelSrcTextEdit = new QTextEdit();
  translatePanelMidWidget = new QWidget();
  translatePanelMidWidgetLayout = new QVBoxLayout(translatePanelMidWidget);
  translatePanelToDestButton = new QPushButton(">>");
  translatePanelToSrcButton = new QPushButton("<<");
  translatePanelDestGroupBox = new QGroupBox();
  translatePanelDestGroupBoxLayout = new QVBoxLayout(translatePanelDestGroupBox);
  translatePanelDestTextEdit = new QTextEdit();

  /******************************************************************************************
  * Set member information
  ******************************************************************************************/
  // Translate
  this->retranslate();

  // Setup language
  // translator->load(LanguageTypes::zh_TW);
  this->setLanguage(LanguageTypes::zh_TW);

  // Setup icon
  this->setWindowIcon(QIcon("assets/image/icon.png"));

  // Setup top level widget
  this->centralWidgetLayout->addWidget(mainPanel);
  this->centralWidgetLayout->addWidget(articlePanel);
  this->centralWidgetLayout->addWidget(typingPanel);
  this->centralWidgetLayout->addWidget(testingPanel);
  this->centralWidgetLayout->addWidget(translatePanel);
  this->centralWidgetLayout->addWidget(articleTypePanel);
  this->centralWidgetLayout->addWidget(worldSubTypePanel);
  this->centralWidgetLayout->addWidget(africaArticlePanel);
  this->centralWidgetLayout->addWidget(articlePanel);

  // Setup menu bar
  mainMenuBar->addMenu(settingMenu);
  settingMenu->addMenu(languageMenu);
  languageMenu->addAction(enUsAction);
  languageMenu->addAction(zhCnAction);
  languageMenu->addAction(zhTwAction);
  mainMenuBar->addMenu(switchToMenu);
  switchToMenu->addAction(mainPanelAction);
  switchToMenu->addAction(articleTypePanelAction);
  switchToMenu->addAction(typingPanelAction);
  switchToMenu->addAction(translatePanelAction);
  mainMenuBar->addMenu(helpMenu);
  helpMenu->addAction(aboutAction);

  // Setup about dialogl
  aboutDialog->resize(300, 150);
  aboutDialog->setLayout(aboutDialogLayout);
  aboutDialogLayout->addWidget(aboutDialogInfoLabel1);
  aboutDialogLayout->addWidget(aboutDialogInfoLabel2);
  aboutDialogLayout->addWidget(aboutDialogInfoLabel3);
  aboutDialogLayout->addWidget(aboutDialogOkButton);

  // Setup main panel
  mainPanel->setLayout(mainPanelLayout);
  mainPanelLayout->addWidget(articleTypePanelButton, 0, 0);
  mainPanelLayout->addWidget(typingPanelButton, 0, 1);
  mainPanelLayout->addWidget(testingPanelButton, 1, 0);
  mainPanelLayout->addWidget(translatePanelButton, 1, 1);

  // Setup article type panel
  articleTypePanel->setLayout(articleTypePanelLayout);
  articleTypePanelLayout->addWidget(articleTypePanelWorldButton, 1, 1);

  // Setup world sub type panel
  worldSubTypePanel->setLayout(worldSubTypePanelLayout);
  worldSubTypePanelLayout->addWidget(worldSubTypePanelAfricaButton);

  // Setup africa article panel
  africaArticlePanel->setLayout(africaArticlePanelLayout);

  // Setup article panel
  articlePanel->setLayout(articlePanelLayout);
  articlePanelLayout->setColumnMinimumWidth(0, 200);
  articlePanelLayout->addWidget(articlePanelTextBrowser, 1, 0);

  // Setup test panel

  // QVBoxLayout *testingPanelLayout = new QVBoxLayout(testingPanel);

  // QWidget *testingPanelSubPanel = new QWidget();
  // testingPanelLayout->addWidget(testingPanelSubPanel);

  QVBoxLayout *testingPanelSubPanelLayout = new QVBoxLayout(testingPanelSubPanel);
  testingPanelSubPanelLayout->setAlignment(Qt::AlignTop);
  testingPanelSubPanelLayout->addWidget(new QTextBrowser()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!
  testingPanelSubPanelLayout->addWidget(new QLineEdit()); //debug!!

  QScrollArea *testingPanelScrollArea = new QScrollArea(testingPanel);
  testingPanelScrollArea->setWidget(testingPanelSubPanel);






  // Setup typing
  typingPanel->setLayout(typingPanelLayout);
  // typingPanelLayout->addWidget(typingPanelStatusWidget, 0, 0);
  typingPanelLayout->addWidget(typingPanelTypingWidget, 0, 1);

  // Setup typing panel status widget
  // QGridLayout *typingPanelStatusWidgetLayout = new QGridLayout();

  // Setup typing panel typing widget
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world1")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());



  // Setup translate panel
  translatePanelLayout->addWidget(translatePanelSrcGroupBox, 0, 0);
  translatePanelSrcGroupBoxLayout->addWidget(translatePanelSrcTextEdit);
  translatePanelLayout->addWidget(translatePanelMidWidget, 0, 1);
  translatePanelMidWidgetLayout->addWidget(translatePanelToDestButton);
  translatePanelMidWidgetLayout->addWidget(translatePanelToSrcButton);
  translatePanelLayout->addWidget(translatePanelDestGroupBox, 0, 2);
  translatePanelDestGroupBoxLayout->addWidget(translatePanelDestTextEdit);



  // Connect action callback
  QObject::connect(enUsAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::en_US);});
  QObject::connect(zhCnAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_CN);});
  QObject::connect(zhTwAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_TW);});
  QObject::connect(mainPanelAction, &QAction::triggered, [this]{centralWidgetLayout->setCurrentWidget(mainPanel);});
  QObject::connect(articleTypePanelAction, &QAction::triggered, [this]{centralWidgetLayout->setCurrentWidget(articleTypePanel);});
  QObject::connect(typingPanelAction, &QAction::triggered, [this]{centralWidgetLayout->setCurrentWidget(typingPanel);});
  QObject::connect(translatePanelAction, &QAction::triggered, [this]{centralWidgetLayout->setCurrentWidget(translatePanel);});
  QObject::connect(aboutAction, &QAction::triggered, [this]{this->popUpAboutWindow();});

  // Connect button callback
  QObject::connect(aboutDialogOkButton, &QPushButton::clicked, [this]{this->aboutDialog->hide();});
  QObject::connect(articleTypePanelButton, &QPushButton::clicked, [this]{centralWidgetLayout->setCurrentWidget(articleTypePanel);});
  QObject::connect(articleTypePanelWorldButton, &QPushButton::clicked, [this]{centralWidgetLayout->setCurrentWidget(worldSubTypePanel);});
  QObject::connect(worldSubTypePanelAfricaButton, &QPushButton::clicked, [this]{centralWidgetLayout->setCurrentWidget(africaArticlePanel);});
  QObject::connect(typingPanelButton, &QPushButton::clicked, [this]{centralWidgetLayout->setCurrentWidget(typingPanel);});
  QObject::connect(testingPanelButton, &QPushButton::clicked, [this]{centralWidgetLayout->setCurrentWidget(testingPanel);});
  QObject::connect(translatePanelButton, &QPushButton::clicked, [this]{centralWidgetLayout->setCurrentWidget(translatePanel);});
  QObject::connect(translatePanelToDestButton, &QPushButton::clicked, [this]{this->translatePanelTranslateToDest();});
  QObject::connect(translatePanelToSrcButton, &QPushButton::clicked, [this]{this->translatePanelTranslateToSrc();});
}

void MainWindow::retranslate()
{
  // Main window
  this->setWindowTitle(QMainWindow::tr("English Assistant"));

  // Menu
  settingMenu->setTitle(QMenu::tr("Setting"));
  languageMenu->setTitle(QMenu::tr("Language"));
  enUsAction->setText(QAction::tr("English(US)"));
  zhCnAction->setText(QAction::tr("Chinese(Simplified)"));
  zhTwAction->setText(QAction::tr("Chinese(Traditional)"));
  switchToMenu->setTitle(QMenu::tr("Switch To"));
  mainPanelAction->setText(QAction::tr("Main Panel"));
  articleTypePanelAction->setText(QAction::tr("Article Type Select Panel"));
  typingPanelAction->setText(QAction::tr("Typing Panel"));
  translatePanelAction->setText(QAction::tr("Translate Panel"));
  helpMenu->setTitle(QMenu::tr("Help"));
  aboutAction->setText(QMenu::tr("About"));

  // About dialog
  aboutDialog->setWindowTitle(QDialog::tr("English Assistant"));
  aboutDialogInfoLabel1->setText(QDialog::tr("English Assistant") + " " + ProjectInfo::VERSION);
  aboutDialogInfoLabel2->setText(QDialog::tr("English translate & learning program"));
  aboutDialogInfoLabel3->setText(QDialog::tr("published under GPLv3"));
  aboutDialogOkButton->setText(QPushButton::tr("OK"));

  // Main panel
  articleTypePanelButton->setText(QPushButton::tr("article"));
  typingPanelButton->setText(QPushButton::tr("typing"));
  testingPanelButton->setText(QPushButton::tr("test"));
  translatePanelButton->setText(QPushButton::tr("translate"));

  // Article type panel
  articleTypePanelWorldButton->setText(QPushButton::tr("world"));

  // World sub type panel
  worldSubTypePanelAfricaButton->setText(QPushButton::tr("africa"));

  // Translate panel
  translatePanelSrcGroupBox->setTitle(QTextEdit::tr("Source language"));
  translatePanelDestGroupBox->setTitle(QTextEdit::tr("Dest language"));
}

void MainWindow::setLanguage(const std::string &languageType)
{
  std::cout << "Current language is: " << translator->language().toStdString() << "\n"; //debug

  // Check if it is different with current language
  if(translator->language().toStdString() == languageType)
  {
    std::cout << languageType << " is the current language, nothing changed\n";
    return;
  }

  std::cout << "MainWindow::setLanguage(\"" << languageType << "\")\n";
  std::string languageFilePath = std::string("assets/lang/") + languageType;
  translator->load(QString::fromStdString(languageFilePath));
  std::cout << "The language after change is: " << translator->language().toStdString() << "\n"; //debug

  this->retranslate();
}

void MainWindow::africaArticlePanelFetchArticleTitle()
{
  std::cout << "MainWindow::africaArticlePanelFetchArticleTitle()\n";
  // africaArticlePanelLayout->addWidget();

}

void MainWindow::articlePanelFetchArticle(const std::string &articleType)
{
  // Clear text browser
  articlePanelTextBrowser->setText("");

  // Put article to text browser
  if(articleType == "world")
  {
    articlePanelTextBrowser->setText(QString::fromStdString(Crawler::getArticle()));
  }
  else
  {
    articlePanelTextBrowser->setText("Unsupported article type");
  }
}

void MainWindow::translatePanelTranslateToDest()
{
  std::cout << "MainWindow::translatePanelTranslateToDest()\n";
  const std::string &input = translatePanelSrcTextEdit->toPlainText().toStdString();
  const std::string &destLanguageType = translator->language().toStdString();
  const std::string &srcLanguageType = LanguageTypes::en_US;
  const std::string &reply = OnlineTranslator::translate(input, destLanguageType, srcLanguageType);
  translatePanelDestTextEdit->setText(QString::fromStdString(reply));
}

void MainWindow::translatePanelTranslateToSrc()
{
  std::cout << "MainWindow::translatePanelTranslateToSrc()\n";
  const std::string &input = translatePanelDestTextEdit->toPlainText().toStdString();
  const std::string &srcLanguageType = translator->language().toStdString();
  const std::string &destLanguageType = LanguageTypes::en_US;
  const std::string &reply = OnlineTranslator::translate(input, destLanguageType, srcLanguageType);
  translatePanelSrcTextEdit->setText(QString::fromStdString(reply));
}

void MainWindow::popUpAboutWindow()
{
  std::cout << "MainWindow::popUpAboutWindow()\n";
  aboutDialog->show();
}
