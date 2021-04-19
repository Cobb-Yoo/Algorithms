#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int ssize = number.length() - k;
    int len = number.length();
    
    stack<char> arr;
    for(int i=0;i<len;i++){
        char a = number[i];
        while(!arr.empty() && k > 0){
            char top = arr.top();
            if(top < a){
                arr.pop();
                k--;
            }
            else break;
        }
        arr.push(a);
    }
    
    while(ssize != arr.size()) arr.pop();
    while(!arr.empty()){
        answer += arr.top();
        arr.pop();
    }
    
    reverse(answer.begin(),answer.end());
    
    return answer;
}
