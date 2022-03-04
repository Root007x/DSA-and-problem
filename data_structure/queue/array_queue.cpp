#include<iostream>

using namespace std;

void enqueue(int value);
void display();
int dequeue();


struct queue{
	int *arr;
	int size;
	int front;
	int rear;
};

queue qt;

int main(){
	cout << "Enter size of queue : ";
	cin >> qt.size;
	qt.arr = new int[qt.size]; // memory allocation
	qt.front = qt.rear = -1;

	// use fucntion here
}


void enqueue(int value){
	if(qt.rear == qt.size - 1){
		cout << "Queue Full" << endl;
	}	
	else{
		qt.rear++;
		qt.arr[qt.rear] = value;
	}
}

void display(){
	if((qt.rear == -1) && (qt.front == -1)){
		cout << "Queue Empty" << endl;
	}
	else{
		for(int i = qt.front + 1;i <= qt.rear;i++){
			cout << qt.arr[i] << " ";
		}
	}
}

int dequeue(){
	int value = -1;
	if(qt.rear == -1){
		cout << "Queue Empty" << endl;
	}
	else{
		qt.front++;
		value = qt.arr[qt.front];
	}

	return value;
}

bool isEmpty(){
	if((qt.front == -1) && (qt.rear == -1)){
		return true;
	}
	return false;
}

bool isFull(){
	if(qt.rear == (qt.size - 1)){
		return true;
	}
	return false;
}