//
// Created by sunqp on 17-12-8.
//

#ifndef PATEST_LOG_UTILS_H
#define PATEST_LOG_UTILS_H

#include <android/log.h>

#define DEBUG 1

#define TAG ""

#if DEBUG
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO,  TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##args)
#else
#define LOGI(fmt, args...) asm("nop")
#define LOGD(fmt, args...) asm("nop")
#define LOGE(fmt, args...) asm("nop")
#endif

#endif //PATEST_LOG_UTILS_H
