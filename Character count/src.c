//Read the number of characters, numbers, special characters, etc from a file
#include <stdio.h>
#include <stdbool.h>
char special[]="<>,./?'|\"[]{})(*&^%$#@!-_=+)";
char types[6][30]={"Upper case", "Lower case", "Numbers", "Special characters", "Spaces","Total characters"};
bool isSpecialChar(char ch){
    for(int i=0;i<strlen(special);i++)
        if(special[i]==ch)
            return true;
    return false;
}
void main(){
    FILE *ptr;
    char ch;
    int count[6]={0,0,0,0,0,0};
    ptr=fopen("input.txt","r");
    while(fscanf(ptr,"%c",&ch)!=EOF){
        if(ch>='A' && ch<='Z')
            count[0]++;
        else if((ch>='a' && ch<='z'))
            count[1]++;
        else if(ch>=48 && ch<=57)
            count[2]++;
        else if(isSpecialChar(ch))
            count[3]++;
        else if(ch==' ')
            count[4]++;
        count[5]++;
    }
    for(int i=0;i<6;i++)
        printf("%s: %d\n",types[i],count[i]);
    fclose(ptr);
}