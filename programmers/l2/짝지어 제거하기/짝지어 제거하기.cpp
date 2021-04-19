#include <string>
#include <stack>
using namespace std;

int solution(string s){
    int len = s.size();
    stack<char> a;
    
    for(int i=0;i<len;i++){
        if(a.empty()) {
            a.push(s[i]);
            continue;
        }
        
        if(a.top() == s[i]) a.pop();
        else a.push(s[i]);
    }
    
    
    if(!a.empty()) return 0;
    return 1;
}
