#include <iostream> //debug
// #include <QtWidgets>
#include <QApplication>
#include <QTranslator>
#include <QMainWindow>
#include "MainWindow.h"
#include "OnlineTranslator.h"

int main(int argc, char **argv)
{
  // Init app
  QApplication app(argc, argv);

  // Init translator
  QTranslator translator;
  translator.load("assets/lang/zh_tw");
  translator.load("assets/lang/zh_cn");
  std::cout << "isEmpty() " << translator.isEmpty() << "\n"; //debug
  std::cout << "language() " << translator.language().toStdString() << "\n"; //debug
  app.installTranslator(&translator);

  // Init main window
  MainWindow mainWindow(&translator);
  mainWindow.resize(1200, 800);
  mainWindow.show();

  // Run app
  return app.exec();
}
