#include "MainWindow.h"
#include "Crawler.h"
#include "OnlineTranslator.h"
#include "LanguageTypes.h"
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
  articleTypeSelectPanelAction = new QAction(switchToMenu);
  typingPanelAction = new QAction(switchToMenu);
  translatePanelAction = new QAction(switchToMenu);

  // Central widget
  this->setCentralWidget(new QWidget(this));
  centralWidgetLayout = new QStackedLayout(this->centralWidget());
  this->centralWidget()->setBackgroundRole(QPalette::Shadow);//debug!!

  // Main panel
  mainPanel = new QWidget();
  articleTypeSelectPanelButton = new QPushButton(mainPanel);
  typingPanelButton = new QPushButton(mainPanel);
  testingPanelButton = new QPushButton(mainPanel);
  translatePanelButton = new QPushButton(mainPanel);

  // Artical type select panel
  articleTypeSelectPanel = new QWidget();
  articlePanelHealthButton = new QPushButton(articleTypeSelectPanel);
  articlePanelSportButton = new QPushButton(articleTypeSelectPanel);
  articlePanelTravelButton = new QPushButton(articleTypeSelectPanel);
  articlePanelWorldButton = new QPushButton(articleTypeSelectPanel);

  // Artical panel
  articlePanel = new QWidget();
  articlePanelTextBrowser = new QTextBrowser(articlePanel);

  // Typing panel
  typingPanel = new QWidget();
  // typingPanelStatusWidget = new QWidget(typingPanel);
  typingPanelTypingWidget = new QWidget(typingPanel);

  // Test panel
  testingPanel = new QWidget();

  // Translate panel
  translatePanel = new QWidget();
  translatePanelSrcGroupBox = new QGroupBox();
  translatePanelSrcGroupBoxLayout = new QVBoxLayout(translatePanelSrcGroupBox);
  translatePanelSrcTextEdit = new QTextEdit();
  translatePanelMidWidget = new QWidget();
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
  this->setWindowIcon(QIcon("assets/image/icon.ico"));

  // Setup top level widget
  this->centralWidgetLayout->addWidget(mainPanel);
  this->centralWidgetLayout->addWidget(articlePanel);
  this->centralWidgetLayout->addWidget(typingPanel);
  this->centralWidgetLayout->addWidget(testingPanel);
  this->centralWidgetLayout->addWidget(translatePanel);
  this->centralWidgetLayout->addWidget(articleTypeSelectPanel);

  // Setup menu bar
  mainMenuBar->addMenu(settingMenu);
  settingMenu->addMenu(languageMenu);
  mainMenuBar->addMenu(switchToMenu);
  languageMenu->addAction(enUsAction);
  languageMenu->addAction(zhCnAction);
  languageMenu->addAction(zhTwAction);
  switchToMenu->addAction(mainPanelAction);
  switchToMenu->addAction(articleTypeSelectPanelAction);
  switchToMenu->addAction(typingPanelAction);
  switchToMenu->addAction(translatePanelAction);

  // Setup main panel
  QGridLayout *mainPanelLayout = new QGridLayout(mainPanel);
  mainPanelLayout->addWidget(articleTypeSelectPanelButton, 0, 0);
  mainPanelLayout->addWidget(typingPanelButton, 0, 1);
  mainPanelLayout->addWidget(testingPanelButton, 1, 0);
  mainPanelLayout->addWidget(translatePanelButton, 1, 1);

  // Setup article type select panel
  QGridLayout *articleTypeSelectPanelLayout = new QGridLayout(articleTypeSelectPanel);
  articleTypeSelectPanelLayout->addWidget(articlePanelHealthButton, 0, 0);
  articleTypeSelectPanelLayout->addWidget(articlePanelSportButton, 0, 1);
  articleTypeSelectPanelLayout->addWidget(articlePanelTravelButton, 1, 0);
  articleTypeSelectPanelLayout->addWidget(articlePanelWorldButton, 1, 1);

  // Setup article panel
  QGridLayout *articlePanelLayout = new QGridLayout(articlePanel);
  articlePanelLayout->setColumnMinimumWidth(0, 200);
  articlePanelLayout->addWidget(articlePanelTextBrowser, 1, 0);





  // Setup test panel
  QWidget *testingPanelSubPanel = new QWidget(testingPanel);

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





  // Setup typing panel
  QGridLayout *typingPanelLayout = new QGridLayout(typingPanel);
  typingPanel->setLayout(typingPanelLayout);
  // typingPanelLayout->addWidget(typingPanelStatusWidget, 0, 0);
  typingPanelLayout->addWidget(typingPanelTypingWidget, 0, 1);

  // Setup typing panel status widget
  // QGridLayout *typingPanelStatusWidgetLayout = new QGridLayout();

  // Setup typing panel typing widget
  QVBoxLayout *typingPanelTypingWidgetLayout = new QVBoxLayout(typingPanelTypingWidget);
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world1")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit());

  // Setup translate panel
  QGridLayout *translatePanelLayout = new QGridLayout(translatePanel);

  translatePanelLayout->addWidget(translatePanelSrcGroupBox, 0, 0);
  translatePanelSrcGroupBoxLayout->addWidget(translatePanelSrcTextEdit);

  translatePanelLayout->addWidget(translatePanelMidWidget, 0, 1);
  QVBoxLayout *translatePanelMidWidgetLayout = new QVBoxLayout(translatePanelMidWidget);
  QPushButton *translatePanelToDestButton = new QPushButton(">>");
  QPushButton *translatePanelToSrcButton = new QPushButton("<<");
  translatePanelMidWidgetLayout->addWidget(translatePanelToDestButton);
  translatePanelMidWidgetLayout->addWidget(translatePanelToSrcButton);

  translatePanelLayout->addWidget(translatePanelDestGroupBox, 0, 2);
  translatePanelDestGroupBoxLayout->addWidget(translatePanelDestTextEdit);



  // Connect action callback
  // QObject::connect(zhTwAction, SIGNAL(triggered()), this, SLOT(MainWindow::setLanguageZhTw()));
  // QObject::connect(zhTwAction, &QAction::triggered, this, &MainWindow::setLanguageZhTw, 100);
  QObject::connect(enUsAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::en_US);});
  QObject::connect(zhCnAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_CN);});
  QObject::connect(zhTwAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_TW);});
  QObject::connect(mainPanelAction, &QAction::triggered, [this]{this->switchToMainPanel();});
  QObject::connect(articleTypeSelectPanelAction, &QAction::triggered, [this]{this->switchToArticleTypeSelectPanel();});
  QObject::connect(typingPanelAction, &QAction::triggered, [this]{this->switchToTypingPanel();});
  QObject::connect(translatePanelAction, &QAction::triggered, [this]{this->switchToTranslatePanel();});

  // Connect button callback
  QObject::connect(articleTypeSelectPanelButton, &QPushButton::clicked, [this]{this->switchToArticleTypeSelectPanel();});
  QObject::connect(articlePanelHealthButton, &QPushButton::clicked, [this]{this->switchToArticlePanel("health");});
  QObject::connect(articlePanelSportButton, &QPushButton::clicked, [this]{this->switchToArticlePanel("sport");});
  QObject::connect(articlePanelTravelButton, &QPushButton::clicked, [this]{this->switchToArticlePanel("travel");});
  QObject::connect(articlePanelWorldButton, &QPushButton::clicked, [this]{this->switchToArticlePanel("world");});
  QObject::connect(typingPanelButton, &QPushButton::clicked, [this]{this->switchToTypingPanel();});
  QObject::connect(testingPanelButton, &QPushButton::clicked, [this]{this->switchTotestingPanel();});
  QObject::connect(translatePanelButton, &QPushButton::clicked, [this]{this->switchToTranslatePanel();});
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
  articleTypeSelectPanelAction->setText(QAction::tr("Article Type Select Panel"));
  typingPanelAction->setText(QAction::tr("Typing Panel"));
  translatePanelAction->setText(QAction::tr("Translate Panel"));

  // Main panel
  articleTypeSelectPanelButton->setText(QPushButton::tr("Article"));
  typingPanelButton->setText(QPushButton::tr("Typing"));
  testingPanelButton->setText(QPushButton::tr("Test"));
  translatePanelButton->setText(QPushButton::tr("Translate"));

  // Article panel
  articlePanelHealthButton->setText(QPushButton::tr("Health"));
  articlePanelSportButton->setText(QPushButton::tr("Sport"));
  articlePanelTravelButton->setText(QPushButton::tr("Travel"));
  articlePanelWorldButton->setText(QPushButton::tr("World"));

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

void MainWindow::switchToMainPanel()
{
  std::cout << "MainWindow::switchToMainPanel()\n";
  centralWidgetLayout->setCurrentWidget(mainPanel);
}

void MainWindow::switchToArticleTypeSelectPanel()
{
  std::cout << "MainWindow::switchToarticleTypeSelectPanel()\n";
  centralWidgetLayout->setCurrentWidget(articleTypeSelectPanel);
}

void MainWindow::switchToArticlePanel(const std::string &articleType)
{
  std::cout << "MainWindow::switchToarticlePanel(\"" << articleType << "\")\n";
  centralWidgetLayout->setCurrentWidget(articlePanel);

  // Clear text browser
  articlePanelTextBrowser->setText("");

  // Put article to text browser
  if(articleType == "health")
  {
    articlePanelTextBrowser->setText(QString::fromStdString(Crawler::getArticle()));
  }
  else if(articleType == "sport")
  {
    articlePanelTextBrowser->setText(QString::fromStdString(OnlineTranslator::translate(Crawler::getArticle(), LanguageTypes::zh_TW)));
  }
  else if(articleType == "travel")
  {
    articlePanelTextBrowser->setText(QString::fromStdString(OnlineTranslator::translate("hello\nhello", LanguageTypes::zh_TW)));
  }
  else if(articleType == "world")
  {

  }
  else
  {
    articlePanelTextBrowser->setText("Unsupported article type");
  }
}

void MainWindow::switchToTypingPanel()
{
  std::cout << "MainWindow::switchToTypingPanel()\n";
  centralWidgetLayout->setCurrentWidget(typingPanel);
}

void MainWindow::switchTotestingPanel()
{
  std::cout << "MainWindow::switchToTypingPanel()\n";
  centralWidgetLayout->setCurrentWidget(testingPanel);
}

void MainWindow::switchToTranslatePanel()
{
  std::cout << "MainWindow::switchToTranslatePanel()\n";
  centralWidgetLayout->setCurrentWidget(translatePanel);
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
