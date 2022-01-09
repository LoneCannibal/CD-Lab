//Write a program to implement three address codes and print them
#include<stdio.h>
#include<string.h>
char input[100], stack[100],return_value[100];
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
void replace(int a, int b){
    char temp[100];
    int len = 0,i = 0;
    for(i=0;i<a;i++)
        temp[len++] = input[i];
    temp[len++] = (int)b+65;//Converting codeNumber to respective alphabet A,B,C, etc.
    i = a+3;
    while(input[i]!='\0'){
        temp[len++] = input[i];
        i++;
    }
    strcpy(input,temp);
}
void evaluate(){
    int codeNumber = 0;
    for(int i=0;i<strlen(input);i++){
        if(!isalpha(input[i])){
            printf("t%d=",codeNumber++);
            if(input[i-2]>=65 && input[i-2]<=90)
                printf("t%d%c",input[i-2]-65,input[i]);
            else
                printf("%c%c",input[i-2],input[i]);
            if(input[i-1]>=65 && input[i-1]<=90)
                printf("t%d\n",input[i-1]-65);
            else
                printf("%c\n",input[i-1]);
            replace(i-2,codeNumber-1);
            if(i-2!=0)
                i=0;
        }
    }
}
int main(){
    printf("Enter the  input string: ");//Eg. a+b*c
    scanf("%s",input);
    postfix();
    printf("POSTFIX VALUE:%s\n",input);
    evaluate();
    return 0;
}
 