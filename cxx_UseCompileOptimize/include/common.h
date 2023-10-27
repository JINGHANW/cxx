//
// Created by wjh on 10/16/23.
//
#include <iostream>
#include <map>
#include <string>
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
#endif
#ifndef __REFLECT_H
#define __REFLECT_H
#include<functional>


template <typename ClassName>
class ClassRegister
{
public:
    typedef ClassName* (*Constructor)(void);

private:
    typedef std::map<std::string, Constructor> ClassMap;
    ClassMap                                   constructor_map_;

public:
    void AddConstructor(const std::string class_name, Constructor constructor)
    {
        typename ClassMap::iterator it = constructor_map_.find(class_name);
        if (it != constructor_map_.end()) {
            std::cout << "error!";
            return;
        }
        constructor_map_[ class_name ] = constructor;
    }

    ClassName* CreateObject(const std::string class_name) const
    {
        typename ClassMap::const_iterator it = constructor_map_.find(class_name);
        if (it == constructor_map_.end()) {

            return nullptr;
        }
        return (*(it->second))();
    }
};

template <typename ClassName>
ClassRegister<ClassName>& GetRegister()
{
    static ClassRegister<ClassName> class_register;
    return class_register;
}

template <typename BaseClassName, typename SubClassName>
BaseClassName* NewObject()
{
    return new SubClassName();
}

template <typename BaseClassName>
class ClassRegisterHelper
{
public:
    ClassRegisterHelper(const std::string sub_class_name, typename ClassRegister<BaseClassName>::Constructor constructor)
    {
        GetRegister<BaseClassName>().AddConstructor(sub_class_name, constructor);
    }
    ~ClassRegisterHelper()
    {
    }
};


#endif
