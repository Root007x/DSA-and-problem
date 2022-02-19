#include<iostream>

using namespace std;

int main(){
	int len;
	cout << "Enter size of array : " << endl;
	cin >> len;
	int *arr = new int[len];

	cout << "Enter elements : ";
	for(int i = 0;i < len;i++){
		cin >> arr[i];
	}

	for(int i = 0;i < len - 1;i++){
		
		for(int j = 0;j < len - i- 1;j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << "First Largest elements : " << " " << arr[len - 1]<< endl;
	cout << "Second Largest elements : " << " " << arr[len - 2]<< endl;
	return 0;
}


