#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <jni.h>

using namespace std;

int main (int argc, char *argv[])
{

    JavaVM *jvm;                    /* 宣告一個java machine */
    JNIEnv *env;                     /* JNI的環境 */
    JavaVMInitArgs vm_args;
    JavaVMOption options[1];    /*自定義JRE所要的參數，就是java -... -... xxx.java將-...字串加入options中 用*/

    jint res;
    jclass cls;
    jmethodID mid;

    vm_args.version = JNI_VERSION_1_6;  /*使用的版本*/

    options[0].optionString = (char*)
    "-Djava.class.path=.;C:\\Users\\user.user-PC\\Downloads\\jsoup\\jsoup-1.14.3.jar";

    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_FALSE;

    res = JNI_CreateJavaVM(&jvm,(void**)&env,&vm_args); /*產生一個java machine*/

    jclass ver;
    jmethodID print;

    cls = env->FindClass("ex");  /*找Helloworld Class*/

    if(cls == 0)
        printf("cls error \n");

    mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V"); /*確定要執行的 function是甚麼 在這裡指的是HelloWorld裡的main 後面是main要傳的參數*/

    if(mid == 0)
        printf("mid error \n");

    env->CallStaticVoidMethod(cls, mid); /*執行此class*/

}