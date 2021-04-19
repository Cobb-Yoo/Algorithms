#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class cmp{
    public:
        bool operator()(vector<int> a, vector<int> b){
            return a[1] > b[1];
        }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int j = 0;
    int time = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    
    int len = jobs.size();
    while(j < len || !pq.empty()){
        if(len > j && time >= jobs[j][0]){
            pq.push(jobs[j++]);
            continue;
        }
        
        if(!pq.empty()){
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }else{
            time = jobs[j][0];
        }
    }
    
    return answer/len;
}
