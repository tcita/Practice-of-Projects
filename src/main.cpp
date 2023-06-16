#include <iostream> //debug
// #include <QtWidgets>
#include <QDir>
#include <QApplication>
#include <QTranslator>
#include "MainWindow.h"
#include "OnlineTranslator.h"
#include "LanguageTypes.h"
#include <jni.h>
#include "Crawler.h"
#include "Solution.h"
#include <vector>
#include <string>

int main(int argc, char **argv) {
    QTranslator translator;
    Crawler crawler;

    // Init app
    QApplication app(argc, argv);
    app.installTranslator(&translator);

    // Init main window
    MainWindow mainWindow(&translator, &crawler);
    mainWindow.resize(1200, 800);
    mainWindow.show();

    // Run app
    return app.exec();
}
