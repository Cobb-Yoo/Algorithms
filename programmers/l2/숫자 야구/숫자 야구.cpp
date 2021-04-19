#include <string>
#include <vector>
#include <algorithm> //find
using namespace std;

vector<string> datas;

void dfs(vector<bool>& visited, int n, string tmp){
    if(visited[n]) return;
    
    visited[n] = true;
    tmp += to_string(n+1);
    
    if(tmp.size() == 3){
        datas.push_back(tmp);
        return;
    }
    
    for(int i=0;i<9;i++){
        if(!visited[i] && i != n){
            dfs(visited, i, tmp);
            visited[i] = false;
        }
    }
}

pair<int,int> get_score(string request, string candidate){
    int strikes = 0, balls = 0;
    
    for(int i=0;i<3;i++){
        if(request[i] == candidate[i]) strikes++;
        else if(find(candidate.begin(), candidate.end(),request[i]) != candidate.end()) balls++;
    }
    
    return {strikes, balls};
}

int solution(vector<vector<int>> baseball){
    for(int i=0;i<9;i++){
        vector<bool> visited(9);
        dfs(visited, i , "");
    }
    
    for(auto game : baseball){
        vector<string> tmp;
        
        for(auto candidate : datas){
            pair<int,int> score = get_score(to_string(game[0]), candidate);
            
            if(score.first == game[1] && score.second == game[2]) tmp.push_back(candidate);
        }
        datas = tmp;
    }
    
    return datas.size();
}
