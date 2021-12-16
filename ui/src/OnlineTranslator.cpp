#include "OnlineTranslator.h"
#include <memory>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCoreApplication>
#include <QEventLoop>
#include <iostream>

std::string OnlineTranslator::translate(const std::string &input, const std::string &destLanguageType, const std::string &srcLanguageType)
{
  // From: https://stackoverflow.com/questions/8085743/google-translate-vs-translate-api
  // From: https://stackoverflow.com/questions/8550147/how-to-use-google-translate-api-with-c
  // Use google translate to translate
  std::string url = std::string("https://translate.googleapis.com/translate_a/single?client=gtx&sl=") + srcLanguageType + std::string("&tl=") + destLanguageType + std::string("&dt=t&q=") + input;
  QNetworkAccessManager networkAccessManager;
  QNetworkReply *networkReply = networkAccessManager.get(QNetworkRequest(QString::fromStdString(url)));

  // Wait for network reply finished
  QEventLoop waitForNetworkReply;
  QObject::connect(networkReply, &QNetworkReply::finished, [&]{waitForNetworkReply.quit();});
  waitForNetworkReply.exec();

  // Put reply data to string
  std::string replyData = networkReply->readAll().toStdString();

  return replyData;
}
