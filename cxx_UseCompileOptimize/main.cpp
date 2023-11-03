//
// Created by wjh on 10/7/23.
//
#include<bitset>
#include<iostream>
#include<typeinfo>
#include<vector>
#include<glog/logging.h>
#include<thread>
#include"cpp_name.h"
#include"common.h"
#include<functional>
struct Base {
    Base(){
        std::cout<<"Base constructor"<<std::endl;
    }
    Base(int a):a(a){
        std::cout<<"int constructor"<<std::endl;
    }
    int Fun(int & a,int & b){
        return a+b;
    }
    auto get_a() -> int{return a;}
    Base operator()(){
        return Base();
    }
private:
    int a;
}; // 非多态


struct Addd{
public:
    Addd(){
        std::cout<<"A:"<<std::endl;
    }
    Addd(int a):a(a){
        std::cout<<"int constructor"<<std::endl;
    }
    Addd operator()(){
        return Addd();
    }
    Addd operator()(int a){
        return Addd(a);
    }
private:
    int a;
};

using namespace std;
void foo(std::array<Base,2>& bases){
    cout<<cpp_type_name<decltype(bases)>()<<endl;
    for(auto a:bases){
        cout<<a.get_a()<<endl;
    }
}
std::mutex mut;
class Data_uniq_ptr{ // 用于保护互斥量
public:
    Data_uniq_ptr(int* ptr):int_ptr(ptr){
    };
    std::shared_ptr<int> int_ptr PT_GUARDED_BY(mut);
private:

};
void functionCalc(Data_uniq_ptr& dataUniqPtr){
    int i=0;
    shared_ptr<int> sharedPtr = dataUniqPtr.int_ptr;
    while(*sharedPtr.get()<100){
        ( *dataUniqPtr.int_ptr.get())++;

        this_thread::sleep_for(chrono::milliseconds(5));
    }
}
#define Conn(x,y)x##y
#define ToString(x) #x



int main(int argc,char** argv)
{

    auto fun2 =std::bind(Addd(),std::placeholders::_1);
    Addd a = std::invoke(fun2,111);

}