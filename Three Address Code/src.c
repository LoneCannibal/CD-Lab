//Write a program to implement three address codes and print them
#include<stdio.h>
#include<string.h>
char input[100];
int main(){
    printf("Enter the  input string: ");//Eg. z=a+b*c
    scanf("%s",input);
    for(int i=0;i<strlen(input);i++)
        if(!isalpha(input[i]))//If the character is a symbol like /*+- send it's index location to the next function.
            operator_priority(i);
    return 0;
}