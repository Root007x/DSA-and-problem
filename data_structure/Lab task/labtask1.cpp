#include<iostream>

using namespace std;

int main(){
	int size;
	cout << "Enter Array size : ";
	cin >> size;
	int *arr = new int[size];

	cout << "Enter array Element" << endl;
	for(int j = 0;j < size;j++){
		cin >> arr[j];
	}

	cout << "Negative Value : " << endl;
	for(int i = 0;i < size;i++){

		if(arr[i] < 0){
			cout << arr[i] << endl;
		}
	}


	return 0;
}