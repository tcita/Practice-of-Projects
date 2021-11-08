#include <iostream> //debug
#include <QMenuBar>
#include "MainWindow.h"
#include "MainPanel.h"
#include "LearningPanel.h"

MainWindow::MainWindow()
// Menu
:settingMenu(menuBar()->addMenu(QMenu::tr("&Setting")))

// Panel
,mainPanel(new MainPanel())
,learningPanel(new LearningPanel())
{
  // Set icon
  this->setWindowIcon(QIcon("assets/image/icon.png"));

  // Add central widget
  this->setCentralWidget(mainPanel);
}
