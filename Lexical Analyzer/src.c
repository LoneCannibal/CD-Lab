//C program to implement Lexical Analysis by reading from a program file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
char OPERATOR[11][5]={"<",">","/","*","%","+","-","^","==","&&","||"};
char KEYWORD[7][10]={"void","int","char","string","if","return","bool"};
char op[20][20] , keyword[20][20] , identifier[20][20] , function[20][20] ;
int opCount=0,keywordCount=0,identifierCount=0,functionCount=0;
void display(char* msg,char* a,int count){
    printf("%s: ",msg);
    for(int i=0;i<count;i++)
        printf("%s ",a);
    printf("\n");
}
bool isOperator(char *buff){
    for(int i=0;i<11;i++)
        if(strcmp(buff,OPERATOR[i])==0)
            return true;
        return false;
}
bool isKeyword(char *buff){
    for(int i=0;i<7;i++)
        if(strcmp(buff,KEYWORD[i])==0)
            return true;
        return false;
}
bool isFunction(char *buff){
    if(buff[strlen(buff)-1]==')' && buff[strlen(buff)-2]=='(')
        return true;
    return false;
}
void main(){
    FILE *ptr;
    ptr=fopen("input.txt","r");
    if(ptr==NULL){
        printf("File not found\n");
        exit(1);
    }
    char buffer[30];
    while (fscanf(ptr,"%s",buffer)!=EOF){
        if(isOperator(buffer))
            strcpy(op[opCount++],buffer);
        else if(isKeyword(buffer))
            strcpy(keyword[keywordCount++],buffer);
        else if(isFunction(buffer))
            strcpy(function[functionCount++],buffer);
        else
            strcpy(identifier[identifierCount++],buffer);
    }
    display("Operators",op,opCount);
    display("Keywords",keyword,keywordCount);
    display("Functions",function,functionCount);
    fclose(ptr);
}