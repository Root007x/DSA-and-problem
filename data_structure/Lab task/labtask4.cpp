#include<iostream>

using namespace std;

struct Array{
	int *arr;
	int size;
	int lenght;
};

Array arr;


void display();
void insert(int value,int index);

int main(){
	int len;
	cout << "Enter size of the array : ";
	cin >> arr.size;
	arr.arr = new int[arr.size];
	arr.lenght = 0;


	cout << "Enter how many element do you want to enter : ";
	cin  >> len;


	cout << "Enter elements : ";
	for(int i = 0;i < len;i++){
		cin >> arr.arr[i]; // arr.*(arr + i)
	}
	arr.lenght = len;
	display();
	insert(2,10);
	display();


	return 0;
}

void insert(int index,int value){
	if((index >= 0 ) && (index <= arr.lenght) && (arr.lenght < arr.size)){
		for(int i = arr.lenght-1;i >=index;i--){
			arr.arr[i + 1] = arr.arr[i];
		}
		arr.arr[index] = value;
		arr.lenght++;
	}
	else{
		cout << "Index out of range" << endl;
	}
}

void display(){
	cout << "All Elements : " ;
	for(int i = 0;i < arr.lenght;i++){
		cout << arr.arr[i] << " ";
	}
	cout << "\nArray Lenght : " << arr.lenght << endl;
}