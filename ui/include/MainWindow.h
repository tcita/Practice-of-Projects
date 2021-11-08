#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MainPanel.h"
#include "LearningPanel.h"

// The application main window
class MainWindow : public QMainWindow
{
public:
  // Central widget
  // welcome panel
  MainPanel* mainPanel;
  // learning stuff, show crawler result
  LearningPanel* learningPanel;
  // typing speed test
  QWidget* typingPanel;

  // Menu
  // the top left setting menu
  QMenu *settingMenu;


  // Construtor
  MainWindow();



};

#endif
