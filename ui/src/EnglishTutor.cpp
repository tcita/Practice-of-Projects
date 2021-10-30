#include <QtWidgets>
#include "MainWindow.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  MainWindow mainWindow;
  mainWindow.setFixedSize(1200, 800);
  mainWindow.show(); 

  return app.exec();
}
