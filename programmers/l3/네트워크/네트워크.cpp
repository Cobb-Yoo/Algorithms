#include <cstring>
#include <string>
#include <vector>

using namespace std;

bool arr[201];
int N;
vector<vector<int>> v;

void dfs(int n, int answer){
    arr[n] = 1;

    for(int i=0;i<N;i++){
        if(!arr[i] && v[n][i]) dfs(i, answer);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    v = computers;

    for(int i=0;i<n;i++){
        if(arr[i]) continue;
        dfs(i, ++answer);
    }

    return answer;
}
