//
// Created by wjh on 10/19/23.
//
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <chrono>
class TestTimerExample
{
public:
    TestTimerExample(boost::asio::io_context& io)
            : timer_(io, boost::asio::chrono::milliseconds (20)),
              count_(0)
    {
        timer_.async_wait(boost::bind(&TestTimerExample::print, this));
    }

    ~TestTimerExample()
    {
        std::cout << "Final count is " << count_ << std::endl;
    }

    void print()
    {

        static auto clock_after = std::chrono::high_resolution_clock::now();
        static auto clock_before = std::chrono::high_resolution_clock::now();
        clock_before = clock_after;
        clock_after = std::chrono::high_resolution_clock::now();
        timer_.expires_at(timer_.expiry() + boost::asio::chrono::milliseconds (20));
        if (count_ < 5)
        {
            std::cout << count_ << std::endl;
            std::cout<<"duration"<<std::chrono::duration_cast<std::chrono::milliseconds>(clock_after-clock_before).count()<<std::endl;
            ++count_;


            timer_.async_wait(boost::bind(&TestTimerExample::print, this));
        }
    }

private:
    boost::asio::steady_timer timer_;
    int count_;
};

int main() {
    boost::asio::io_context io;
    TestTimerExample p(io);
    io.run();

    return 0;
}



