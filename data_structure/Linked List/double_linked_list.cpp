#include<bits/stdc++.h>

void display();
void insertAtEnd(int data);
void insertAtBegin(int data);
bool isEmpty();
int count_node();
void insertAfter(int index,int data);
bool search(int value);
void delete_node(int index);
void update(int index,int value);

using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};

Node *head = NULL;

int main(){
	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	update(1,50);
	display();
	return 0;
}

void insertAtEnd(int data){
	if(isEmpty()){
		head = new Node;
		head->data = data;
		head->next = NULL;
		head->prev = NULL;
	}
	else{
		Node *newNode = new Node;
		Node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		newNode->data = data;
		newNode->prev = temp;
		newNode->next = NULL;
		temp->next = newNode;
	}
}

void insertAtBegin(int data){
	if(isEmpty()){
		head = new Node;
		head->data = data;
		head->prev = NULL;
		head->next = NULL;
	}
	else{
		Node *newNode = new Node;
		head->prev = newNode;
		newNode->data = data;
		newNode->next = head;
		newNode->prev = NULL;
		head = newNode;
	}
}

void insertAfter(int index,int data){
	if((index >= 0) && (index <= count_node())){
		if(index == 0){
			insertAtBegin(data);
		}
		else{
			Node *newNode = new Node;
			Node *temp = head;
			newNode->data = data;

			for(int i = 0;i < index - 1;i++){
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next->prev = newNode;
			newNode->prev = temp;
			temp->next = newNode;
		}
	}
	else{
		cout << "Index out of range" << endl;
	}

}

void delete_node(int index){
	if((index >= 0) && (index <= count_node())){
		if(index == 0){
			Node *temp = head;
			temp->next->prev = NULL;
			head = temp->next;
			delete temp;
		}
		else{
			Node *temp = head;
			for(int i = 0;i < index;i++){
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
	else{
		cout << "Index out of range" << endl;
	}
}

void update(int index,int value){
	if(isEmpty()){
		cout << "Linked List empty" << endl;
		return;
	}
	if((index >= 0) && (index < count_node())){
		Node *temp = head;

		for(int i = 0;i < index;i++){
			temp = temp->next;
		}
		temp->data = value;
	}
	else{
		cout << "index out of range" << endl;
	}
}

bool search(int value){
	if(isEmpty()){
		cout << "Linked List empty" << endl;
		return false;
	}
	else{
		Node *temp = head;
		while(temp != NULL){
			if(temp->data == value){
				return true;
			}
			temp = temp->next;
		}
	}
	return false;
}

void display(){
	if(head == NULL){
		cout << "List Empty" << endl;
		return;
	}
	else{
		Node *temp = head;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}

int count_node(){
	int count = 0;
	if(isEmpty()){
		return count;
	}
	else{
		Node *temp = head;
		while(temp != NULL){
			count++;
			temp = temp->next;
		}
	}
	return count;
}

bool isEmpty(){
	if(head == NULL)
		return true;
	return false;
}