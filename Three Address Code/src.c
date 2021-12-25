//Write a program to implement three address codes and print them
#include<stdio.h>
#include<string.h>
char input[100];
int codes[50][3], codeCount=0;

int main(){
    printf("Enter the  input string: ");//Eg. z=a+b*c
    scanf("%s",input);
    for(int i = 0; i < strlen(input); i++)
        if(!isalpha(input[i])){//If the character is a symbol like /*+- 
            sprintf(codes[codeCount],"%c%c%c",input[i-1],input[i],input[i+1]);
            codeCount++;
        }
    for(int i = 0; i <codeCount; i++)
        printf("%s\n",codes[i]);
    return 0;
}