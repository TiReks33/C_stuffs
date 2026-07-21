default: count_time.lib

count_time.lib: count_time.c count_time.h
	x86_64-w64-mingw32-gcc -D_WIN32_WINNT=0x0502 -c count_time.c -o count_time.lib

clean:
	-@rm -f count_time.lib 2>/dev/null
 


