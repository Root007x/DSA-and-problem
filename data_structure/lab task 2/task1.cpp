#include<iostream>

using namespace std;

bool isSorted(int *,int);
bool search(int *,int,int);
void sort(int *,int);

int main(){
	int arr[5] = {10,20,3,4,5};
	int size = 5;
	int key = 5;

	if(isSorted(arr,size)){
		if(search(arr,size,key)){
			cout << "Found" << endl;
		}
		else{
			cout << "Not Found" << endl;
		}
	}
	else{
		sort(arr,size);
		if(search(arr,size,key)){
			cout << "Found" << endl;
		}
		else{
			cout << "Not Found" << endl;
		}
	}
	return 0;
}

bool isSorted(int *arr,int size){
	for(int i = 0; i < size;i++){
		if(arr[i] > arr[i + 1]){
			return false;
		}
	}
	return true;
}

bool search(int *arr,int size,int key){
	int low = 0;
	int high = size-1;
	int mid;
	while(low <= high){
		mid = (low + high)/2;
		if(arr[mid] == key){
			return true;
		}
		else if(arr[mid] > key){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return false;
}

void sort(int *arr,int size){
	for(int i = 0;i < size - 1;i++){
		for(int j = 0;j < size - i - 1;j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}