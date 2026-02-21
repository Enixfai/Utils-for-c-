#pragma once 

#include <chrono>


class Timer_func{
private:
protected:
    std::chrono::milliseconds measure_unt;
    std::chrono::high_resolution_clock start;
    std::chrono::high_resolution_clock end;
public:
    virtual void set_milliseconds()=0;
    virtual void set_microseconds()=0;
    virtual void set_minutes()=0;
    virtual void set_seconds()=0;
    virtual void start_timer()=0;
    virtual void stop_timer()=0;
};


template <class T>
class Timer: public Timer_func{
private: 
public:
    Timer()=default;
    void set_milliseconds(){
        static_cast<std::chrono::milliseconds> measure_unt;
    }
    void set_mircoseconds(){
        static_cast<std::chrono::microseconds> measure_unt;
    }
    void set_seconds(){
        static_cast<std::chrono::seconds> measure_unt;
    }
    void set_minutes(){
        static_cast<std::chrono::minutes> measure_unt;
    }
    void start_timer(){
        auto start = std::chrono::high_resolution_clock::now();
    }
    void end_timer(){
    }

};



