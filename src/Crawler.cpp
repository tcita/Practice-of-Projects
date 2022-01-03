#include "Crawler.h"
#include "Solution.h"
#include <iostream>
#include <cstdio>
#include <memory>

Crawler::Crawler()
{
  JavaVM *jvm;                    /* 宣告一個java machine */

  JavaVMOption options[1];    /*自定義JRE所要的參數，就是java -... -... xxx.java將-...字串加入options中 用*/
  options[0].optionString = (char*) "-Djava.class.path=.;./lib/crawler;./lib/jsoup/jsoup-1.14.3.jar";

  JavaVMInitArgs vm_args;
  vm_args.version = JNI_VERSION_1_6;  /*使用的版本*/
  vm_args.nOptions = 1;
  vm_args.options = options;
  vm_args.ignoreUnrecognized = JNI_FALSE;

  jint res = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args); /*產生一個java machine*/
  // The java crawler class file
  jclass javaCrawlerClass = env->FindClass("Scraper");  /*找Helloworld Class*/
  // Constructor of java crawler
  jmethodID constructor = env->GetMethodID(javaCrawlerClass, "<init>", "()V");
  // The instance of java crawler
  javaCrawler = env->NewObject(javaCrawlerClass, constructor);

  // find getmethodid instruction
  methodID_1 = env->GetMethodID(javaCrawlerClass, "setArticle_list", "(Ljava/lang/String;)V"); /*確定要執行的 function是甚麼 在這裡指的是HelloWorld裡的main 後面是main要傳的參數*/
  methodID_2 = env->GetMethodID(javaCrawlerClass, "setArticle_url_list","(Ljava/lang/String;)V");
  methodID_3 = env->GetMethodID(javaCrawlerClass, "setChosed_doc", "(Ljava/lang/String;)V");
  methodID_4 = env->GetMethodID(javaCrawlerClass, "crawl_article", "()V");
  methodID_5 = env->GetMethodID(javaCrawlerClass, "clear", "()V");
}

// void Crawler::clear()
// {
//   env->CallVoidMethod(javaCrawler, methodID_5);
// }

std::vector<std::string> Crawler::fetchArticleTitles(const std::string &articleType)
{
  // Clear
  env->CallVoidMethod(javaCrawler, methodID_5);

  const std::string articleTypeWithSlash = std::string("/") + articleType;

  env->CallVoidMethod(javaCrawler, methodID_1, toJString(articleTypeWithSlash));
  env->CallVoidMethod(javaCrawler, methodID_2, toJString(articleTypeWithSlash));

  std::vector<std::string> articleTitles = Solution::splitString(Solution::readFile(ARTICLE_TITLE_FILE_PATH), '\n');

  return articleTitles;
}

std::string Crawler::fetchArticle(const std::string &articleTitle)
{
  // std::string articleTitle("An American teacher held in Libya for 6 weeks is now back home in the United States");
  env->CallVoidMethod(javaCrawler, methodID_3, toJString(articleTitle));
  env->CallVoidMethod(javaCrawler, methodID_4);

  std::string article = Solution::readFile(ARTICLE_FILE_PATH);
  return article;
}

jstring Crawler::toJString(const std::string &string)
{
  return env->NewStringUTF(string.c_str());
}
