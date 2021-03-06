#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    struct document doc;
    doc.paragraph_count=0;

    doc.data = (struct paragraph*)malloc(1*sizeof(struct paragraph));
    doc.data[0].data =(struct sentence*)malloc(1*sizeof(struct sentence));
    doc.data[0].sentence_count = 0;
    doc.data[0].data[0].data = (struct word*)malloc(1*sizeof(struct word));
    doc.data[0].data[0].word_count = 1;
    doc.data[0].data[0].data[0].data = (char*)malloc(1*sizeof(char));

    // doc.data = malloc(MAX_PARAGRAPHS*sizeof(struct paragraph*));
    // for (int i=0; i<MAX_PARAGRAPHS; i++){
    //     doc.data = (struct paragraph*)malloc(1*sizeof(struct paragraph));
    //     doc.data[i].data =(struct sentence*)malloc(1*sizeof(struct sentence));
    //     doc.data[i].sentence_count = 0;
    //     doc.data[i].data[0].data = (struct word*)malloc(1*sizeof(struct word));
    //     doc.data[i].data[0].word_count = 1;
    //     doc.data[i].data[0].data[0].data = (char*)malloc(1*sizeof(char));
    // }

    
    for (int n=0, i=0,j=0,k=0,l=0; n<strlen(text); n++) {
        if (text[n]!='\n'&&text[n]!=' '&&text[n]!='.') {
            doc.data[i].data[j].data[k].data[l]=text[n];
            l++;
            doc.data[i].data[j].data[k].data = realloc(doc.data[i].data[j].data[k].data,(l+1)*sizeof(char));
        }
        else if (text[n]==' ') {
            doc.data[i].data[j].data[k].data[l] = '\0';
            k++;
            l=0;
            doc.data[i].data[j].word_count++;
            doc.data[i].data[j].data = realloc(doc.data[i].data[j].data,(k+1)*sizeof(struct word));
            doc.data[i].data[j].data[k].data = malloc(1*sizeof(char));
        }
        else if (text[n]=='.') {
            doc.data[i].data[j].data[k].data[l] = '\0';
            j++;
            k=l=0;
            doc.data[i].sentence_count++;
            doc.data[i].data = realloc(doc.data[i].data,(j+1)*sizeof(struct sentence));
            doc.data[i].data[j].data = malloc(1*sizeof(struct word));
            doc.data[i].data[j].word_count = 1;
            doc.data[i].data[j].data[k].data = malloc(1*sizeof(char));
        }
        else if (text[n]=='\n') {
            doc.data[i].data[j].data[k].data[l] = '\0';
            doc.paragraph_count++;
            i++;
            j=k=l=0;
            doc.data = realloc(doc.data, (i+1)*sizeof(struct paragraph));
            doc.data[i].data = malloc(1*sizeof(struct sentence));
            doc.data[i].sentence_count = 0;
            doc.data[i].data[j].data = malloc(1*sizeof(struct word));
            doc.data[i].data[j].word_count = 1;
            doc.data[i].data[j].data[k].data = malloc(1*sizeof(char));
        }
    }
    return doc;

}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    struct word word = Doc.data[n-1].data[m-1].data[k-1];
    return word;
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    struct sentence set = Doc.data[m-1].data[k-1];
    return set;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    struct paragraph par = Doc.data[k-1];
    return par;
}


