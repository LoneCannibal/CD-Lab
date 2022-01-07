//Write a program to implement three address codes and print them
#include<stdio.h>
#include<string.h>
char input[100], stack[100];
int top=-1;
void push(char ch){
    top++;
    stack[top] = ch;
}
char pop(){
    return stack[top--];
}
int precedence(char ch){
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='/'|| ch=='*')
        return 2;
    else
        return 3;
}
void postfix(){
    char postfix[100];
    int len=0;
    for(int i=0;i<strlen(input);i++){
        if(isalpha(input[i]))//If the input char is an operand, add it to the postfix string
            postfix[len++]=input[i];
        else{
            if(top==-1 || strcmp(stack,")")==0 || strcmp(stack,"(")==0)//If stack is empty or contains brackets
                push(input[i]);
            else{
                
            }
        }
    }
}
int main(){
    printf("Enter the  input string: ");//Eg. z=a+b*c
    scanf("%s",input);
    postfix();
    evaluate();
    return 0;
}
 