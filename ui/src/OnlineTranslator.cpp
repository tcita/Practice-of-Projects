#include "OnlineTranslator.h"
#include <memory>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCoreApplication>
#include <QEventLoop>
#include <iostream>

std::string OnlineTranslator::translate(const std::string &input, const std::string &destLanguageType, const std::string &srcLanguageType)
{
  //debug!!
  // QString url = QString("https://translate.google.com.tw/?sl=en&tl=zh-TW&text=INPUT_TEXT&op=translate");
  // QString url = QString("https://translate.google.com.tw/?sl=") + QString(srcLanguageType.c_str()) + QString("&tl=") + QString(destLanguageType.c_str()) + QString("&text=") + QString(input.c_str()) + QString("&op=translate");

  // From: https://stackoverflow.com/questions/8085743/google-translate-vs-translate-api
  // From: https://stackoverflow.com/questions/8550147/how-to-use-google-translate-api-with-c
  // https://translate.googleapis.com/translate_a/single?client=gtx&sl=en&tl=es&dt=t&q=Hello
  // std::string url = std::string("https://translate.googleapis.com/translate_a/single?client=gtx&sl=") + srcLanguageType + std::string("&tl=") + destLanguageType + std::string("&dt=t&q=") + input;
  std::string url = std::string("https://translate.googleapis.com/translate_a/single?client=gtx&sl=") + srcLanguageType + std::string("&tl=") + destLanguageType + std::string("&dt=t&q=") + input;
  std::cout << url << std::endl;
  QNetworkAccessManager networkManager;
  QNetworkReply *networkReply = networkManager.get(QNetworkRequest(QString::fromStdString(url)));
  do
  {
    QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
  } while(!networkReply->isFinished());

  std::string replyData = networkReply->readAll().toStdString();

  networkReply->close();


  return replyData;
}
