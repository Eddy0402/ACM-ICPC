#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct word{
    char word[16];
}word;
word dictionary[10002];
word dictionarySort[10002];
int compareExact(const void *a,const void *b){
    return strcmp(((word *)a) -> word,((word *)b)->word);
}
int canReplace(const char *toCheck,const char *dictionaryWord){
    int t = (int)strlen(toCheck) - (int)strlen(dictionaryWord);
    while(*toCheck && *dictionaryWord && *toCheck == *dictionaryWord) ++toCheck,++dictionaryWord;
    if(t > 1 || t < -1)return 0;
    if(t == 0)++toCheck,++dictionaryWord;
    if(t ==-1)dictionaryWord++;
    if(t == 1)toCheck++;
        while(*toCheck && *dictionaryWord && *toCheck == *dictionaryWord) ++toCheck,++dictionaryWord;
    return !(*toCheck - *dictionaryWord);
}
int main(void){
    int dictionarySize = 0,i;
    char wordToSearch[16];
    while(1){
        scanf("%s",dictionary + dictionarySize);
        *(dictionarySort + dictionarySize) = *(dictionary + dictionarySize);
        if((dictionary + dictionarySize) -> word[0] == '#')break;
        dictionarySize++;
    }
    qsort(dictionarySort,dictionarySize,sizeof(word),compareExact);
    while(1){
	scanf("%s",wordToSearch);
        if(*wordToSearch == '#')break;
        if(bsearch((void *)wordToSearch,dictionarySort,dictionarySize,sizeof(word),compareExact) != NULL)
            printf("%s is correct\n",wordToSearch);
        else{
            printf("%s:",wordToSearch);
            for(i = 0;i < dictionarySize;i++)
                if(canReplace(wordToSearch, (dictionary + i) -> word))
                    printf(" %s",(dictionary + i) -> word);
            putchar('\n');
        }
    }
    return 0;
}
