//C program to implement Lexical Analysis by reading from a program file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char OPERATOR[10][5]={"<",">","/","*","%","+","-","^","==","&&","||"};
char KEYWORD[20][10]={"void","int","char","string","if"};
char op[20][20] , keyword[20][20] , identifier[20][20] , function[20][20] ;
int opCount=0,keywordCount=0,identifierCount=0,functionCount=0;
void main(){
    FILE *ptr;
    ptr=fopen("input.txt","r");
    if(ptr==NULL){
        printf("File not found\n");
        exit(1);
    }
    char buffer[30];
    while (fscanf(ptr,"%s",buffer)!=EOF){
        printf("%s\n",buffer);
        if(isOperator(buffer))
            strcpy(op[opCount++],buffer);
        else if(isKeyword(buffer))
            strcpy(keyword[keywordCount++],buffer);
        else if(isFunction(buffer))
            strcpy(function[functionCount++],buffer);
        else
            strcpy(function[functionCount++],buffer);
    }
    fclose(ptr);
}