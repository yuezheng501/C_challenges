#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    char* w = document[n-1][m-1][k-1];
    return w;
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    char** st = document[m-1][k-1];
    return st;
}

char*** kth_paragraph(char**** document, int k) {
    char*** par=document[k-1];
    return par;
}

char**** get_document(char* text) {

    char**** doc = (char****)malloc(MAX_PARAGRAPHS*sizeof(char***));
    for (int i=0; i<MAX_PARAGRAPHS; i++){
        doc[i] = (char***)malloc(1*sizeof(char**));
        doc[i][0] = (char**)malloc(1*sizeof(char*));
        doc[i][0][0] = (char*)malloc(1*sizeof(char));
    }
    for(int n = 0, i = 0, j = 0, k = 0, l = 0; n < strlen(text); n ++) {
        if(text[n] != ' ' && text[n] != '\n' && text[n] != '.') {
            doc[i][j][k][l] = text[n];
            l++;
            doc[i][j][k] = realloc(doc[i][j][k], (l + 1) * sizeof(char));
        } else if(text[n] == ' ') {
            doc[i][j][k][l] = '\0';
            l = 0;
            k++;
            doc[i][j] = realloc(doc[i][j], (k + 1) * sizeof(char*));
            doc[i][j][k] = malloc(sizeof(char));
            continue;
        } else if(text[n] == '.') {
            doc[i][j][k][l] = '\0';
            k = l = 0;
            j++;
            doc[i] = realloc(doc[i], (j+1) * sizeof(char**));
            doc[i][j] = malloc(sizeof(char*));
            doc[i][j][k] = malloc(sizeof(char));
            continue;
        } else if(text[n] == '\n') {
            j = k = l = 0;
            i++;
            continue;
        }
    }
    return doc;
}


