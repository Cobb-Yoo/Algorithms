#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> map;
int a,b;

bool check(int y, int x, int n){
    for(int i=y;i<y+n;i++){
        for(int j=x;j<x+n;j++){
            if(map[y][x] != map[i][j]) return 0;
        }
    }
    return 1;
}

void solve(int y, int x, int n){
    if(check(y,x,n)){
        if(map[y][x]) b++;
        else a++;
    }
    else{
        int tmp = n/2;
        solve(y, x, tmp);
        solve(y+tmp, x, tmp);
        solve(y, x+tmp, tmp);
        solve(y+tmp, x+tmp, tmp);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    map = arr;
    
    solve(0,0, map.size());
    
    vector<int> answer;
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}
