#include<bits/stdc++.h>
#include "tqueue.h"

using namespace std;

struct Node *root = NULL;

void treeCreate(){
    struct Node *ptr,*temp;
    int value;
    struct circular_queue cq;
    create(&cq,100);
    cout << "Enter root value : " << endl;
    cin >> value;
    root = new Node;
    root->data = value;
    root->lchild = root->rchild = NULL;
    enQueue(&cq,root);

    while(!isEmpty(cq)){
        ptr = deQueue(&cq);
        cout << "Enter left child of" << " "<<ptr->data << ": ";
        cin >> value;
        if(value != -1){
            temp = new Node;
            temp->data = value;
            temp->lchild = temp->rchild = NULL;
            ptr->lchild = temp;
            enQueue(&cq,temp);
        }

        cout << "Enter right child of "<< " " <<ptr->data << ": ";
        cin >> value;
        if(value != -1){
            temp = new Node;
            temp->data = value;
            temp->lchild = temp->rchild = NULL;
            ptr->rchild = temp;
            enQueue(&cq,temp);
        }

    }
}

void preorder(struct Node *ptr){

    if(ptr){
        cout << ptr->data << " ";
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }

}
void inorder(struct Node *ptr){

    if(ptr){
        inorder(ptr->lchild);
        cout << ptr->data << " ";
        inorder(ptr->rchild);
    }

}
void postorder(struct Node *ptr){

    if(ptr){
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        cout << ptr->data << " ";
    }

}

int main(){
    treeCreate();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    return 0;
}
