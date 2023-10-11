//
// Created by wjh on 10/16/23.
//

#ifndef USE_COMPILEOPTIMIZE_COMMON_H
#define USE_COMPILEOPTIMIZE_COMMON_H
#include<memory>
#include<mutex>
#if defined(__SUPPORT_TS_ANNOTATION__) || defined(__clang__)
#define THREAD_ANNOTATION_ATTRIBUTE__(x) __attribute__((x))
#else
#define THREAD_ANNOTATION_ATTRIBUTE__(x)  // no-op
#endif

#define PT_GUARDED_BY(x) THREAD_ANNOTATION_ATTRIBUTE__(pt_guarded_by(x))
#endif //USE_COMPILEOPTIMIZE_COMMON_H
