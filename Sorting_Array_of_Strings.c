#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int ans=0;
    if (strcmp(a, b)>0) {
         ans=1;
    }
    return ans;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int ans=0;
    if (strcmp(a, b)<0) {
         ans=1;
    }
    return ans;
}

int distinct_count(const char* x){
    int count[100]={0};
    int uniqnum=0;
    for (int i=0; i<strlen(x); i++) {
       count[x[i]-'a']++;
    }
    for (int i=0; i<100; i++) {
        if (count[i]) {
            uniqnum++;
        }
    }
    return uniqnum;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int ans=0;
    if (distinct_count(a)>distinct_count(b)){
        ans = 1;
    }
    else if (distinct_count(a)==distinct_count(b)) {
        ans = lexicographic_sort(a,b);
    }
    return ans;
}

int sort_by_length(const char* a, const char* b) {
    int ans=0;
    if (strlen(a)>strlen(b)){
        ans = 1;
    }
    else if (strlen(a)==strlen(b)) {
        ans = lexicographic_sort(a,b);
    }
    return ans;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i=0; i< len-1; i++) {
        for (int j=i+1; j<len; j++) {
            if(cmp_func(arr[i],arr[j])==1){
                char* temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

}


