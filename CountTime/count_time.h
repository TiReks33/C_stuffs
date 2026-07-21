#ifndef __COUNT_TIME__
#define __COUNT_TIME__

//C

#include <stddef.h>

#if defined(WIN32)
    #include <pthread_time.h>
#else //elif defined(UNIX)
    #include <time.h>
#endif //WIN32/UNIX


typedef struct timespec timespec;


enum { NS_PER_SECOND = 1000000000 };


// nanosleep based
inline int sleep_nano_ms(long miliseconds)
{
   timespec rem;
   timespec req = {
       (int)(miliseconds / 1000),     /* secs (Must be Non-Negative) */
       (miliseconds % 1000) * 1000000 /* nano (Must be in range of 0 to 999999999) */
   };

   return nanosleep(&req , &rem);
}


// clock_nanosleep based
inline int sleep_clock_ms(long milisec)
{
    timespec res;
    res.tv_sec = (int) (milisec/1000);
    res.tv_nsec = (milisec % 1000) * 1000000;

    return clock_nanosleep(CLOCK_MONOTONIC, 0, &res, NULL);
}


double diff_timespec(timespec t1, timespec t2);


// get current time for timespec
inline timespec get_cur_time()
{   
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts;
}


timespec upd_timespec(timespec t1);


// how much time passed since start timespec
inline double time_passed(timespec start_time)
{   
    return diff_timespec(start_time, get_cur_time());
}


#endif // __COUNT_TIME__



