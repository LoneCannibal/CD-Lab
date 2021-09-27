//Read the number of characters, numbers, special characters, etc from a file
#include<stdio.h>
void main(){
    FILE *ptr;
    char ch;
    int upper=0, lower=0, numbers=0, special_char=0;
    ptr=fopen("input.txt","r");
    while(fscanf(ptr,"%c",&ch)!=EOF){
        if(ch>='A' && ch<='Z')
            upper++;
        else if((ch>='a' && ch<='z'))
            lower++;
        else if(ch>='0' && ch<='9')
            numbers++;
    }
    printf("%d\n",upper);
    fclose(ptr);
}