#include "Crawler.h"
#include <cstdio>
#include <memory>

Crawler::Crawler()
{
}

void Crawler::fetchArticle()
{
    JavaVM *jvm;                    /* 宣告一個java machine */
    JNIEnv *env;                     /* JNI的環境 */
    JavaVMInitArgs vm_args;
    JavaVMOption options[1];    /*自定義JRE所要的參數，就是java -... -... xxx.java將-...字串加入options中 用*/

    jmethodID methodID_1;
    jmethodID methodID_2;
    jmethodID methodID_3;
    jmethodID methodID_4;

    vm_args.version = JNI_VERSION_1_6;  /*使用的版本*/

    options[0].optionString = (char*) "-Djava.class.path=.;./lib/crawler/Scraper.class;./lib/jsoup/jsoup-1.14.3.jar";
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_FALSE;

    jint res = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args); /*產生一個java machine*/

    // The java crawler class file
    jclass crawlerClass = env->FindClass("Scraper");  /*找Helloworld Class*/
    // Constructor of java crawler
    jmethodID constructor = env->GetMethodID(crawlerClass, "<init>", "()V");
    // The instance of java crawler
    jobject object = env->NewObject(crawlerClass, constructor);

    // find getmethodid instruction
    methodID_1 = env->GetMethodID(crawlerClass, "setArticle_list", "(Ljava/lang/String;)V"); /*確定要執行的 function是甚麼 在這裡指的是HelloWorld裡的main 後面是main要傳的參數*/
    methodID_2 = env->GetMethodID(crawlerClass, "setArticle_url_list","(Ljava/lang/String;)V");
    methodID_3 = env->GetMethodID(crawlerClass, "setChosed_doc", "(Ljava/lang/String;)V");
    methodID_4 = env->GetMethodID(crawlerClass, "crawl_article", "()V");

    jstring articleType = env->NewStringUTF("/africa");
    jstring articleTitle = env->NewStringUTF("An American teacher held in Libya for 6 weeks is now back home in the United States");

    env -> CallVoidMethod(object, methodID_1, articleType); /*執行此class*/
    env -> CallVoidMethod(object, methodID_2, articleType);
    env -> CallVoidMethod(object, methodID_3, articleTitle);
    env -> CallVoidMethod(object, methodID_4);
}

std::string Crawler::getArticle(const std::string &articleType)
{
  std::string testString("A simlpe test string"); //debug!!
  return testString;
}
