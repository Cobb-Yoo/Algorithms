#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.size();
    
    for(int i=0;i<len;i++){
        stack<char> st;
        
        int j;
        for(j=0;j<len;j++){
            char ch = s[(j+i)%len];
            
            if(ch == '[' || ch == '{' || ch == '(') st.push(ch);
            else if(ch == ']' && st.top() == '[') st.pop();
            else if(ch == '}' && st.top() == '{') st.pop();
            else if(ch == ')' && st.top() == '(') st.pop();
            else break;
        }
        if(st.empty() && j == len) answer++;
    }
    return answer;
}
