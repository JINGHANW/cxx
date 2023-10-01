//
// Created by wjh on 23-10-1.
//
#include<iostream>
#include<gtest/gtest.h>
#include<vector>
int test_fun(int input){
    return 2*input;
}
TEST(testRet,input){
    ASSERT_EQ(test_fun(2),4);
    ASSERT_EQ(test_fun(3),4);
}
int main(int argc,char** argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}