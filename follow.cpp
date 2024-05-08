#include<bits/stdc++.h>

using namespace std;

bool isCharacterInString(const string& str, char ch) {
    for (char c : str) {
        if (c == ch)
            return true;
    }
    return false;
}

vector<char> check_non_terminal(map<char, vector<string>> grammer,char target,vector<char> v)
{
    vector<char> ans;
    for(auto t : v){
        vector<string> tmp = grammer[t];
        for(auto it : tmp){
            if(isCharacterInString(it,target)){
                ans.push_back(t);
                break;
            }
        }
    }
    return ans;
}


void follow(map<char,vector<char>> result,map<char, vector<string>> grammer){
    map<char,string> str_grammer = {
        {'S',"a S | A b"}, // S-> aS | Ab
        {'A',"X Y Z | %"}, // A-> XYZ | %  Note % consider epsilon
        {'X',"c S | %"},  // X-> cS | %
        {'Y',"d S | %"},  // Y-> dS | %
        {'Z',"e S | %"}
    };

    vector<char> v = {'S','A','X','Y','Z'};
    // vector<char> t = check_non_terminal(grammer,'S',v);
    map<char,vector<char>> ans;
    ans['S'].push_back('%');

    for(int k = 0;k < 3;k++){
        for(char s : v){
            vector<char> t = check_non_terminal(grammer,s,v);
            for(auto yo : t){
                string str = str_grammer[yo];
                for(int i = 0;i < str.length();i++){
                    if(str[i] == s){
                        int new_pos = i + 2;
                        if(new_pos < str.length()){
                            if(islower(str[new_pos])){
                                ans[s].push_back(str[new_pos]);
                            }
                        }
                    }
                }
            }  
        }


        for(char s : v){
            vector<char> t = check_non_terminal(grammer,s,v);
            for(auto yo : t){
                string str = str_grammer[yo];
                for(int i = 0;i < str.length();i++){
                    if(str[i] == s){
                        int new_pos = i + 2;
                        if(new_pos < str.length()){
                            if(str[new_pos] == '|'){
                                vector<char> follow = ans[yo];
                                for(int i = 0;i < follow.size();i++){
                                    ans[s].push_back(follow[i]);
                                }
                            }
                        }
                        else{
                            vector<char> follow = ans[yo];
                            for(int i = 0;i < follow.size();i++){
                                    ans[s].push_back(follow[i]);
                            }
                        }
                    }
                }
            } 
        }

        for(char s : v){
            vector<char> t = check_non_terminal(grammer,s,v);
            for(auto yo : t){
                string str = str_grammer[yo];
                for(int i = 0;i < str.length();i++){
                    if(str[i] == s){
                        int new_pos = i + 2;
                        label:
                        if(new_pos < str.length()){
                            if(isupper(str[new_pos])){
                                vector<char> first = result[str[new_pos]];
                                for(int i = 0;i < first.size();i++){
                                    if(first[i] == '%'){
                                        new_pos = new_pos + 2;
                                        goto label;
                                    }
                                    ans[s].push_back(first[i]);
                                }
                            }
                            else if(islower(str[new_pos])){
                                ans[s].push_back(str[new_pos]);
                            }
                            else if(str[new_pos] == '|'){
                                vector<char> follow = ans[yo];
                                for(int i = 0;i < follow.size();i++){
                                    ans[s].push_back(follow[i]);
                                }
                            }
                        }
                        else{
                            vector<char> follow = ans[yo];
                            for(int i = 0;i < follow.size();i++){
                                    ans[s].push_back(follow[i]);
                            }
                        }
                    }
                }
            } 
        }
    }

    for (auto& pair : ans) {
        // Step 1: Sort the vector
        sort(pair.second.begin(), pair.second.end());

        // Step 2: Remove duplicates
        auto last = unique(pair.second.begin(), pair.second.end());
        pair.second.erase(last, pair.second.end());
    }

    for(int i = 0;i < v.size();i++){
        cout << v[i] << " : ";
        for(auto it : ans[v[i]]){
            cout << it << " ";
        }
        cout << endl;
    }
}


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
    cout << "First : " << endl;
    for(int i = 0;i < v.size();i++){
        cout << v[i] << " : ";
        for(auto it : result[v[i]]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Follow : " << endl;
    follow(result,grammer);

    return 0;
}