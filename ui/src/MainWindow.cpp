#include "MainWindow.h"
#include "Crawler.h"
#include "OnlineTranslator.h"
#include <iostream> //debug
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

MainWindow::MainWindow(QTranslator *translator)
:translator(translator)
{
  // Set translator
  // this->translator = translator;

  // Setup icon
  this->setWindowIcon(QIcon("assets/image/icon.png"));

  // Setup language
  translator->load("zh_tw");

  // Setup menu bar
  mainMenuBar->addMenu(settingMenu);
  settingMenu->addMenu(languageMenu);
  mainMenuBar->addMenu(switchMenu);
  languageMenu->addAction(enUsAction);
  languageMenu->addAction(zhCnAction);
  languageMenu->addAction(zhTwAction);
  switchMenu->addAction(mainPanelAction);
  switchMenu->addAction(articleTypeSelectPanelAction);
  switchMenu->addAction(typingPanelAction);

  // Set central widget
  this->setCentralWidget(mainPanel);

  // Setup main panel
  QGridLayout *mainPanelLayout = new QGridLayout();
  mainPanel->setLayout(mainPanelLayout);
  mainPanelLayout->addWidget(articleTypeSelectPanelButton, 0, 0);
  mainPanelLayout->addWidget(typingPanelButton, 0, 1);
  mainPanelLayout->addWidget(testPanelButton, 1, 0);

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
  QObject::connect(enUsAction, &QAction::triggered, [this]{this->setLanguage("en_us");});
  QObject::connect(zhCnAction, &QAction::triggered, [this]{this->setLanguage("zh_cn");});
  QObject::connect(zhTwAction, &QAction::triggered, [this]{this->setLanguage("zh_tw");});
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
}

void MainWindow::setLanguage(const std::string &languageType)
{
  std::cout << "MainWindow::setLanguage(\"" << languageType << "\")\n";
  std::string languageFilePath = std::string("assets/lang/") + languageType;
  translator->load(languageFilePath.c_str());
  
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
    articlePanelTextBrowser->setText(QString::fromStdString(OnlineTranslator::translate(Crawler::getArticle(), "zh-TW")));
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
