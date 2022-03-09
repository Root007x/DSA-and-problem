#include<bits/stdc++.h>

using namespace std;

void push(int);
void display();
bool isEmpty();
bool isEmpty();
int pop();
int peek();

struct Node{
	int data;
	Node *next;
};

Node *top = NULL;

int main(){

	push(10);
	push(20);
	push(40);
	cout << pop() << endl;
	display();
	return 0;
}

bool isEmpty(){
	if(top == NULL){
		return true;
	}
	return false;
}

bool isFull(){
	Node *full = new Node;
	if(full == NULL){
		return true;
	}
	return false;
}

void push(int data){
	if(isFull()){
		cout << "Stack Overflow" << endl;
		return;
	}
	else{
		Node *temp = new Node;
		temp->data = data;
		temp->next = top;
		top = temp;
	}
}

int pop(){
	int value = -1;
	if(isEmpty()){
		cout << "Stack Underflow" << endl;
		return value;
	}
	else{
		Node *temp = top;
		value = temp->data;
		top = temp->next;
		delete temp;
	}
	return value;
}

int peek(){
	int value = -1;
	if(isEmpty()){
		cout << "Stack Underflow" << endl;
		return value;
	}
	else{
		value = top->data;
	}
	return value;
}

void display(){
	if(isEmpty()){
		cout << "Stack Empty" << endl;
		return;
	}
	else{
		Node *temp = top;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}