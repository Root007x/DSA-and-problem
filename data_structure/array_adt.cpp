#include <iostream>

using namespace std;

// operation
void display();
void append(int value);
void insert(int index,int value);
void remove(int index);
int search(int value);
void reverse();

struct Array{
    int *arr; // array pointer
    int size; // array size
    int length; // array elements size
} arr;

int main(){
    //struct Array arr;
    int len;
    cout << "Enter size of Array : ";
    cin >> arr.size;
    arr.arr = new int[arr.size]; // create heap memory
    arr.length = 0;

    cout << "Enter how many elements do you want to enter : ";
    cin >> len;

    cout << "Enter elements : " << endl;
    for(int i = 0;i < len;i++){
        cin >> arr.arr[i];
    }
    arr.length = len;
    insert(2,10);
    display();
    return 0;
}

void display(){
    cout << "Output elements : " << endl;
    for(int i = 0;i < arr.length;i++){
        cout << arr.arr[i] << " ";
    }
}

void append(int value){
        if(arr.length < arr.size){
            arr.arr[arr.length] = value;
            arr.length++;
        }
        else{
            cout << "Index out of range" << endl;
        }
}

void insert(int index,int value){
    if((index >= 0) && (index <= arr.length) && (arr.length < arr.size)){
        for(int i = arr.length; i >= index;i--){
            arr.arr[i + 1] = arr.arr[i];
        }
        arr.arr[index] = value;
        arr.length++;
    }
    else{
        cout << "Index out of range" << endl;
    }

}

void remove(int index){
    if((index >= 0 ) && (index <= arr.length)){
        for(int i = index; i < arr.length-1;i++){
            arr.arr[i] = arr.arr[i + 1];
        }
        arr.length--;
    }
    else{
        cout << "index out of range" << endl;
    }
}

int search(int value){
    for(int i = 0;i < arr.length; i++){
        if(arr.arr[i] == value){
            return i;
        }
    }
    return -1;
}

void reverse(){
    for(int i = 0,j = arr.length-1;i < j;i++,j--){
        int temp = arr.arr[i];
        arr.arr[i] = arr.arr[j];
        arr.arr[j] = temp;
    }
}
