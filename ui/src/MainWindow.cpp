#include "MainWindow.h"

MainWindow::MainWindow()
{
  // Add menu bar
  QMenu *menu1 = menuBar()->addMenu("選單");

  // Add left tool bar
  QToolBar *leftToolBar = new QToolBar(this);
  leftToolBar->setMovable(false);
  this->addToolBar(Qt::LeftToolBarArea, leftToolBar);

  // Add button to left tool bar
  QPushButton *button1 = new QPushButton("button1", this);
  leftToolBar->addWidget(button1);

  //debug add buttons to left tool bar
  for(int i=0; i<400; ++i)
  {
    leftToolBar->addWidget(new QPushButton(QString(i)));
  }

  // Add central widget
  QWidget *centralWidget = new QWidget();
  this->setCentralWidget(centralWidget);

  // Add layout to central widget
  QVBoxLayout *centralWidgetLayout = new QVBoxLayout();
  this->centralWidget()->setLayout(centralWidgetLayout);
  centralWidgetLayout->addWidget(new QPushButton("center button"));

}
