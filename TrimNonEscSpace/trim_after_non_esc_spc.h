#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bool.h"//"Bool_impl/Bool.h" 


// ::Get substring before non-escaped whitespace::
//
// Output result by 'return' and by pointer in third
// input parameter (NULL is allowed for 3rd param.);
//
// !!LEAKS!! (need to call 'free', because dynamically 
// allocated array for output resulting C string used)


char* trim_after_non_esc_spc(char const * c_str__, size_t str_size__, char ** outp_c_str_ptr__)
{
    char * outp_arr = (char*) malloc(sizeof(char) * str_size__ + 1);

    Bool Escape = False, exitNested = False;
    char ps = 0;
    size_t n_len = 0;

    for(size_t i = 0; i != str_size__; ++i)
    {
        if(exitNested)
            break;

        switch((ps = c_str__[i]))
        {   
            default:
                outp_arr[n_len++] = ps;
                Escape = False;
                break;

            case ' ':
                if(!Escape)
                {
                    exitNested=True;
                }
                else
                {
                    outp_arr[n_len++] = ps;
                    Escape = False;
                }
                break;

            case '\\':
                if(Escape)
                {
                    outp_arr[n_len++] = ps;
                    Escape = False;
                }
                else
                {
                    Escape = True;
                }
                break;
        }

    }
 
    outp_arr[n_len] = '\0';

    if(outp_c_str_ptr__)
        *outp_c_str_ptr__ = outp_arr;

    return outp_arr;
}



