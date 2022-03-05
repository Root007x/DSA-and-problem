#include<bits/stdc++.h>

using namespace std;

void insertAtEnd(int);
void insertAtBegin(int);
void display();
int count_node();
void insertAfter(int,int);
void delete_node(int);
bool search(int);
void update(int,int);

struct Node{
	int data;
	Node *next;
};

Node *head = NULL;
Node *tail = NULL;

int main(){
	// use function

	return 0;
}

bool isEmpty(){
	if(head == NULL)
		return true;
	return false;
}


void insertAtEnd(int data){
	if(isEmpty()){
		head = new Node;
		head->data = data;
		head->next = NULL;
	}
	else{
		Node *temp = head;
		Node *newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void insertAtBegin(int data){
	if(isEmpty()){
		head = new Node;
		head->data = data;
		head->next = NULL;
	}
	else{
		Node *newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}
}

void insertAfter(int index,int data){
	if((index >= 0) && (index <= count_node())){
		if(index == 0){
			insertAtBegin(data);
		}
		else{
			Node *temp = head;
			Node *newNode = new Node;
			newNode->data = data;

			for(int i = 0;i < index - 1;i++){
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	else{
		cout << "Index out of range" << endl;
	}
}

void delete_node(int index){
	if(isEmpty()){
		cout << "Linked List is Empty" << endl;
		return;
	}
	if((index >= 0) && (index < count_node())){
		if(index == 0){
			Node *temp = head;
			head = head->next;
			delete temp;
		}
		else{
			Node *temp = head;
			Node *prev;
			for(int i = 0;i < index;i++){
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			delete temp;
		}
	}
	else{
		cout << "Index Out of range" << endl;
	}	

}

bool search(int value){
	if(isEmpty()){
		cout << "Linked List Empty" << endl;
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

void display(){
	if(isEmpty()){
		cout << "Linked List Empty" << endl;
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
			temp = temp->next;
			count++;
		}
	}
	return count;
}