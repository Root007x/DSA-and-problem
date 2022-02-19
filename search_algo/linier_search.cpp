#include<iostream>

using namespace std;

int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int key = 5;
	
	bool flag = false;

	for(int i = 0;i < 10;i++){
		if(arr[i] == key){
			flag = true;
			break;
		}
	}

	if(flag == true){
		cout << "Found" << endl;
	}
	else{
		cout << "Not Found" << endl;
	}
	return 0;
}