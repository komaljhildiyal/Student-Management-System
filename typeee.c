#include<stdio.h>
#include<windows.h>

void type(const char *text) {
    while (*text) {
        printf("%c", *text++);
        fflush(stdout);
        Sleep(60); 
    }
}