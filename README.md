# ::C stuffs::
Custom libs and wrappers that i use in my projects.  
  
## CountTime
Very handy C functions that wrapps 'nanosleep(..)' and 'clock_nanosleep(..)' (for milliseconds count of timestamps and sleep)
  
## BackslashSplit
Split string by non-escaped whitespace character and adds splitted parts to 'strings_vector' (mine C-strings vector container implementation, you may find it in 'StringsVector' repo). Escaped by '\\' (backslash) character parts of string will be accepted as one monolithic part.
  
## TrimNonEscSpace
Get substring before non-escaped whitespace. Escaped by '\\' (backslash) character parts of string will be accepted as one monolithic part.
