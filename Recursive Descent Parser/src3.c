//Implement recursive descent parser for the following grammar
// S->ABC  A-> aAb|C  B-> cB|d C->eC
#include <stdio.h>
#include <string.h>
int pointer = 0;
char input[30];
void A (), B(), C();
void S(){
    A();
    B();
    C();
}
void A(){
    if(input[pointer] == 'a'){
        pointer++;
        A();
        if(input[pointer] == 'b')
            pointer++;
    }
    else
        C();
}
void B(){
    if(input[pointer] == 'c'){
        pointer++;
        B();
    }
    else if(input[pointer] == 'd')
        pointer++;
}
void C(){
    if(input[pointer] == 'e'){
        pointer++;
        C();
    }
}
int main(){
    printf("Enter the string: ");
    scanf("%s",input);
    input[strlen(input)] = '$';
    S();
    if(input[pointer] == '$')
        printf("Accepted \n");
    else
        printf("Rejected \n");
    return 0;
}