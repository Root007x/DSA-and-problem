#include<iostream>
#include<cstring>
#include "stack.cpp"

using namespace std;

bool isOperand(char ch);
int presedent(char ch);

int main(){
	char *equ = "a+b*c/d";
	create(strlen(equ));
	string postfix = "";
	int in = 0;

	while(equ[in] != '\0'){
		if(isOperand(equ[in])){
			postfix = postfix + equ[in];
			in++;
		}
		else{
			if(presedent(equ[in]) > presedent(peek())){
				push(equ[in]);
				in++;
			}
			else{
				postfix = postfix + pop();
			}
		}
	}

	while(!isEmpty()){
		postfix = postfix + pop();
	}

	cout << postfix << endl;

	return 0;
}

bool isOperand(char ch){
	if((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')){
		return false;
	}
	return true;
}

int presedent(char ch){
	if((ch == '+') || (ch == '-')){ // low priority 
		return 1;
	}
	else if((ch == '*') || (ch == '/')){ // high priority
		return 2;
	}
	else{
		return 0;
	}
}