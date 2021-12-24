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

  // Main panel
  mainPanel = new QWidget();
  articleTypeSelectPanelButton = new QPushButton(mainPanel);
  typingPanelButton = new QPushButton(mainPanel);
  testPanelButton = new QPushButton(mainPanel);
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
  typingPanelStatusWidget = new QWidget(typingPanel);
  typingPanelTypingWidget = new QWidget(typingPanel);

  // Test panel
  testPanel = new QWidget();

  // Translate panel
  translatePanel = new QWidget();

  /******************************************************************************************
  * Set member information
  ******************************************************************************************/
  // Translate all widgets
  this->retranslate();

  // Setup icon
  this->setWindowIcon(QIcon("assets/image/icon.ico"));

  // Setup language
  translator->load(LanguageTypes::zh_TW);

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

  // Set central widget
  this->setCentralWidget(mainPanel);

  // Setup main panel
  QGridLayout *mainPanelLayout = new QGridLayout();
  mainPanel->setLayout(mainPanelLayout);
  mainPanelLayout->addWidget(articleTypeSelectPanelButton, 0, 0);
  mainPanelLayout->addWidget(typingPanelButton, 0, 1);
  mainPanelLayout->addWidget(testPanelButton, 1, 0);
  mainPanelLayout->addWidget(translatePanelButton, 1, 1);

  // Setup article type select panel
  QGridLayout *articleTypeSelectPanelLayout = new QGridLayout();
  articleTypeSelectPanel->setLayout(articleTypeSelectPanelLayout);
  articleTypeSelectPanelLayout-> addWidget(articlePanelHealthButton, 0, 0);
  articleTypeSelectPanelLayout-> addWidget(articlePanelSportButton, 0, 1);
  articleTypeSelectPanelLayout-> addWidget(articlePanelTravelButton, 1, 0);
  articleTypeSelectPanelLayout-> addWidget(articlePanelWorldButton, 1, 1);


  // Setup article panel
  QGridLayout *articlePanelLayout = new QGridLayout();
  articlePanel->setLayout(articlePanelLayout);
  articlePanelLayout->setColumnMinimumWidth(0, 200);
  articlePanelLayout->addWidget(articlePanelTextBrowser, 1, 0);

  // Setup typing panel
  QGridLayout *typingPanelLayout = new QGridLayout();
  typingPanel->setLayout(typingPanelLayout);
  typingPanelLayout->addWidget(typingPanelStatusWidget, 0, 0);
  typingPanelLayout->addWidget(typingPanelTypingWidget, 0, 1);

  // Setup typing panel typing widget
  QVBoxLayout *typingPanelTypingWidgetLayout = new QVBoxLayout();
  typingPanelTypingWidget->setLayout(typingPanelTypingWidgetLayout);
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world1")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit()); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world2")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit()); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world3")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit()); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLabel("hello, world4")); //debug!!
  typingPanelTypingWidgetLayout->addWidget(new QLineEdit()); //debug!!

  // Connect action callback
  // QObject::connect(zhTwAction, SIGNAL(triggered()), this, SLOT(MainWindow::setLanguageZhTw()));
  // QObject::connect(zhTwAction, &QAction::triggered, this, &MainWindow::setLanguageZhTw, 100);
  QObject::connect(enUsAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::en_US);});
  QObject::connect(zhCnAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_CN);});
  QObject::connect(zhTwAction, &QAction::triggered, [this]{this->setLanguage(LanguageTypes::zh_TW);});
  QObject::connect(mainPanelAction, &QAction::triggered, [this]{this->switchToMainPanel();});
  QObject::connect(articleTypeSelectPanelAction, &QAction::triggered, [this]{this->switchToArticleTypeSelectPanel();});
  QObject::connect(typingPanelAction, &QAction::triggered, [this]{this->switchToTypingPanel();});

  // Connect button callback
  QObject::connect(articleTypeSelectPanelButton, &QPushButton::clicked, [this]{this->switchToArticleTypeSelectPanel();});
  QObject::connect(articlePanelHealthButton, &QPushButton::clicked, [this]{this->switchToArticlePanel("health");});
  QObject::connect(articlePanelSportButton, &QPushButton::clicked, [this]{this->switchToArticlePanel("sport");});
  QObject::connect(articlePanelTravelButton, &QPushButton::clicked, [this]{this->switchToArticlePanel("travel");});
  QObject::connect(articlePanelWorldButton, &QPushButton::clicked, [this]{this->switchToArticlePanel("world");});
  QObject::connect(typingPanelButton, &QPushButton::clicked, [this]{this->switchToTypingPanel();});
  QObject::connect(testPanelButton, &QPushButton::clicked, [this]{this->switchToTestPanel();});
  QObject::connect(translatePanelButton, &QPushButton::clicked, [this]{this->switchToTranslatePanel();});
}

void MainWindow::retranslate()
{
  // Menu
  settingMenu -> setTitle(QMenu::tr("Setting"));
  languageMenu -> setTitle(QMenu::tr("Language"));
  enUsAction -> setText(QAction::tr("English(US)"));
  zhCnAction -> setText(QAction::tr("Chinese(Simplified)"));
  zhTwAction -> setText(QAction::tr("Chinese(Traditional)"));
  switchToMenu -> setTitle(QMenu::tr("Switch To"));
  mainPanelAction -> setText(QAction::tr("Main Panel"));
  articleTypeSelectPanelAction -> setText(QAction::tr("Article Type Select Panel"));
  typingPanelAction -> setText(QAction::tr("Typing Panel"));

  // Main panel
  articleTypeSelectPanelButton -> setText(QPushButton::tr("Article"));
  articlePanelHealthButton -> setText(QPushButton::tr("Health"));
  articlePanelSportButton -> setText(QPushButton::tr("Sport"));
  articlePanelTravelButton -> setText(QPushButton::tr("Travel"));
  articlePanelWorldButton -> setText(QPushButton::tr("World"));
  typingPanelButton -> setText(QPushButton::tr("Typing"));
  testPanelButton -> setText(QPushButton::tr("Test"));
  translatePanelButton -> setText(QPushButton::tr("Translate"));
}

void MainWindow::setLanguage(const std::string &languageType)
{
  // Check if it is different with current language
  if(translator->language().toStdString() == languageType)
  {
    std::cout << languageType << " is the current language\n";
    return;
  }

  std::cout << "MainWindow::setLanguage(\"" << languageType << "\")\n";
  std::string languageFilePath = std::string("assets/lang/") + languageType;
  translator->load(languageFilePath.c_str());
  std::cout << translator->language().toStdString() << "\n";

  this->retranslate();
  // int clickedButtonId = QMessageBox::information(this, tr("EnglishAssistant"), tr("Application restart is needed, do you want to restart now?"), QMessageBox::Yes | QMessageBox::No);
  // if(clickedButtonId == QMessageBox::Yes)
  // {
  //   // Application restart
  //   std::cout << "Application restart\n";
  // }
}

void MainWindow::switchToMainPanel()
{
  std::cout << "MainWindow::switchToMainPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(mainPanel);
}

void MainWindow::switchToArticleTypeSelectPanel()
{
  std::cout << "MainWindow::switchToarticleTypeSelectPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(articleTypeSelectPanel);
}

void MainWindow::switchToArticlePanel(const std::string &articleType)
{
  std::cout << "MainWindow::switchToarticlePanel(\"" << articleType << "\")\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(articlePanel);

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
  else
  {
    articlePanelTextBrowser->setText("Unsupport article type");
  }
}

void MainWindow::switchToTypingPanel()
{
  std::cout << "MainWindow::switchToTypingPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(typingPanel);
}

void MainWindow::switchToTestPanel()
{
  std::cout << "MainWindow::switchToTypingPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(testPanel);
}

void MainWindow::switchToTranslatePanel()
{
  std::cout << "MainWindow::switchToTranslatePanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(translatePanel);
}
