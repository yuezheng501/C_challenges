#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000
int  sum (int count,...) {
    int sum=0;
    va_list valist;
    va_start(valist, count);
    for (int i=0; i<count; i++) {
        sum=sum+va_arg(valist, int);
    }
    va_end(valist);
    return sum;
}

int min(int count,...) {
    int min = 0;
    int var;
    va_list valist;
    va_start(valist, count);
    min = va_arg(valist, int);
    for (int i=0; i<count-1; i++) {
        var = va_arg(valist, int);
        if (var<min) {
            min = var;
        }
    }
    va_end(valist);
    return min;
}

int max(int count,...) {
    int max = 0;
    int var;
    va_list valist;
    va_start(valist, count);
    max = va_arg(valist, int);
    for (int i=0; i<count-1; i++) {
        var = va_arg(valist, int);
        if (var>max) {
            max = var;
        }
    }
    va_end(valist);
    return max;
}

int test_implementations_by_sending_three_elements() {
