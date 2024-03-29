//
// Created by wjh on 23-10-11.
//

#ifndef CXX_CPP_NAME_H
#define CXX_CPP_NAME_H
#include<iostream>
#include<type_traits>
#include<cstdlib>
#if defined(__GNUC__) || defined(__clang__)
#include<cxxabi.h>
#endif
#endif


template <class T>
std::string cpp_type_name() {
    const char *name = typeid(T).name();
#if defined(__GNUC__) || defined(__clang__)
    int status;
    char *p = abi::__cxa_demangle(name, 0, 0, &status);
    std::string s = p;
    std::free(p);
#else
    std::string s = name;
#endif

    return s;
}