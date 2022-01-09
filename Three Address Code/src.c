//Write a program to implement three address codes and print them
#include<stdio.h>
#include<string.h>
char input[100], stack[100],return_value[10];
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
                if(input[i]==')'){
                    while(stack[top]!='(')
                        postfix[len++]=pop();
                    char ch=pop();
                }
                if(precedence(input[i])>precedence(stack[top]))
                    push(input[i]);
                else{
                    while(top!=-1)
                        postfix[len++]=pop();
                    push(input[i]);
                }
            }
        }
        //printf("Stack:%s\n",stack);
    }
    while(top!=-1)
        postfix[len++]=pop();
    strcpy(input,postfix);
}
char* code(char ch){//Returns values like t0,t1,t2 etc. according to ch value A,B,C, etc.
    printf("DEBUG%c",ch);
    return_value[0] = '\0';//Resetting string to empty
    if(ch>=65 && ch<=90){
        return_value[0] = 't';
        return_value[1] = ch-65;}
    else
        return_value[0] = ch;
    return  return_value;
}
void evaluate(){
    int codeNumber = 0;
    for(int i=0;i<strlen(input);i++){
        if(!isalpha(input[i])){
            printf("t%d=%c%c%c\n",codeNumber++,input[i-2],input[i],input[i-1]);
        }
    }
}
int main(){
    printf("Enter the  input string: ");//Eg. z=a+b*c
    scanf("%s",input);
    postfix();
    printf("%s\n",input);
    evaluate();
    return 0;
}
 