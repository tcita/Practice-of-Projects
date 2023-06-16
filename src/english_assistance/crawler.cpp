#include "english_assistance/crawler.h"
#include "english_assistance/util.h"

#include <iostream>
#include <cstdio>
#include <memory>
#include <random>

namespace english_assistance {
    Crawler::Crawler() {
        JavaVMOption options[1];    /*自定義JRE所要的參數，就是java -... -... xxx.java將-...字串加入options中 用*/
        options[0].optionString = (char*) "-Djava.class.path=.;./lib/crawler;./lib/jsoup/jsoup-1.14.3.jar";

        JavaVMInitArgs vm_args;
        vm_args.version = JNI_VERSION_10;
        vm_args.nOptions = 1;
        vm_args.options = options;
        vm_args.ignoreUnrecognized = JNI_FALSE;

        jint res = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
        // The java crawler class file
        jclass javaCrawlerClass = env->FindClass("Crawler");
        // Constructor of java crawler
        jmethodID constructor = env->GetMethodID(javaCrawlerClass, "<init>", "()V");
        // The instance of java crawler
        javaCrawler = env->NewObject(javaCrawlerClass, constructor);

        // find defined methods
        methodID_1 = env->GetMethodID(javaCrawlerClass, "setArticle_list", "(Ljava/lang/String;)V");
        methodID_2 = env->GetMethodID(javaCrawlerClass, "setArticle_url_list","(Ljava/lang/String;)V");
        methodID_3 = env->GetMethodID(javaCrawlerClass, "setChosed_doc", "(Ljava/lang/String;)V");
        methodID_4 = env->GetMethodID(javaCrawlerClass, "crawl_article", "()V");
        methodID_5 = env->GetMethodID(javaCrawlerClass, "clear", "()V");
    }

    Crawler::~Crawler() {
        if(jvm) {
            jvm->DestroyJavaVM();
        }
    }

    std::vector<std::string> Crawler::fetchArticleTitles(const std::string &articleType) {
        // Clear
        env->CallVoidMethod(javaCrawler, methodID_5);

        const std::string articleTypeWithSlash = std::string("/") + articleType;

        env->CallVoidMethod(javaCrawler, methodID_1, toJString(articleTypeWithSlash));
        env->CallVoidMethod(javaCrawler, methodID_2, toJString(articleTypeWithSlash));

        std::vector<std::string> articleTitles = util::split(util::readFile(ARTICLE_TITLE_FILE_PATH), '\n');

        return articleTitles;
    }

    std::string Crawler::fetchArticle(const std::string &articleTitle) {
        // std::string articleTitle("An American teacher held in Libya for 6 weeks is now back home in the United States");
        env->CallVoidMethod(javaCrawler, methodID_3, toJString(articleTitle)); // also print stuff
        env->CallVoidMethod(javaCrawler, methodID_4); // also print stuff

        std::string article = util::readFile(ARTICLE_FILE_PATH);
        return article;
    }

    std::string Crawler::fetchRandomArticle() {
        const std::vector<std::string> &articleTitles = fetchArticleTitles("africa");

        // Get distribute
        // From: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution/
        std::random_device randomDevice;
        std::mt19937 seedGenerator(randomDevice());
        std::uniform_int_distribution<int> distribute(0, articleTitles.size());
        int randomTitleIndex = distribute(seedGenerator);
        const std::string& randomArticle = fetchArticle(articleTitles[randomTitleIndex]);

        return randomArticle;
    }

    jstring Crawler::toJString(const std::string &string) {
        return env->NewStringUTF(string.c_str());
    }
}