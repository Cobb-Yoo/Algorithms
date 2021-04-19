#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int len = truck_weights.size();
    int cnt=0;
    int total_weight=0;
    queue<int> q;

    for(int i=0;i<bridge_length;i++) q.push(0);

    while(1){
        if(cnt == len) {
            answer += bridge_length;
            break;
        }
        answer++;
        total_weight -= q.front();
        q.pop();
        if(truck_weights[cnt] + total_weight <=  weight){
            q.push(truck_weights[cnt]);
            total_weight += truck_weights[cnt++];
        }else{
            q.push(0);
        }
    }
    return answer;
}
