//A -> a | b | ( A )

#include <stdio.h>
#include<stdlib.h>


typedef int Token;
int preana;

void error(){
	puts("error!!");
	exit(0);
}

int sigToken(){
	return getchar();
}


void parea(Token t){
	if(preana == t)
		preana = sigToken();
	else error();
}
void A(){
	if(preana == 'a'){
		parea('a');
	}else if(preana == 'b'){
		 parea('b');
	}else if(preana== '('){
		parea('(');	 A();  parea(')');
	}else error();
}

void main(){
	preana = sigToken();
	A();
}
