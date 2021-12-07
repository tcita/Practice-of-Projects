#ifndef ONLINE_TRANSLATOR_H
#define ONLINE_TRANSLATOR_H

#include <QString>

class OnlineTranslator {
public:
  QString translate(const QString &input, const QString &destLanguageType, const QString &srcLanguageType="auto");
};

#endif
