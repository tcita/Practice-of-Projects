#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// The application main window
class MainWindow : public QMainWindow
{
public:
  // Menu
  QMenu *settingMenu;

  // Panel
  QWidget* mainPanel;
  QWidget* learningPanel;
  QWidget* typingPanel;

  // Construtor
  MainWindow();



};

#endif
