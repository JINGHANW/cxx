//
// Created by wjh on 10/7/23.
//
#include<bitset>
#include<iostream>
#include<typeinfo>
#include<vector>
#include<thread>
#include"cpp_name.h"
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
void foo_1(int  a){}
int main()
{
    array<Base,2> base{1,4};
    array<Base,2> b =base;
    foo(base);
}