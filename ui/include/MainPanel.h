#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class MainPanel : public QWidget {
public:
  // Layout
  // top layout
  QGridLayout *mainLayout;

  // Button
  // button to learningPanel
  QPushButton *learningPanelButton;
  // button to typingPanel
  QPushButton *typingPanelButton;

  // Constructor
  MainPanel();
};

#endif
