#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct word{
    char old[22];
    char sort[22];
    bool isAnanagram;
}word;

word dictionary[1005];
int wordCount = 0;

int compare_old(const void *a,const void *b){
    if( ((word *)a) -> isAnanagram != ((word *)b) -> isAnanagram )return  ((word *)b) -> isAnanagram - ((word *)a) -> isAnanagram ;
    else return strcmp(((word *)a) -> old,((word *)b) -> old);
}
int compare_sort(const void *a,const void *b){
    return strcmp(((word *)a) -> sort,((word *)b) -> sort);
}
int compare_character(const void *a,const void *b){
    return *(char*)a - *(char*)b;
}

int main(void){
    int len,i;
    char temp;
    bool flag = false;
    while(scanf("%s",(dictionary + wordCount) -> old)!=EOF)
	if(*((dictionary + wordCount) -> old)!='#'){
	    for(len = 0; (temp = tolower((dictionary + wordCount) -> old[len])) != '\0' ;len++)
		(dictionary + wordCount) -> sort[len] = temp;
	    qsort((dictionary + wordCount) -> sort,len,sizeof(char),compare_character);
            (dictionary + wordCount) -> isAnanagram = true;
	    wordCount++;
	}else break;
    qsort(dictionary,wordCount,sizeof(word),compare_sort);
    for(i = 0;i < wordCount; i++){
	if(strcmp( (dictionary + i) -> sort , (dictionary + i + 1) -> sort) == 0){
            (dictionary + i) -> isAnanagram = false;
            (dictionary + i + 1) -> isAnanagram = false;
        }
    }
    qsort(dictionary,wordCount,sizeof(word),compare_old);
    for(i = 0;(dictionary + i) -> isAnanagram; i++)
	printf("%s\n",(dictionary + i) -> old);
    return 0;
}
