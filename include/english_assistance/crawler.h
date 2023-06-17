#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <jni.h>

namespace english_assistance {
    // Use jni to call java crawler
    class Crawler {
    public:
        const std::filesystem::path ARTICLE_TITLE_FILE_PATH = "tmp/article_list.txt";
        const std::filesystem::path ARTICLE_FILE_PATH = "tmp/crawed_content.txt";

    private:
        JavaVM *jvm;
        JNIEnv *env;
        jobject javaCrawler;
        jmethodID methodId_1;
        jmethodID methodId_2;
        jmethodID methodId_3;
        jmethodID methodId_4;
        jmethodID methodId_5;

    public:
        Crawler();
        ~Crawler();
        
        std::vector<std::string> fetchArticleTitles(const std::string &articleType);
        std::string fetchArticle(const std::string &articleTitle);
        std::string fetchRandomArticle();

    private:
        jstring toJString(const std::string &string);
    };
}