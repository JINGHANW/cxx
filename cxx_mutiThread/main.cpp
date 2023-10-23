//
// Created by wjh on 23-10-23.
//
#include<iostream>
#include<condition_variable>
#include<thread>
#include<mutex>
std::mutex global_mutex;
void do_something(std::unique_lock<std::mutex>& lock,std::condition_variable cv){
        
}
int main(int argv,char ** argc){
    std::condition_variable condition;
}