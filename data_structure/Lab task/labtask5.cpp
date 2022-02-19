#include<iostream>

using namespace std;

struct Array{
	int *arr;
	int size;
	int lenght;
};

Array arr;


void display();
void delete_value(int value);

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
	delete_value(10);
	display();


	return 0;
}

void delete_value(int value){
	int index = -1;
	for(int i = 0;i < arr.lenght;i++){
		if(arr.arr[i] == value){
			index = i;
		}
	}
	if(index == -1){
		cout << "Value not found" << endl;
	}
	else{
		for(int j = index; j < arr.lenght;j++){
			arr.arr[j] = arr.arr[j + 1];
		}
		arr.lenght--;
	}

}

void display(){
	cout << "All Elements : " ;
	for(int i = 0;i < arr.lenght;i++){
		cout << arr.arr[i] << " ";
	}
	cout << "\nArray Lenght : " << arr.lenght << endl;
}