#include <iostream> //debug
// #include <QtWidgets>
#include <QDir>
#include <QApplication>
#include <QTranslator>
#include "MainWindow.h"
#include "OnlineTranslator.h"
#include "LanguageTypes.h"
#include <jni.h>

int main(int argc, char **argv)
{
  /****************************************************************************************************
  * Set up JNI
  ****************************************************************************************************/
  JavaVM *jvm;                    /* 宣告一個java machine */
  JNIEnv *env;                     /* JNI的環境 */
  JavaVMInitArgs vm_args;
  JavaVMOption options[1];    /*自定義JRE所要的參數，就是java -... -... xxx.java將-...字串加入options中 用*/

  jint res;
  jclass clazz;
  jmethodID methodID_1;
  jmethodID methodID_2;
  jmethodID methodID_3;
  jmethodID methodID_4;

  vm_args.version = JNI_VERSION_1_6;  /*使用的版本*/

  options[0].optionString = (char*)
  "-Djava.class.path=.;C:\\Users\\user.user-PC\\Downloads\\jsoup\\jsoup-1.14.3.jar";

  vm_args.nOptions = 1;
  vm_args.options = options;
  vm_args.ignoreUnrecognized = JNI_FALSE;

  res = JNI_CreateJavaVM(&jvm,(void**)&env,&vm_args); /*產生一個java machine*/

  jclass ver;
  jmethodID print;

  clazz = env->FindClass("Scraper");  /*找Helloworld Class*/

  jmethodID constructor = env->GetMethodID(clazz, "<init>", "()V");
  jobject object = env->NewObject(clazz, constructor);

  // find getmethodid instruction
  methodID_1 = env->GetMethodID(clazz, "setArticle_list", "(Ljava/lang/String;)V"); /*確定要執行的 function是甚麼 在這裡指的是HelloWorld裡的main 後面是main要傳的參數*/
  methodID_2 = env->GetMethodID(clazz, "setArticle_url_list","(Ljava/lang/String;)V");
  methodID_3 = env->GetMethodID(clazz, "setChosed_doc", "(Ljava/lang/String;)V");
  methodID_4 = env->GetMethodID(clazz, "crawl_article", "()V");

  jstring str_1 = env->NewStringUTF("/africa");
  jstring str_2 = env->NewStringUTF("Madagascar boat accident kills at least 64; minister swims to safety from helicopter crash at site");

  // // scr.setArticle_list("/africa");
  env -> CallVoidMethod(object, methodID_1, str_1); /*執行此class*/
  env -> CallVoidMethod(object, methodID_2, str_1);
  env -> CallVoidMethod(object, methodID_3, str_2);
  env -> CallVoidMethod(object, methodID_4);

  /****************************************************************************************************
  * Set up Qt
  ****************************************************************************************************/
  // Init translator
  QTranslator translator;

  // Init app
  QApplication app(argc, argv);
  app.installTranslator(&translator);

  // Set language
  translator.load(QString("assets/lang/") + QString(LanguageTypes::zh_TW));

  // Init main window
  MainWindow mainWindow(&translator);
  mainWindow.resize(1200, 800);
  mainWindow.show();

  // Run app
  return app.exec();
}
