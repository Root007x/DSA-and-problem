#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    char lower[200] = {'0'};
    memset(lower,'0',200*sizeof(char));
    lower[0] = 'c';
    for(int i = 0;lower[i] != '0';i++){
        cout << "hello" << endl;
    }
    return 0;
}
