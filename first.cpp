#include<bits/stdc++.h>

using namespace std;

int main(){
    map<char, vector<string>> grammer = { // grammer[key] will return vector
        {'S',{"aS","Ab"}}, // S-> aS | Ab
        {'A',{"XYZ","%"}}, // A-> XYZ | %  Note % consider epsilon
        {'X',{"cS","%"}},  // X-> cS | %
        {'Y',{"dS","%"}},  // Y-> dS | %
        {'Z',{"eS","%"}}   // Z-> eS | %
    };
    map<char,vector<char>> result;
    vector<char> v = {'S','A','X','Y','Z'};

    for(int i = v.size()-1;i >= 0;i--){

        //cout << v[i] << " : ";
        for(string s : grammer[v[i]]){
            if(s[0] >= 'a' && s[0] <= 'z' || s[0] == '%'){
                //cout << s[0] << " ";
                result[v[i]].push_back(s[0]);
                continue;
            }
            else{
                bool flag = false;
                for(int pointer = 0;pointer < s.length();pointer++){
                    flag = false;
                    for(char ch : result[s[pointer]]){
                        if(ch == '%'){
                            flag = true;
                            break;
                        }
                        result[v[i]].push_back(ch);
                        //cout << ch << " ";
                    }
                    if(!flag) break;
                }
                if(flag){
                    result[v[i]].push_back('%');
                    // cout << '%' << " ";
                }
                for(char rest : s){
                    if(rest >= 'a' && rest <= 'z'){
                        result[v[i]].push_back(rest);
                        //cout << rest << " ";
                    }
                }
                if(s[0] >= 'A' && s[0] <= 'Z'){ // optional
                    result[v[i]].push_back('%');
                }
            }
        }
        //cout << endl;
    }
    // cout << endl;
    // cout << endl;

    for (auto& entry : result) {
        entry.second.erase(unique(entry.second.begin(), entry.second.end()), entry.second.end());
    }

    for(int i = 0;i < v.size();i++){
        cout << v[i] << " : ";
        for(auto it : result[v[i]]){
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}