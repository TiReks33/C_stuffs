#include <stdio.h>

#include <string.h>
#include <stdlib.h>

#include "strings_vector.h"


// ::Split string by non-escaped whitespace character and adds splitted parts to 'strings_vector'::
//
// Escaped by '\\' (backslash) character parts of string will be accepted as one monolithic part.


void split_with_backslash(char const * s, size_t s_len, strings_vector ** ret)
{
    char * ss = (char*) malloc(sizeof(char) * s_len + 1);
    if(!ss)
    {
        fprintf(stderr, "'%s' error: buffer alloc failed!\n", __func__);
    }

    Bool Escape = False;
    char ps = 0;
    size_t i = 0, seq_length = 0;
    
    for(; i != s_len ; ++i)
    {
        switch((ps = s[i]))
        {
            default:
                /*//########
                if(Escape)
                {
                    ss[seq_length++] = '\\';
                }
                //######33*/
                ss[seq_length++] = ps;
                Escape = False;
                break;

            case ' ': // case '\t': case '\n':
                if(!Escape)
                {
                    if(seq_length > 0)
                    {
                        ss[seq_length] = '\0';
                        sv_push_back(*ret, ss);
                        seq_length = 0;
                    }
                    ss[0] = '\0';  
                }
                else
                {
                    ss[seq_length++] = ps; // if escaped space is needs to be included in the string

                    Escape = False;
                }
                break;
            
            /*case '\\':
                Escape = True;
                break;*/
            case '\\':
                if(Escape)
                {
                    ss[seq_length++] = ps;
                    Escape = False;
                }
                else
                {
                    Escape = True;
                }
                break;
        }//switch
    }//for

    if(seq_length > 0)
    {
        ss[seq_length] = '\0';
        sv_push_back(*ret, ss); // push final sub-string (if not empty)
    }

    free(ss);
} 



