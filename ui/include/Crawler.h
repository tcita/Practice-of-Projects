#ifndef CRAWLER_H
#define CRAWLER_H

#include <string>
#include <vector>
#include <jni.h>

class Crawler {
public:
  static constexpr const char *ARTICLE_TITLE_FILE_PATH = "./lib/crawler/tmp/article_list.txt";
  static constexpr const char *ARTICLE_FILE_PATH = "./lib/crawler/tmp/crawed_content.txt";

private:
  JNIEnv *env;                     /* JNI的環境 */
  jobject javaCrawler;
  jmethodID methodID_1;
  jmethodID methodID_2;
  jmethodID methodID_3;
  jmethodID methodID_4;

public:
  Crawler();

  std::vector<std::string> fetchArticleTitles(const std::string &articleType);
  std::string fetchArticle(const std::string &articleTitle);
  std::string getArticle(const std::string &articleType="");

private:
  jstring toJString(const std::string &string);
};

#endif
