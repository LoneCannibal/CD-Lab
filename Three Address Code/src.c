//Write a program to implement three address codes and print them
#include<stdio.h>
#include<string.h>
char input[100], stack[100];
int top=-1;
void push(char ch){
    top++;
    stack[top] = ch;
}
int main(){
    printf("Enter the  input string: ");//Eg. z=a+b*c
    scanf("%s",input);
    postfix();
    evaluate();
    return 0;
}
 