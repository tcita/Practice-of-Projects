#ifndef CRAWLER_H
#define CRAWLER_H

#include <string>
#include <jni.h>

class Crawler {
public:
  Crawler();

  static void fetchArticle();
  std::string getArticle(const std::string &articleType="");
};

#endif
