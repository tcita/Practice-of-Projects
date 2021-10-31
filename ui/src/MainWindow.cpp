#include "MainWindow.h"
#include <iostream> //debug

MainWindow::MainWindow()
{
  // Add menu bar
  QMenu *settingMenu = menuBar()->addMenu(tr("Setting"));

  // Set icon
  this->setWindowIcon(QIcon("assets/image/icon.png"));

  // Add central widget
  this->setCentralWidget(new QWidget());

  // Add buttons to central widget
  QGridLayout *centralWidgetLayout = new QGridLayout();
  this->centralWidget()->setLayout(centralWidgetLayout);

  // Add four buttons in main window
  QPushButton *button0 = new QPushButton(tr("button0"));
  centralWidgetLayout->addWidget(button0, 0, 0);
  QPushButton *button1 = new QPushButton(tr("button1"));
  centralWidgetLayout->addWidget(button1, 0, 1);
  QPushButton *button2 = new QPushButton(tr("button2"));
  centralWidgetLayout->addWidget(button2, 1, 0);
  QPushButton *button3 = new QPushButton(tr("button3"));
  centralWidgetLayout->addWidget(button3, 1, 1);

  // Connect callback to button clicked
  QObject::connect(button0, &QPushButton::clicked, [=](){std::cout << button0->text().toStdString() << "\n";});
  QObject::connect(button1, &QPushButton::clicked, [=](){std::cout << button1->text().toStdString() << "\n";});
  QObject::connect(button2, &QPushButton::clicked, [=](){std::cout << button2->text().toStdString() << "\n";});
  QObject::connect(button3, &QPushButton::clicked, [=](){std::cout << button3->text().toStdString() << "\n";});
}
