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

int main(int argc, char **argv)
{
  // Init java web crawler
  // Crawler crawler;
  // crawler.fetchArticleTitles("africa");
  // crawler.fetchArticle("An American teacher held in Libya for 6 weeks is now back home in the United States");

  // std::string article = Solution::readFile("./tmp/crawed_content.txt");
  // std::vector<std::string> bannedWords{"a", "is", "the"};
  // std::cout << Solution::wordFrequency(article, bannedWords);

  // Init translator
  QTranslator translator;

  // Init crawler
  Crawler crawler;

  // Init app
  QApplication app(argc, argv);
  app.installTranslator(&translator);

  // Set language
  translator.load(QString("assets/lang/") + QString(LanguageTypes::zh_TW));

  // Init main window
  MainWindow mainWindow(&translator, &crawler);
  mainWindow.resize(1200, 800);
  mainWindow.show();

  // Run app
  return app.exec();
}
