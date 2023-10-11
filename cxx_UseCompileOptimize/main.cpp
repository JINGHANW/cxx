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
private:
    int a;
}; // 非多态
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
int main()
{
    Data_uniq_ptr dataUniqPtr(new int());
    vector<thread> threads;
    LOG(INFO)<<"main thread id:"<<this_thread::get_id();
    for(int i=0;i<4;i++){
        threads.push_back(std::move(thread(functionCalc,std::ref(dataUniqPtr))));
    }

    for(int i=0;i<4;i++){
        if(threads[i].joinable()){
            threads[i].join();
        }
    }
}