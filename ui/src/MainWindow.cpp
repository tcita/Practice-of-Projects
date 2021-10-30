#include "MainWindow.h"

MainWindow::MainWindow()
{
  // Add menu bar
  QMenu *menu1 = menuBar()->addMenu("選單");

  // Add central widget
  this->setCentralWidget(new QWidget());

  // Add buttons to central widget
  QGridLayout *centralWidgetLayout = new QGridLayout();
  centralWidgetLayout->addWidget(new QPushButton("button1"), 0, 0);
  centralWidgetLayout->addWidget(new QPushButton("button2"), 0, 1);
  centralWidgetLayout->addWidget(new QPushButton("button3"), 1, 0);
  centralWidgetLayout->addWidget(new QPushButton("button4"), 1, 1);
  this->centralWidget()->setLayout(centralWidgetLayout);
}
