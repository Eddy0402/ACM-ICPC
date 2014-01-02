#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char dictionary[60000][205];
int main(void){
    int i, wordCount = 0,letter = 0,p;
    while((p = getchar()) != EOF){
        p = tolower(p);
        if(p > 'z' || p < 'a'){
            if(letter == 0)continue;
            dictionary[wordCount][letter] = '\0';
            wordCount++;
            letter = 0;
        }else dictionary[wordCount][letter++] = p;
    }
    qsort(dictionary, wordCount, sizeof(char) * 205,(int(*)(const void *,const void *))strcmp);
    for(i = 0;i < wordCount; i++)
	if(strcmp(&dictionary[i][0], &dictionary[i-1][0]) )
	    puts(&dictionary[i][0]);
    return 0;
}
