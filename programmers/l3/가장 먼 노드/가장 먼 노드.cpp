#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(int a,int b){
    return a > b;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<pair<int,int>> q;
    vector<bool> visited(n,0);
    vector<int> deep(n,0);
    vector<vector<bool>> graph(n,vector<bool>(n,0));

    for(auto i : edge){
        graph[i[0]-1][i[1]-1] = 1;
        graph[i[1]-1][i[0]-1] = 1;
    }

    for(int i=0;i<n;i++){
        if(graph[0][i]){
            q.push({i,1});
            visited[i] = 1;
            deep[i] = 1;
        }
    }
    visited[0] = 1;

    while(!q.empty()){
        pair<int,int>tmp = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(graph[tmp.first][i] && !visited[i]){
                visited[i] = 1;
                deep[i] = 1+tmp.second;
                q.push({i,deep[i]});
            }
        }
    }

    sort(deep.begin(),deep.end(),cmp);
    int m = deep[0];
    for(auto i : deep){
        if(i == m) answer++;
        else break;
    }

    return answer;
}
