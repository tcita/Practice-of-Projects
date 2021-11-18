#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

// The application main window
class MainWindow : public QMainWindow
{
public:
  QTranslator *translator;

  // Construtor
  MainWindow(QTranslator* translator);

  // Set language to zh_tw
  void setLanguageZhTw();
  void setLanguageZhTw(int n); //debug!!
  // Set language to zh_cn
  void setLanguageZhCn();

  // Change to main panel
  void changeMainPanel();
  // Change to health panel
  void changeHealthPanel();
  // Change to sport panel
  void changeSportPanel();
  // Change to travel panel
  void changeTravelPanel();
  // Change to world panel
  void changeWorldPanel();
};

#endif
