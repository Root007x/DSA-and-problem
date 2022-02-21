#include<iostream>
#include<cstring>


using namespace std;

void create(int len);
void push(char ch);
char pop();
bool isEmpty();
void display();
bool isBalance(char *exp, int len);

struct stack{
	char *arr;
	int size;
	int top;
};

stack st;


int main(){
	string x = "((b + c)) + (c + d)";
	int len = x.length() + 1;
	char char_array[len];
	strcpy(char_array,x.c_str());

	if(isBalance(char_array,len)){
		cout << "Balance Exp" << endl;
	}
	else{
		cout << "Not Balance Exp" << endl;
	}

	return 0;
}

void create(int len){
	st.size = len;
	st.arr = new char[st.size];
	st.top = -1;
}

void push(char ch){
	if((st.size - 1) == st.top){
		cout << "stack overflow" << endl;
	}
	else{
		st.top++;
		st.arr[st.top] = ch;
	}
}

char pop(){
	char ch = '\0';
	if(st.top == -1){
		cout << "Stack underflow" << endl;
	}
	else{
		ch = st.arr[st.top];
		st.top--;
	}
	return ch;
}


bool isEmpty(){
	if(st.top == -1){
		return true;
	}
	return false;
}

void display(){
	if(st.top == -1){
		cout << "stack underflow" << endl;
	}
	else{
		for(int i = 0;i <= st.top;i++){
			cout << st.arr[i] << " ";
		}
	}
}

bool isBalance(char *exp,int len){

	create(len);

	for(int i = 0;exp[i] != '\0';i++){
		if(exp[i] == '('){
			push(exp[i]);
		}
		else if(exp[i] == ')'){
			if(isEmpty()){
				return false;
			}
			else{
				pop();
			}
		}

	}
	if(isEmpty()){
		return true;
	}
	return false;
}