#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int len;
bool dfs(string end, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& answer, vector<string>& tmp, int cnt){
    tmp.push_back(end);
    
    if(cnt == len){
        answer = tmp;
        return 1;
    }
    
    for(int i=0;i<len;i++){
        if(tickets[i][0] == end && !visited[i]){
            visited[i] = 1;
            if(dfs(tickets[i][1],tickets, visited, answer, tmp, cnt+1)) return 1;
            visited[i] = 0;
        }
    }
    tmp.pop_back();
    return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, tmp;
    vector<bool> visited(tickets.size(),false);
    
    sort(tickets.begin(),tickets.end());
    int cnt =0;
    len = tickets.size();
    
    dfs("ICN", tickets, visited, answer, tmp, cnt);
    
    return answer;
}
