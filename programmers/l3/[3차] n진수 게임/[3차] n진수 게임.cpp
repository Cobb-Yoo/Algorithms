#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<char> s;

void f(int n, int a){
    if(a == 0) return s.push(char('0'));
    int tmp = a;
    while(tmp > 0){
        int k = tmp % n;
        k > 9 ? s.push(char('A'+k-10)) : s.push(char('0' + k));
        tmp /= n;
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int cnt = 1;
    int num = 0;
    while(answer.size() < t){
        f(n, num++);
        
        for(int i=0;!s.empty() && answer.size() != t;i++){
            if(cnt == p) answer += s.top();
            s.pop();
            cnt++;
            if(cnt > m) cnt = 1;
        }
    }
    return answer;
}
