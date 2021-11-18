#include <iostream> //debug
#include <QMenuBar>
#include <QGridLayout>
#include <QPushButton>
#include "MainWindow.h"

MainWindow::MainWindow(QTranslator* translator)
:translator(translator)
{
  // Set icon
  this->setWindowIcon(QIcon("assets/image/icon.png"));

  QMenu *settingMenu = menuBar()->addMenu(QMenu::tr("&Setting"));
  QMenu *languageMenu = new QMenu(QMenu::tr("&Language"));

  QAction *zhTwAction = new QAction(QAction::tr("Chinese (Traditional)"), this);
  QAction *zhCnAction = new QAction(QAction::tr("Chinese (Simplified)"), this);
  QAction *mainPanelAction = new QAction(QAction::tr("Main Panel"), this);

  settingMenu->addMenu(languageMenu);

  settingMenu->addAction(mainPanelAction);
  languageMenu->addAction(zhTwAction);
  languageMenu->addAction(zhCnAction);

  QWidget *mainPanel = new QWidget();
  QWidget *healthPanel = new QWidget();
  QWidget *sportPanel = new QWidget();
  QWidget *travelPanel = new QWidget();
  QWidget *worldPanel = new QWidget();

  QPushButton *learningPanelButton = new QPushButton(QPushButton::tr("Learning"));
  QPushButton *typingPanelButton = new QPushButton(QPushButton::tr("Typing"));

  QGridLayout *mainPanelLayout = new QGridLayout();
  mainPanelLayout->addWidget(learningPanelButton, 0, 0);

  QObject::connect(zhTwAction, SIGNAL(triggered()), this, SLOT(MainWindow::setLanguageZhTw()));
  QObject::connect(zhCnAction, &QAction::triggered, this, &MainWindow::setLanguageZhCn);
  // QObject::connect(mainPanelAction, &QAction::triggered, changeMainPanel);
  // QObject::connect(learningPanelButton, &QPushButton::clicked, changeHealthPanel);
  // QObject::connect(learningPanelButton, &QPushButton::clicked, changeSportPanel);
  // QObject::connect(learningPanelButton, &QPushButton::clicked, changeTravelPanel);
  // QObject::connect(learningPanelButton, &QPushButton::clicked, changeWorldPanel);
}

void MainWindow::setLanguageZhTw(int n) //debug!!
{
  // std::cout << "MainWindow::setLanguageZhTw()\n";
  std::cout << "MainWindow::setLanguageZhTw()" << n << "\n";
}

void MainWindow::setLanguageZhCn()
{
  std::cout << "MainWindow::setLanguageZhCn()\n";
}

void MainWindow::changeMainPanel()
{
  std::cout << "MainWindow::changeMainPanel()\n";
}

void MainWindow::changeHealthPanel()
{
  std::cout << "MainWindow::changeHealthPanel()\n";
}

void MainWindow::changeSportPanel()
{
  std::cout << "MainWindow::changeSportPanel()\n";
}

void MainWindow::changeTravelPanel()
{
  std::cout << "MainWindow::changeTravelPanel()\n";
}

void MainWindow::changeWorldPanel()
{
  std::cout << "MainWindow::changeWorldPanel()\n";
}
