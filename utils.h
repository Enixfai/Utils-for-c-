#pragma once 

#include <chrono>



enum struct TimeUnit{
    Microseconds, 
    Milliseconds, 
    Seconds,
    Minutes
};



class Timer_func{
private:
protected:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
    


    TimePoint start;
    TimePoint end;
public:

    virtual ~Timer_func()=default;
    virtual void set_milliseconds()=0;
    virtual void set_microseconds()=0;
    virtual void set_minutes()=0;
    virtual void set_seconds()=0;



    virtual void start_timer()=0;
    virtual void end_timer()=0;

    virtual double get_time()=0;
};





class Timer: public Timer_func{
private: 
    TimeUnit curr_unit = TimeUnit::Milliseconds;

public:
    Timer()=default;
    
    
    void set_milliseconds() override { curr_unit = TimeUnit::Milliseconds; }
    void set_microseconds() override { curr_unit = TimeUnit::Microseconds; }
    void set_seconds()      override { curr_unit = TimeUnit::Seconds; }
    void set_minutes()      override { curr_unit = TimeUnit::Minutes; }

    void start_timer() override {
        start = std::chrono::high_resolution_clock::now();
    }
    
    void end_timer() override {
        end = std::chrono::high_resolution_clock::now();
    }

    double get_time () override{

        std::chrono::duration<double> time_diff = end-start;
        switch(curr_unit){
            case TimeUnit::Milliseconds:
                return time_diff.count()/1000;
            case TimeUnit::Microseconds:
                return time_diff.count();
            case TimeUnit::Seconds:
                return time_diff.count()*1000;
            case TimeUnit::Minutes:
                return time_diff.count()*1000000;
            default: return 0;
        }
    }

    
};



