#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n = 5;
    int sum = 0;

    for(int i = 1;i <=n ;i++){
        for(int j = 1;j <= i;j++){
            sum = i + j;
            if(sum % 2 == 0){
                cout << "1 ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}