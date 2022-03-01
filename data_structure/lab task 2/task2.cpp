#include<iostream>

using namespace std;


void push(int value);
int peek();
int peek_index(int index);
int pop();
void display();
void isEmpty();

struct stack{
	int *arr;
	int top;
	int size;
};

stack st;

int main(){
	cout << "Enter size of stack : ";
	cin >> st.size;
	st.arr = new int[st.size]; // memory allocation
	st.top = -1;

	// use fucntion here

	return 0;
}

void push(int value){

	if((st.size - 1) == st.top){ // checking stack full or not
		cout << "Stack Overflow" << endl;
	}
	else{
		st.top++;
		st.arr[st.top] = value;
	}
}

int peek(){
	int value = -1;
	if(st.top == -1){ // checking stack enpty or not
		cout << "Stack underflow" << endl;
	}
	else{
		value = st.arr[st.top];
	}
	return value;
}

int pop(){
	int value = -1;
	if(st.top == -1){ // checking stack empty or not
		cout << "Stack underflow" << endl;
	}
	else{
		value = st.arr[st.top];
		st.top--;
	}
	return value;
}

void display(){
	if(st.top == -1){
		cout << "Stack underflow" << endl;
	}
	else{
		cout << "Stack Elements : ";
		for(int i = 0;i <= st.top;i++){
			cout << st.arr[i] << " ";
		}
	}
}

void isEmpty(){
	if(st.top == -1){
		cout << "Stack Empty" << endl;
	}
	else{
		cout << "Stack not Empty" << endl;
	}
}

int peek_index(int index){
	int value = -1;
	if(st.top == -1){
		cout << "Stack underflow" << endl;
	}
	else{
		if((index >= 0) && (index <= st.top)){
			for(int i = 0;i <= index;i++){
				value = st.arr[index];
			}
		}
	}
	return value;
}