#include <iostream> //debug
// #include <QtWidgets>
#include <QDir>
#include <QApplication>
#include <QTranslator>
#include "MainWindow.h"
#include "OnlineTranslator.h"
#include "LanguageTypes.h"

int main(int argc, char **argv)
{
  // Init translator
  QTranslator translator;

  // Init app
  QApplication app(argc, argv);
  app.installTranslator(&translator);

  // Set language
  translator.load(QString("assets/lang/") + QString(LanguageTypes::zh_TW));

  // Init main window
  MainWindow mainWindow(&translator);
  mainWindow.resize(1200, 800);
  mainWindow.show();

  // Run app
  return app.exec();
}
