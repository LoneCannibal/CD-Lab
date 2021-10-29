//Implement recursive descent parser for the following grammar
//E->TE'  E'->+TE' T->FT' T'-> *FT' F->(E)|i
#include <stdio.h>
#include <string.h>
int pointer=0,error=0;
char input[30];
void Eprime();
void T();
void Tprime();
void F();
void E(){
    T();
    Eprime();
}
void Eprime(){
    if(input[pointer]=='+'){
        pointer++;
        T();
        Eprime();
    }
}
void T(){
    F();
    Tprime();
}
void Tprime(){
    if(input[pointer]=='*'){
        pointer++;
        F();
        Tprime();
    }
}
void F(){
    if(input[pointer]=='('){
        error++;
        pointer++;
        E();
        if(input[pointer]==')'){
            error--;
            pointer++;
        }
    }
    else if(input[pointer]=='i')
        pointer++;
    else
        error++;
}
int main(){
    printf("Enter the input string ");
    scanf("%s",input);
    input[strlen(input)]='$'; //Changing the last character to $ sign
    E();
    if(input[pointer]=='$' && error==0)
        printf("Accept\n");
    else
        printf("Reject\n");
    return 0;
}