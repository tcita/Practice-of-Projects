#include <string>
#include <vector>

#include <jni.h>
#include <QtWidgets>

#include "english_assistance/crawler.h"
#include "english_assistance/ui/main_window.h"
#include "english_assistance/util.h"

int main(int argc, char **argv) {
    QTranslator translator;
    english_assistance::Crawler crawler;

    // Init app
    QApplication app(argc, argv);
    app.installTranslator(&translator);

    // Init main window
    english_assistance::MainWindow mainWindow(&translator, &crawler);
    mainWindow.resize(1200, 800);
    mainWindow.show();

    // Run app
    return app.exec();
}
