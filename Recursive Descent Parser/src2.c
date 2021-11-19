// Write a program to implement recursive descent parser for the following grammar
// S->(L)|a  L->SL' L'->,SL'
#include <stdio.h>
#include <string.h>
int error = 0, pointer = 0;
char input[30];
void Lprime(), L();
void S(){
	if(input[pointer] == '('){
		pointer++;
		error++;
		L();
		if(input[pointer] == ')'){
			error--;
			pointer++;
		}
	}
	else if(input[pointer] == 'a')
		pointer++;
}
void L(){
	S();
	Lprime();
}
void Lprime(){
	if(input[pointer] == ','){
		pointer++;
		S();
		Lprime();
	}
}
int main(){
	printf("Enter the input: ");
	scanf("%s",input);
	input[strlen(input)] = '$';
	S();
	if(input[pointer] == '$' && error == 0)
		printf("Accepted \n");
	else
		printf("Rejected \n");
	return 0;	
}