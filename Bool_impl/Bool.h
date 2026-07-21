#ifndef __BOOL_TYPEDEF__
#define __BOOL_TYPEDEF__

// C

enum { False, True };

typedef int Bool;

inline static char const * Bool2S(Bool b__){
    static char const FalseS[] = "False", TrueS[] = "True";
    return (b__) ? TrueS : FalseS;
}


#endif //__BOOL_TYPEDEF__



