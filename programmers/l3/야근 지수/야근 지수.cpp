#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int len = works.size();
    priority_queue<int> q;

    for(int i=0;i<len;i++) q.push(works[i]);
    for(int i=0;i<n;i++){
        q.push(q.top()-1);
        q.pop();
    }

    for(int i=0;i<len;i++){
        if(q.top() > 0) answer += q.top()*q.top();
        q.pop();
    }

    return answer;
}
