#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
const int MAX = 10000;

int option[3][2] = {{-1,1},{0,1},{1,1}};
 
int R, C;
string graph[MAX];
bool visited[MAX][500];

bool dfs(int y, int x){
    visited[y][x] = true;
    if (x == C - 1) return true;
 
    for (int i = 0; i < 3; i++){
        int nextY = y + option[i][0];
        int nextX = x + option[i][1];
 
        if(0<=nextY && nextY < R && 0<=nextX && nextX < C){
            if (!visited[nextY][nextX] && graph[nextY][nextX] == '.'){
                bool flag = dfs(nextY, nextX);
                if (flag)		return flag;	
			}
        }
    }
    return false;
}
 
int main(){
    cin >> R >> C;
 
    for (int i = 0; i < R; i++) cin >> graph[i];
 
    int result = 0;
    for (int i = 0; i < R; i++) result += dfs(i, 0);

	
    cout << result;
}
