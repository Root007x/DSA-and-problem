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

	int sum = 0;

	for(int i = 0;i < size;i++){
		sum = sum + arr[i];
	}
	cout << "Sum : " << sum << endl;

	float avarage = sum / size;

	cout << "Avarage : " << avarage << endl;

	return 0;
}
