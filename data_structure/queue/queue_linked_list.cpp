#include<bits/stdc++.h>

using namespace std;

bool isEmpty();
bool isFull();
void enQueue(int data);
int deQueue();
void display();

struct Node{
	int data;
	Node *next;
};

Node *front = NULL;
Node *rear = NULL;

int main(){
	enQueue(10);
	enQueue(20);
	enQueue(30);
	cout << deQueue() << endl;
	display();

	return 0;
}

void enQueue(int data){
	if(isFull()){
		cout << "Queue is Full" << endl;
		return;
	}
	else{
		if((front == NULL) && (rear == NULL)){
			Node *newNode = new Node;
			newNode->data = data;
			newNode->next = NULL;
			front = rear = newNode;
		}
		else{
			Node *newNode = new Node;
			newNode->data = data;
			newNode->next = NULL;
			rear->next = newNode;
			rear = newNode;
		}
	}
}

int deQueue(){
	int value = -1;
	if(isEmpty()){
		cout << "Queue is Empty" << endl;
	}
	else{
		Node *temp = front;
		value = temp->data;
		front = temp->next;
		delete temp;
	}
	return value;
}

void display(){
	if(isEmpty()){
		cout << "Queue is Empty" << endl;
		return;
	}
	else{
		Node *temp = front;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}

bool isEmpty(){
	if(front == NULL){
		return true;
	}
	return false;
}

bool isFull(){
	Node *newNode = new Node;
	if(newNode == NULL){
		return true;
	}
	return false;
}