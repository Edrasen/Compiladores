//A -> a | b | ( A )

#include <stdio.h>
#include<stdlib.h>

void A();

typedef int Token;
int preana;
int count = -1;

void error(){
	puts("error!!");
	exit(0);
}

int sigToken(){
	return getchar();
}


void parea(Token t){
	if(preana == t){
		preana = sigToken();
		if((preana == 160 | preana == 161)  && count<1)
			A();
		else{
			error();
		}
	}
	else error();
}
void A(){
	if(preana== '('){
		parea('(');	 
		A(); 
	       	parea(')');
	}
	else if(preana == 'a'){
		count++;
		parea('a');
	}else if(preana == 'b'){
		count++;
		parea('b');
	}
	else
		error();
}


void main(){
	preana = sigToken();
	A();
}
