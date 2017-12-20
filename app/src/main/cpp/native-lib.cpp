#include <jni.h>
#include <string>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "log-utils.h"

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_spmno_patest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT void JNICALL
Java_com_spmno_patest_MainActivity_openPA(JNIEnv *env, jobject instance) {

    // TODO
    int ivt_pa = open("/dev/audioPA", O_RDWR);
    if (ivt_pa > 0) {
        LOGI("open device %s success, fd = %d.", "/dev/audioPA", ivt_pa);
    } else {
        LOGE("open device %s failed, error : %s ", "/dev/audioPA", strerror(errno));
    }
    if (ivt_pa > 0) {
        int result = ioctl(ivt_pa, 0x0f, 1);
        LOGI("ivt_pa, 0, 1 result %d, error no %d, ivt_fd:%d ", result, errno, ivt_pa);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_spmno_patest_MainActivity_closePA(JNIEnv *env, jobject instance) {

    // TODO
    int ivt_pa = open("/dev/audioPA", O_RDWR);
    if (ivt_pa > 0) {
        LOGI("open device %s success, fd = %d.", "/dev/audioPA", ivt_pa);
    } else {
        LOGE("open device %s failed, error : %s ", "/dev/audioPA", strerror(errno));
    }
    if (ivt_pa > 0) {
        int result = ioctl(ivt_pa, 0x0f, 0);
        LOGI("ivt_pa, 0, 0 result %d, error no %d, ivt_fd:%d ", result, errno, ivt_pa);
    }
}