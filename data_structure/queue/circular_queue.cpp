#include<bits/stdc++.h>

using namespace std;

bool isEmpty();
void enQueue(int);
void create(int);
bool isFull();
int deQueue();
void display();

struct circular_queue{
	int *arr;
	int size;
	int front;
	int rear;
};

circular_queue cq;

int main(){
	int len = 5; // queue size;
	create(len);

	// use function
	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	enQueue(5);
	deQueue();
	enQueue(10);
	display();
	return 0;
}

void create(int len){
	cq.size = len;
	cq.arr = new int[cq.size];
	cq.front = cq.rear = -1;
}

void enQueue(int value){
	if(isEmpty()){
		cq.front = 0;
		cq.rear = 0;
	}
	else if(isFull()){
		cout << "Queue Overflow" << endl;
		return;
	}
	else{
		cq.rear = (cq.rear + 1) % cq.size;
	}
	cq.arr[cq.rear] = value;
}

int deQueue(){
	int value = -1;
	if(isEmpty()){
		cout << "Queue underflow" << endl;
		return -1;
	}
	else{
		value = cq.arr[cq.front];
		cq.front = (cq.front + 1) % cq.size;
	}
	return value;

}

bool isEmpty(){
	if((cq.front == -1) &&(cq.rear == -1)){
		return true;
	}
	return false;
}

bool isFull(){
	if(((cq.rear + 1) % cq.size) == cq.front){
		return true;
	}
	return false;
}

void display(){
	int i;
	if(isEmpty()){
		cout << "Queue underflow" << endl;
		return;
	}
	for(i = cq.front;i != cq.rear;i = (i + 1) % cq.size){
		cout << cq.arr[i] << " ";
	}
	cout << cq.arr[i] << endl;
}