#include "MainWindow.h"

#include <iostream> //debug
#include <QGridLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QTranslator *translator)
{
  // Set translator
  this->translator = translator;

  // Set icon
  this->setWindowIcon(QIcon("assets/image/icon.png"));

  // Set language
  translator->load("zh_tw");

  // Set central widget of main window
  this->setCentralWidget(mainPanel);

  // Add menu action to menu
  settingMenu->addAction(mainPanelAction);
  languageMenu->addAction(zhTwAction);
  languageMenu->addAction(zhCnAction);

  // main panel layout
  QGridLayout *mainPanelLayout = new QGridLayout();
  mainPanel->setLayout(mainPanelLayout);
  mainPanelLayout->addWidget(articalPanelButton, 0, 0);
  mainPanelLayout->addWidget(typingPanelButton, 0, 1);

  // artical panel layout
  QGridLayout *articalPanelLayout = new QGridLayout();
  articalPanel->setLayout(articalPanelLayout);
  articalPanelLayout->addWidget(healthPanelButton, 0, 0);
  articalPanelLayout->addWidget(sportPanelButton, 0, 1);
  articalPanelLayout->addWidget(travelPanelButton, 1, 0);
  articalPanelLayout->addWidget(worldPanelButton, 1, 1);

  QGridLayout *typingPanelLayout = new QGridLayout();
  typingPanel->setLayout(typingPanelLayout);

  // health panel layout
  QVBoxLayout *healthPanelLayout = new QVBoxLayout();
  healthPanel->setLayout(healthPanelLayout);
  healthPanelLayout->addWidget(healthPanelTextEdit);

  // sport panel layout
  QVBoxLayout *sportPanelLayout = new QVBoxLayout();
  sportPanel->setLayout(sportPanelLayout);
  sportPanelLayout->addWidget(sportPanelTextEdit);

  // travel panel layout
  QVBoxLayout *travelPanelLayout = new QVBoxLayout();
  travelPanel->setLayout(travelPanelLayout);
  travelPanelLayout->addWidget(travelPanelTextEdit);

  // world panel layout
  QVBoxLayout *worldPanelLayout = new QVBoxLayout();
  worldPanel->setLayout(worldPanelLayout);
  worldPanelLayout->addWidget(worldPanelTextEdit);

  // Action callback
  // QObject::connect(zhTwAction, SIGNAL(triggered()), this, SLOT(MainWindow::setLanguageZhTw()));
  QObject::connect(zhTwAction, &QAction::triggered, this, &MainWindow::setLanguageZhTw);
  QObject::connect(zhCnAction, &QAction::triggered, this, &MainWindow::setLanguageZhCn);
  QObject::connect(mainPanelAction, &QAction::triggered, this, &MainWindow::changeMainPanel);
  QObject::connect(articalPanelAction, &QAction::triggered, this, &MainWindow::changeArticalPanel);
  QObject::connect(typingPanelAction, &QAction::triggered, this, &MainWindow::changeTypingPanel);

  // Button callback
  QObject::connect(articalPanelButton, &QPushButton::clicked, this, &MainWindow::changeArticalPanel);
  QObject::connect(healthPanelButton, &QPushButton::clicked, this, &MainWindow::changeHealthPanel);
  QObject::connect(sportPanelButton, &QPushButton::clicked, this, &MainWindow::changeSportPanel);
  QObject::connect(travelPanelButton, &QPushButton::clicked, this, &MainWindow::changeTravelPanel);
  QObject::connect(worldPanelButton, &QPushButton::clicked, this, &MainWindow::changeWorldPanel);
  QObject::connect(typingPanelButton, &QPushButton::clicked, this, &MainWindow::changeTypingPanel);
}

void MainWindow::setLanguageZhTw(int n)
{
  // std::cout << "MainWindow::setLanguageZhTw()\n";
  std::cout << "MainWindow::setLanguageZhTw()" << n << "\n";
  // this->removeTranslator(translator);
}

void MainWindow::setLanguageZhCn()
{
  std::cout << "MainWindow::setLanguageZhCn()\n";
}

void MainWindow::changeMainPanel()
{
  std::cout << "MainWindow::changeMainPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(mainPanel);
}

void MainWindow::changeTypingPanel()
{
  std::cout << "MainWindow::changeTypingPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(typingPanel);
}

void MainWindow::changeArticalPanel()
{
  std::cout << "MainWindow::changeArticalPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(articalPanel);
}

void MainWindow::changeHealthPanel()
{
  std::cout << "MainWindow::changeHealthPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(healthPanel);
}

void MainWindow::changeSportPanel()
{
  std::cout << "MainWindow::changeSportPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(sportPanel);
}

void MainWindow::changeTravelPanel()
{
  std::cout << "MainWindow::changeTravelPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(travelPanel);
}

void MainWindow::changeWorldPanel()
{
  std::cout << "MainWindow::changeWorldPanel()\n";
  this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(worldPanel);
}
