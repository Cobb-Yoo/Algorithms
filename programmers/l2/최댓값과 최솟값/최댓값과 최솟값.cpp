#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return stoi(a) < stoi(b);
}

string solution(string s) {
    string answer = "";
    int len = s.length();
    vector<string> arr;
    string tmp;
    
    for(int i=0;i<len;i++){
        if(s[i] == ' '){
            arr.push_back(tmp);
            tmp = "";
        }else{
            tmp += s[i];
        }
    }
    arr.push_back(tmp);
    
    sort(arr.begin(),arr.end(),cmp);
    
    answer = arr[0] + " " + arr[arr.size()-1];
    
    return answer;
}
