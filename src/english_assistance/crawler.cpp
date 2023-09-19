#include <cstdio>
#include <iostream>
#include <memory>
#include <random>

#include "english_assistance/crawler.h"
#include "english_assistance/util.h"
#include "jni.h"

namespace english_assistance {
    namespace crawler {
        Crawler::Crawler() {
            char java_classpath[] = "-Djava.class.path=lib/crawler;lib/crawler/lib/jsoup-1.14.3.jar";
            JavaVMOption options[1] = {
                {
                    .optionString = java_classpath,
                    .extraInfo = nullptr,
                }
            };
            JavaVMInitArgs vm_args = {
                .version = JNI_VERSION_10,
                .nOptions = 1,
                .options = options,
                .ignoreUnrecognized = JNI_FALSE,
            };

            jint result = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
            if(result != JNI_OK) {
                std::cerr << "JNI_CreateJavaVM error: ";
                switch(result) {
                    case JNI_ERR: {
                        std::cerr << "unknown error" << std::endl;
                        break;
                    }
                    case JNI_EDETACHED: {
                        std::cerr << "thread detached from the VM" << std::endl;
                        break;
                    }
                    case JNI_EVERSION: {
                        std::cerr << "JNI version error" << std::endl;
                        break;
                    }
                    case JNI_ENOMEM: {
                        std::cerr << "not enough memory" << std::endl;
                        break;
                    }
                    case JNI_EEXIST: {
                        std::cerr << "VM already created" << std::endl;
                        break;
                    }
                    case JNI_EINVAL: {
                        std::cerr << "invalid arguments" << std::endl;
                        break;
                    }
                    default: {
                        std::cerr << "undefined error code: " << result << std::endl;
                        break;
                    }
                }
                return;
            }

            // the java Crawler class
            jclass javaCrawlerClass = env->FindClass("Crawler");
            if(javaCrawlerClass == nullptr) {
                std::cerr << "cannot find java class Crawler" << std::endl;
                return;
            }

            // get constructor id of java crawler
            jmethodID constructor = env->GetMethodID(javaCrawlerClass, "<init>", "()V");
            if(constructor == nullptr) {
                std::cerr << "cannot find constructor in java class Crawler" << std::endl;
                return;
            }

            // new a java Crawler class
            javaCrawler = env->NewObject(javaCrawlerClass, constructor);
            if(javaCrawler == nullptr) {
                std::cerr << "failed to new a java Crawler class" << std::endl;
                return;
            }

            // find defined methods
            methodId1 = env->GetMethodID(javaCrawlerClass, "setArticleList", "(Ljava/lang/String;)V");
            if(methodId1 == nullptr) {
                std::cerr << "failed to get methodId1" << std::endl;
                return;
            }
            methodId2 = env->GetMethodID(javaCrawlerClass, "setArticleUrlList","(Ljava/lang/String;)V");
            if(methodId2 == nullptr) {
                std::cerr << "failed to get methodId2" << std::endl;
                return;
            }
            methodId3 = env->GetMethodID(javaCrawlerClass, "setChosenDoc", "(Ljava/lang/String;)V");
            if(methodId3 == nullptr) {
                std::cerr << "failed to get methodId3" << std::endl;
                return;
            }
            methodId4 = env->GetMethodID(javaCrawlerClass, "crawlArticle", "()V");
            if(methodId4 == nullptr) {
                std::cerr << "failed to get methodId4" << std::endl;
                return;
            }
            methodId5 = env->GetMethodID(javaCrawlerClass, "clear", "()V");
            if(methodId5 == nullptr) {
                std::cerr << "failed to get methodId5" << std::endl;
                return;
            }

            std::cout << "end of Crawler ctor" << std::endl; // debug!
        }

        Crawler::~Crawler() {
            if(jvm) {
                jvm->DestroyJavaVM();
            }
        }

        std::optional<std::vector<std::string>> Crawler::fetchArticleTitles(const std::string &articleType) {
            // clear
            env->CallVoidMethod(javaCrawler, methodId5);

            const std::string articleTypeWithSlash = std::string("/") + articleType;

            env->CallVoidMethod(javaCrawler, methodId1, toJString(articleTypeWithSlash));
            env->CallVoidMethod(javaCrawler, methodId2, toJString(articleTypeWithSlash));

            std::vector<std::string> articleTitles = util::split(util::readFile(ARTICLE_TITLE_FILE_PATH), '\n');

            return articleTitles;
        }

        std::optional<std::string> Crawler::fetchArticle(const std::string &articleTitle) {
            env->CallVoidMethod(javaCrawler, methodId3, toJString(articleTitle));
            env->CallVoidMethod(javaCrawler, methodId4);

            std::string article = util::readFile(ARTICLE_FILE_PATH);
            return article;
        }

        std::optional<std::string> Crawler::fetchRandomArticle() {
            std::string randomArticleType = "africa"; // todo! add more possible titles
            std::optional<std::vector<std::string>> articleTitles = fetchArticleTitles(randomArticleType);
            if(!articleTitles) {
                return std::nullopt;
            }

            if(articleTitles.value().empty()) {
                return std::nullopt;
            }
            
            // Get distribute
            // From: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution/
            std::random_device randomDevice;
            std::mt19937 seedGenerator(randomDevice());
            std::uniform_int_distribution<int> distribute(0, articleTitles.value().size());
            int randomTitleIndex = distribute(seedGenerator);
            std::optional<std::string> randomArticle = fetchArticle(articleTitles.value()[randomTitleIndex]);
             
            if(!randomArticle) {
                return std::nullopt;
            }

            return randomArticle;
        }

        jstring Crawler::toJString(const std::string &string) {
            return env->NewStringUTF(string.c_str());
        }
    }
}