#include<iostream>

using namespace std;

int main(){
	int arr[7] = {1,2,3,4,5,6,8};
	int n = 7;
	int split = 3;
    int s = 3;

	for(int i = 0;i <= s;i++){

		int value = arr[split];
		for(int j = split;j < n - i - 1;j++){
			arr[j] = arr[j + 1];
		}
		arr[n - i - 1] = value;
		split--;
	}


	for(int i = 0; i < n;i++){
		cout << arr[i] << " ";
	}
	return 0;
}