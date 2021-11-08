#include <iostream> //debug
#include "MainPanel.h"

MainPanel::MainPanel()
// Layout
:mainLayout(new QGridLayout())

// Button
,learningPanelButton(new QPushButton(QPushButton::tr("button0")))
,typingPanelButton(new QPushButton(QPushButton::tr("button1")))
{
  // Set layout
  this->setLayout(mainLayout);

  // Add button to layout
  mainLayout->addWidget(learningPanelButton, 0, 0);
  mainLayout->addWidget(typingPanelButton, 0, 1);

  // Connect learningPanelButton to launch learningPanel
  QObject::connect(learningPanelButton, &QPushButton::clicked,
    [=, this]()
    {
      //wip: launch learningPanel
      std::cout << this->learningPanelButton->text().toStdString() << " clicked\n"; //debug
    }
  );

  // Connect typingPanelButton to launch typingPanel
  QObject::connect(typingPanelButton, &QPushButton::clicked,
    [=, this]()
    {
      //wip: launch typingPanel
      std::cout << this->typingPanelButton->text().toStdString() << " clicked\n"; //debug
    }
  );
}
