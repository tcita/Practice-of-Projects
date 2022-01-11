#ifndef CRAWLER_H
#define CRAWLER_H

#include <string>
#include <vector>

#include <jni.h>

// Use jni to call java crawler
class Crawler {
public:
  static constexpr const char *ARTICLE_TITLE_FILE_PATH = "./tmp/article_list.txt";
  static constexpr const char *ARTICLE_FILE_PATH = "./tmp/crawed_content.txt";

private:
  JNIEnv *env;                     /* JNI的環境 */
  jobject javaCrawler;
  jmethodID methodID_1;
  jmethodID methodID_2;
  jmethodID methodID_3;
  jmethodID methodID_4;
  jmethodID methodID_5;

public:
  Crawler();

  // void clear();
  std::vector<std::string> fetchArticleTitles(const std::string &articleType);
  std::string fetchArticle(const std::string &articleTitle);
  std::string fetchRandomArticle();

private:
  jstring toJString(const std::string &string);
};

#endif
