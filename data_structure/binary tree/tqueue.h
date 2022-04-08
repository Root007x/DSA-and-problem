#ifndef TQUEUE_H_INCLUDED
#define TQUEUE_H_INCLUDED
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

struct circular_queue{
	struct Node **arr;
	int size;
	int front;
	int rear;
};


void create(struct circular_queue *cq,int len){
	cq->size = len;
	cq->arr = (struct Node**)malloc(cq->size * sizeof(struct Node *));
	cq->front = cq->rear = 0;
}

void enQueue(struct circular_queue *cq,struct Node *value){
	if(((cq->rear + 1) % cq->size) == cq->front){
		cout << "Queue Overflow" << endl;
	}
	else{
		cq->rear = (cq->rear + 1) % cq->size;
		cq->arr[cq->rear] = value;
	}

}

struct Node *deQueue(struct circular_queue *cq){
	struct Node *value = NULL;

	if((cq->front==cq->rear)){
		cout << "Queue underflow" << endl;
	}
	else{
        cq->front = (cq->front + 1) % cq->size;
		value = cq->arr[cq->front];
	}
	return value;

}

int isEmpty(struct circular_queue cq){
    return cq.front == cq.rear;
}

#endif // TQUEUE_H_INCLUDED
