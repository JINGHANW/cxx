//
// Created by wjh on 10/7/23.
//
#include<bitset>
#include<iostream>
#include<typeinfo>
#include<vector>
struct Base {
    Base(){
        std::cout<<"Base constructor"<<std::endl;
    }
    Base(int a):a(a){
        std::cout<<"int constructor"<<std::endl;
    }
    Base(Base & other):a(other.a){
        std::cout<<"copy constructor"<<std::endl;
    }
    Base(Base && other):a(other.a){
        std::cout<<"move constructor\t"<<a<<std::endl;
    }
private:
    int a;
}; // 非多态


int main()
{
    std::vector<Base> base_vec;
    base_vec.reserve(3);
    for(int i=0;i<3;i++){
        Base base(i);
        base_vec.emplace_back( base);
    }
}