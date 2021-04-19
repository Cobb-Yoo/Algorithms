#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int idx = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    
    while (stock < k) {
        for (int i = idx; i<dates.size() && stock >= dates[i]; i++) {
            pq.push(supplies[i]);
            idx = i + 1;
        }
        
        stock += pq.top();
        pq.pop();
        answer += 1;
    }
    
    return answer;
}
