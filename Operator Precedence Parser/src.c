//Implement Operator precedence parsing
#include<stdio.h>
#include<string.h>
char precedence_table [][4] = {" >>>","<><>","<>>>","<<< "};
char symbols[4] = "i+*$" ;
char input[100];

int main(){
    printf("Enter the string: ");
    scanf("%s", input);
    input[strlen(input)]='$'; //Add $ symbol at the end of input string
    return 0;
}