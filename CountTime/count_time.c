#include "count_time.h"


// nanosleep based
extern inline int sleep_nano_ms(long miliseconds);


// clock_nanosleep based
extern inline int sleep_clock_ms(long milisec);


double diff_timespec(timespec t1, timespec t2)
{
    long nsec_ = t2.tv_nsec - t1.tv_nsec;
    time_t sec_  = t2.tv_sec - t1.tv_sec;
    if (sec_ > 0 && nsec_ < 0)
    {
        nsec_ += NS_PER_SECOND;
        sec_--;
    }
    else if (sec_ < 0 && nsec_ > 0)
    {
        nsec_ -= NS_PER_SECOND;
        sec_++;
    }

    return sec_ + (double) (nsec_ / (double) NS_PER_SECOND);
}


// get current time for timespec
extern inline timespec get_cur_time();


timespec upd_timespec(timespec t1)
{
    timespec t2 = get_cur_time();

    timespec upd;

    upd.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    upd.tv_sec  = t2.tv_sec - t1.tv_sec;
    if (upd.tv_sec > 0 && upd.tv_nsec < 0){

        upd.tv_nsec += NS_PER_SECOND;
        upd.tv_sec--;

    } else if(upd.tv_sec < 0 && upd.tv_nsec > 0){

        upd.tv_nsec -= NS_PER_SECOND;
        upd.tv_sec++;
    }

    return upd;
}


// how much time passed since start timespec
extern inline double time_passed(timespec start_time);



