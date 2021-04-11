#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main(){
    string answer, s;
    cin >> s;
    
    reverse(s.begin(), s.end());
    answer = "0000" + s;
 
    bool flag = 0;
    int i;
    
    int s_len = s.size();
    for(i=0; i<s_len; i++){
        int n = answer[i]-'0' + s[i]-'0' + flag;
        if(n >= 2){
            n -= 2;
            flag = 1;
        }
        else flag = 0;
        answer[i] = n + '0';
    }
    
    int answer_len = answer.size();
    for(; i<answer_len; i++){
        int n = answer[i]-'0' + flag;
        if(n == 2){
            n = 0;
            flag = 1;
        }
        else flag = 0;
        answer[i] = n +'0';
    }
    
    if(flag) answer.push_back('1');
    
    reverse(answer.begin(), answer.end());
    cout << answer << endl;
}


