#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

#include <jni.h>

namespace english_assistance {
    namespace crawler {
        // Use jni to call java crawler
        class Crawler {
        public:
            const std::filesystem::path ARTICLE_TITLE_FILE_PATH = "tmp/article_list.txt";
            const std::filesystem::path ARTICLE_FILE_PATH = "tmp/crawed_content.txt";

        private:
            JavaVM *jvm;
            JNIEnv *env;
            jobject javaCrawler;
            jmethodID methodId1;
            jmethodID methodId2;
            jmethodID methodId3;
            jmethodID methodId4;
            jmethodID methodId5;

        public:
            Crawler();
            ~Crawler();
            
            std::optional<std::vector<std::string>> fetchArticleTitles(const std::string &articleType);
            std::optional<std::string> fetchArticle(const std::string &articleTitle);
            std::optional<std::string> fetchRandomArticle();

        private:
            jstring toJString(const std::string &string);
        };
    }
}