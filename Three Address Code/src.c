//Write a program to implement three address codes and print them
#include<stdio.h>
#include<string.h>
char input[100];
int codes[50][3], codeCount = 0, codeNumber=0;
char* left(int i){//    Get the Left value in the three address code
    char return_value[10];
    if(i==0)
        return_value[0] = codes[i][0];
    if(codes[i-1][0] >= 65 && codes[i-1][0] <= 97)
        sprintf(return_value,"t%c",codes[i-1][0]-65);
    else
        return_value[0] = codes[i][0];
    return return_value;
}
char* right(int i){
    char return_value[10];
    if(i==codeCount-1)
        return_value[0] = codes[i][0];
    if(codes[i+1][0] >= 65 && codes[i+1][0] <= 97)
        sprintf(return_value,"t%c",codes[i+1][0]-65);
    else
        return_value[0] = codes[i][0];
    return return_value;
}
void generate_code(char symbol){
    for(int i = 0; i < codeCount; i++)
        if(codes[i][1]==symbol)//Checking if  the codes contain the symbol /*+or-
            printf("t%d=%s%c%s",codeNumber+1,left(i),symbol,right(i));
}
int main(){
    printf("Enter the  input string: ");//Eg. z=a+b*c
    scanf("%s",input);
    for(int i = 0; i < strlen(input); i++){
        if(!isalpha(input[i])){//If the character is a symbol like /*+- 
            codes[i][0] = input[i-1];
            codes[i][1] = input[i];
            codes[i][2] = input[i+1];
            //sprintf(codes[codeCount],"%c%c%c\0",input[i-1],input[i],input[i+1]);
            codeCount++;
        }
    }
    for(int i = 0; i <codeCount; i++)
        printf("%s\n",codes[i][1]);
    generate_code('/');
    generate_code('*');
    generate_code('+');
    generate_code('-');
    return 0;
}