#include <iostream> //debug
#include <QMenuBar>
#include <QGridLayout>
#include <QPushButton>
#include "MainWindow.h"

MainWindow::MainWindow()
{
  // Set icon
  this->setWindowIcon(QIcon("assets/image/icon.png"));

  // menu
  {
    settingMenu = menuBar()->addMenu(QMenu::tr("&Setting"));

    {
      settingMenu->addMenu(QMenu::tr("&Language")); //debug!!

    }

    QAction *helloAction = new QAction(QAction::tr("&hello"), this);
    settingMenu->addAction(helloAction);
    QObject::connect(helloAction, &QAction::triggered,
      [=]()
      {
        std::cout << helloAction->text().toStdString() << " action triggered\n";

      }
    );

    QAction *worldAction = new QAction(QAction::tr("&world"), this);
    settingMenu->addAction(worldAction);
    QObject::connect(worldAction, &QAction::triggered,
      [=]()
      {
        std::cout << worldAction->text().toStdString() << " action triggered\n";
      }
    );
  }

  // main panel
  {
    mainPanel = new QWidget();
    // grid layout
    QGridLayout *mainLayout = new QGridLayout();

    // learning panel button
    QPushButton *learningPanelButton = new QPushButton(QPushButton::tr("Learning"));
    mainLayout->addWidget(learningPanelButton, 0, 0);
    QObject::connect(learningPanelButton, &QPushButton::clicked,
      [=, this]()
      {
        std::cout << learningPanelButton->text().toStdString() << " button clicked\n";
        this->setCentralWidget(learningPanel);
      }
    );

    // typing panel button
    QPushButton *typingPanelButton = new QPushButton(QPushButton::tr("Typing"));
    mainLayout->addWidget(typingPanelButton, 0, 1);
    QObject::connect(typingPanelButton, &QPushButton::clicked,
      [=, this]()
      {
        std::cout << typingPanelButton->text().toStdString() << " button clicked\n";
        this->setCentralWidget(typingPanel);
      }
    );

    mainPanel->setLayout(mainLayout);
  }

  // learning panel
  {
    learningPanel = new QWidget();
  }

  // typing panel
  {
    typingPanel = new QWidget();
  }

  // Add central widget
  this->setCentralWidget(mainPanel);
}
