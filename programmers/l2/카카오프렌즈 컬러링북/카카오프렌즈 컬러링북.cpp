#include <vector>
#include <cstring>
using namespace std;

int option[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visited[101][101];
int M,N;

int check(int a,int b,vector<vector<int>> picture){
    int cnt=0;

    for(int i=0;i<4;i++){
        int x = a + option[i][0];
        int y = b + option[i][1];
        if(0 <= x && x < M && 0 <= y && y < N){
            if(!visited[x][y] && picture[a][b] == picture[x][y]){
                visited[x][y] = 1;
                cnt++;
                cnt += check(x,y,picture);
            }
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M = m;
    N = n;

    memset(visited,0,sizeof(visited));

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] || !picture[i][j]) continue;

            int tmp = check(i,j,picture);

            number_of_area++;
            if(tmp > max_size_of_one_area) {
                max_size_of_one_area = tmp;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
