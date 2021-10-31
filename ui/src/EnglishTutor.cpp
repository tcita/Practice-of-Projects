#include <QtWidgets>
#include "MainWindow.h"

int main(int argc, char **argv)
{
  // Init app
  QApplication app(argc, argv);

  // Init translator
  QTranslator translator;
  translator.load(QLocale(), "/assets/zh_tw");
  app.installTranslator(&translator);

  // Init main window
  MainWindow mainWindow;
  mainWindow.resize(1200, 800);
  mainWindow.show();

  // Run app
  return app.exec();
}
