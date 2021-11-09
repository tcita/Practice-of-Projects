#include <iostream> //debug
#include <QtWidgets>
#include "MainWindow.h"

int main(int argc, char **argv)
{
  // Init app
  QApplication app(argc, argv);

  // Init translator
  QTranslator translator;
  std::cout << QDir::currentPath().toStdString() << "\n"; //debug
  translator.load("zh_tw");
  std::cout << "isEmpty() " << translator.isEmpty() << "\n"; //debug
  std::cout << "language() " << translator.language().toStdString() << "\n"; //debug
  app.installTranslator(&translator);

  // Init main window
  MainWindow mainWindow;
  mainWindow.resize(1200, 800);
  mainWindow.show();

  // Run app
  return app.exec();
}
