#include <iostream> //debug
#include <QMenuBar>
#include <QGridLayout>
#include <QPushButton>
#include "MainWindow.h"

MainWindow::MainWindow()
:settingMenu(menuBar()->addMenu(QMenu::tr("&Setting")))
,mainPanel(new QWidget())
,learningPanel(new QWidget())
,typingPanel(new QWidget())
{
  // Set icon
  this->setWindowIcon(QIcon("assets/image/icon.png"));

  // main panel
  {
    // grid layout
    QGridLayout *mainLayout = new QGridLayout();

    // learning panel button
    QPushButton *learningPanelButton = new QPushButton(QPushButton::tr("Learning"));
    QObject::connect(learningPanelButton, &QPushButton::clicked,
      [=, this]()
      {
        std::cout << learningPanelButton->text().toStdString() << " clicked\n";
        this->setCentralWidget(learningPanel);
      }
    );
    mainLayout->addWidget(learningPanelButton, 0, 0);

    // typing panel button
    QPushButton *typingPanelButton = new QPushButton(QPushButton::tr("Typing"));
    QObject::connect(typingPanelButton, &QPushButton::clicked,
      [=, this]()
      {
        std::cout << typingPanelButton->text().toStdString() << " clicked\n";
        this->setCentralWidget(typingPanel);
      }
    );
    mainLayout->addWidget(typingPanelButton, 0, 1);

    mainPanel->setLayout(mainLayout);
  }

  // learning panel
  {

  }

  // Add central widget
  this->setCentralWidget(mainPanel);
}
