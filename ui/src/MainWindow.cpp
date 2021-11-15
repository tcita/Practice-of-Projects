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

  // menu
  {
    settingMenu = menuBar()->addMenu(QMenu::tr("&Setting"));

    // language
    {
      QMenu *languageMenu = new QMenu(QMenu::tr("&Language"));
      settingMenu->addMenu(languageMenu);

      QAction *chineseTraditional = new QAction(QAction::tr("Chinese (Traditional)"));
      languageMenu->addAction(chineseTraditional);
      QObject::connect(chineseTraditional, &QAction::triggered,
        [=]()
        {
          std::cout << chineseTraditional->text().toStdString() << " action triggered\n";

          translator->load("zh_tw"); //debug!!
        }
      );

      QAction *chineseSimplified = new QAction(QAction::tr("Chinese (Simplified)"));
      languageMenu->addAction(chineseSimplified);
      QObject::connect(chineseSimplified, &QAction::triggered,
        [=]()
        {
          std::cout << chineseSimplified->text().toStdString() << " action triggered\n";

          translator->load("zh_cn"); //debug!!
        }
      );
    }

    QAction *mainPanelAction = new QAction(QAction::tr("Main Panel"), this);
    settingMenu->addAction(mainPanelAction);
    QObject::connect(mainPanelAction, &QAction::triggered,
      [=, this]()
      {
        std::cout << mainPanelAction->text().toStdString() << " action triggered\n";

        this->setCentralWidget(mainPanel);
      }
    );

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
