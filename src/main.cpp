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
  // std::string article = Solution::readFile("./tmp/crawed_content.txt");
  // std::vector<std::string> bannedWords = Solution::splitString(Solution::readFile("./config/bannedWords.txt"), '\n');
  // for(auto wordCount : Solution::wordFrequency(article, bannedWords))
  // {
  //   std::cout << wordCount.first << " " << wordCount.second << "\n";
  // }

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
