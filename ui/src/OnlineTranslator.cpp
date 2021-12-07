#include "OnlineTranslator.h"
#include <memory>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCoreApplication>
#include <QEventLoop>

QString OnlineTranslator::translate(const QString &input, const QString &destLanguageType, const QString &srcLanguageType)
{
  //debug!!
  // QString url = QString("https://translate.google.com.tw/?sl=en&tl=zh-TW&text=INPUT_TEXT&op=translate");
  // QString url = QString("https://translate.google.com.tw/?sl=") + QString(srcLanguageType.c_str()) + QString("&tl=") + QString(destLanguageType.c_str()) + QString("&text=") + QString(input.c_str()) + QString("&op=translate");

  // From: https://stackoverflow.com/questions/8085743/google-translate-vs-translate-api
  // From: https://stackoverflow.com/questions/8550147/how-to-use-google-translate-api-with-c
  // https://translate.googleapis.com/translate_a/single?client=gtx&sl=en&tl=es&dt=t&q=Hello
  QString url = QString("https://translate.googleapis.com/translate_a/single?client=gtx&sl=") + QString(srcLanguageType) + QString("&tl=") + QString(destLanguageType) + QString("&dt=t&q=") + QString(input);

  QNetworkAccessManager networkManager;
  QNetworkReply *networkReply = networkManager.get(QNetworkRequest(url));
  do
  {
    QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
  } while(!networkReply->isFinished());
  networkReply->close();

  //Convert to string
  QString replyData = networkReply->readAll();

  // Remove words before translated text
  // replyData.remove(0, 4);

  // Remove words after translated text
  // int translatedTextEndIndex = replyData.indexOf("\",\"");
  // replyData.remove(translatedTextEndIndex, replyData.size()-translatedTextEndIndex);

  //Extract final translated string
  // translation = translation.mid(0, translation.indexOf(",\"") - 1);


  return replyData;
}
