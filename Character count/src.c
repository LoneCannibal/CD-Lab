//Read the number of characters, numbers, special characters, etc from a file
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
char special[]="<>,.;/?'|\"[]{})(*&^%$#@!-_=+)";
char vowels[]="AEIOUaeiou";
char types[8][30]={"Upper case", "Lower case", "Numbers", "Special characters", "Spaces","Vowels", "Consonants","Total characters"};
bool isSpecialChar(char ch){
    for(int i=0;i<strlen(special);i++)
        if(special[i]==ch)
            return true;
    return false;
}
bool isVowel(char ch){
     for(int i=0;i<strlen(vowels);i++)
        if(vowels[i]==ch)
            return true;
    return false;
}
void main(){
    FILE *ptr;
    char ch;
    int count[8]={0,0,0,0,0,0,0,0};
    ptr=fopen("input.txt","r");
    if(ptr==NULL){
        printf("File not found\n");
        exit(0);
    }
    while(fscanf(ptr,"%c",&ch)!=EOF){
        if(ch>='A' && ch<='Z'){
            count[0]++;
            if(isVowel(ch))
                count[5]++;
            else
                count[6]++;
        }
        else if((ch>='a' && ch<='z')){
            count[1]++;
            if(isVowel(ch))
                count[5]++;
            else
                count[6]++;
        }
        else if(ch>=48 && ch<=57)
            count[2]++;
        else if(isSpecialChar(ch))
            count[3]++;
        else if(ch==' ')
            count[4]++;
        count[7]++;
    }
    for(int i=0;i<8;i++)
        printf("%s: %d\n",types[i],count[i]);
    fclose(ptr);
}