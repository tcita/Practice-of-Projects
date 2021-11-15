#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

// The application main window
class MainWindow : public QMainWindow
{
public:
  QTranslator *translator;

  // Menu
  QMenu *settingMenu;

  // Panel
  QWidget *mainPanel;
  QWidget *learningPanel;
  QWidget *typingPanel;

  // Construtor
  MainWindow(QTranslator* translator);



};

#endif
