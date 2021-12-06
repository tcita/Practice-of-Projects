#include "MainWindow.h"

#include <iostream> //debug
#include <QGridLayout>
#include <QVBoxLayout>

MainWindow::MainWindow()
{
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
  mainPanelLayout->addWidget(healthPanelButton, 0, 0);
  mainPanelLayout->addWidget(sportPanelButton, 0, 1);
  mainPanelLayout->addWidget(travelPanelButton, 1, 0);
  mainPanelLayout->addWidget(worldPanelButton, 1, 1);

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
  QObject::connect(healthPanelAction, &QAction::triggered, this, &MainWindow::changeHealthPanel);
  QObject::connect(sportPanelAction, &QAction::triggered, this, &MainWindow::changeSportPanel);
  QObject::connect(travelPanelAction, &QAction::triggered, this, &MainWindow::changeTravelPanel);
  QObject::connect(worldPanelAction, &QAction::triggered, this, &MainWindow::changeWorldPanel);

  // Button callback
  QObject::connect(healthPanelButton, &QPushButton::clicked, this, &MainWindow::changeHealthPanel);
  QObject::connect(sportPanelButton, &QPushButton::clicked, this, &MainWindow::changeSportPanel);
  QObject::connect(travelPanelButton, &QPushButton::clicked, this, &MainWindow::changeTravelPanel);
  QObject::connect(worldPanelButton, &QPushButton::clicked, this, &MainWindow::changeWorldPanel);
}

void MainWindow::setLanguageZhTw(int n)
{
  // std::cout << "MainWindow::setLanguageZhTw()\n";
  std::cout << "MainWindow::setLanguageZhTw()" << n << "\n";
  this->removeTranslator(translator);
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
