#include "MainWindow.h"

#include <iostream> //debug
#include <QGridLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QTranslator *translator)
{
  // Set translator
  this->translator = translator;

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
  switchMenu->addAction(articalTypeSelectPanelAction);
  switchMenu->addAction(typingPanelAction);

  // Set central widget
  this->setCentralWidget(mainPanel);

  // Setup main panel
  QGridLayout *mainPanelLayout = new QGridLayout();
  mainPanel->setLayout(mainPanelLayout);
  mainPanelLayout->addWidget(articalTypeSelectPanelButton, 0, 0);
  mainPanelLayout->addWidget(typingPanelButton, 0, 1);

  // Setup artical type select panel
  QGridLayout *articalTypeSelectPanelLayout = new QGridLayout();
  articalTypeSelectPanel->setLayout(articalTypeSelectPanelLayout);
  articalTypeSelectPanelLayout-> addWidget(articalPanelHealthButton, 0, 0);
  articalTypeSelectPanelLayout-> addWidget(articalPanelSportButton, 1, 0);
  articalTypeSelectPanelLayout-> addWidget(articalPanelTravelButton, 0, 1);
  articalTypeSelectPanelLayout-> addWidget(articalPanelWorldButton, 1, 1);


  // Setup artical panel
  QGridLayout *articalPanelLayout = new QGridLayout();
  articalPanel->setLayout(articalPanelLayout);
  articalPanelLayout->setColumnMinimumWidth(0, 200);
  articalPanelLayout->addWidget(articalPanelTextBrowser, 1, 0);

  // Setup typing panel
  QGridLayout *typingPanelLayout = new QGridLayout();
  typingPanel->setLayout(typingPanelLayout);

  // Connect action callback
  // QObject::connect(zhTwAction, SIGNAL(triggered()), this, SLOT(MainWindow::setLanguageZhTw()));
  // QObject::connect(zhTwAction, &QAction::triggered, this, &MainWindow::setLanguageZhTw, 100);
  QObject::connect(enUsAction, &QAction::triggered, [this]{this->setLanguage("en_us");});
  QObject::connect(zhCnAction, &QAction::triggered, [this]{this->setLanguage("zh_cn");});
  QObject::connect(zhTwAction, &QAction::triggered, [this]{this->setLanguage("zh_tw");});
  QObject::connect(mainPanelAction, &QAction::triggered, [this]{this->switchToMainPanel();});
  QObject::connect(articalTypeSelectPanelAction, &QAction::triggered, [this]{this->switchToArticalTypeSelectPanel();});
  QObject::connect(typingPanelAction, &QAction::triggered, [this]{this->switchToTypingPanel();});

  // Connect button callback
  QObject::connect(articalTypeSelectPanelButton, &QPushButton::clicked, [this]{this->switchToArticalTypeSelectPanel();});
  QObject::connect(articalPanelHealthButton, &QPushButton::clicked, [this]{this->switchToArticalPanel("health");});
  QObject::connect(articalPanelSportButton, &QPushButton::clicked, [this]{this->switchToArticalPanel("sport");});
  QObject::connect(articalPanelTravelButton, &QPushButton::clicked, [this]{this->switchToArticalPanel("travel");});
  QObject::connect(articalPanelWorldButton, &QPushButton::clicked, [this]{this->switchToArticalPanel("world");});
  QObject::connect(typingPanelButton, &QPushButton::clicked, [this]{this->switchToTypingPanel();});
}

void MainWindow::setLanguage(const std::string &languageType)
{
  std::cout << "MainWindow::setLanguage(\"" << languageType << "\")\n";
  // this->removeTranslator(translator);
}

void MainWindow::switchToMainPanel()
{
  std::cout << "MainWindow::switchToMainPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(mainPanel);
}

void MainWindow::switchToArticalTypeSelectPanel()
{
  std::cout << "MainWindow::switchToArticalTypeSelectPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(articalTypeSelectPanel);
}

void MainWindow::switchToArticalPanel(const std::string &articalType)
{
  std::cout << "MainWindow::switchToArticalPanel(\"" << articalType << "\")\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(articalPanel);
  if(articalType == "health") {
    articalPanelTextBrowser->setText("test string");
  }
  else {
    articalPanelTextBrowser->setText("");
  }
}

void MainWindow::switchToTypingPanel()
{
  std::cout << "MainWindow::switchToTypingPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(typingPanel);
}
