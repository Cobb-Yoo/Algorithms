#include <iostream>
#include <queue>
using namespace std;
 
const int MAX = 100;
 
typedef struct
{
        int y, x, z;
}Dir;
 
Dir moveDir[6] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
 
int M, N, H;
int tomato[MAX][MAX][MAX];
queue<pair<pair<int, int>, int>> q;
int noTomato;
 
//토마토가 전부 익었는지 확인
bool allRipe(void)
{
        int possible = M * N*H - noTomato;
        int cnt = 0;
 
        for (int i = 0; i < H; i++)
                 for (int j = 0; j < N; j++)
                         for (int k = 0; k < M; k++)
                                 if (tomato[j][k][i] == 1)
                                          cnt++;
 
        return possible == cnt;
}
 
int BFS(void)
{
        int day = 0;
 
        //처음부터 익힐 수 있는 토마토가 없는 경우
        if (q.empty())
                 return -1;
 
        while (!q.empty())
        {
                 int currentSize = q.size();
 
                 for (int i = 0; i < currentSize; i++)
                 {
                         int y = q.front().first.first;
                         int x = q.front().first.second;
                         int z = q.front().second;
 
                         for (int i = 0; i < 6; i++)
                         {
                                 int nextY = y + moveDir[i].y;
                                 int nextX = x + moveDir[i].x;
                                 int nextZ = z + moveDir[i].z;
 
                                 //다음 토마토가 범위 안에 있고 안 익었을 경우에만
                                 if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && 0 <= nextZ && nextZ < H)
                                          if (tomato[nextY][nextX][nextZ] == 0)
                                          {
                                                  tomato[nextY][nextX][nextZ] = 1;
                                                  q.push(make_pair(make_pair(nextY, nextX), nextZ));
                                          }
                         }
                         q.pop();
 
                         //익힐 수 있는 토마토를 전부 익혔고 전부 익었을 경우
                         if (q.size() == 0 && allRipe())
                                 return day;
                         //익힐 수 있는 토마토는 전부 익혔지만 안 익은 토마토 존재
                         else if (q.size() == 0 && !allRipe())
                                 return -1;
                 }
                 day++;
        }
}
 
int main(void)
{
        cin >> M >> N >> H;
 
        for (int i = 0; i < H; i++)
                 for (int j = 0; j < N; j++)
                         for (int k = 0; k < M; k++)
                         {
                                 cin >> tomato[j][k][i];
                                 if (tomato[j][k][i] == 1)
                                          q.push(make_pair(make_pair(j, k), i)); //익은 토마토는 큐에 넣는다
                                 if (tomato[j][k][i] == -1)
                                          noTomato++; //토마토를 넣을 수 없는 칸
                         }
 
        if (q.size() == M * N*H - noTomato)
        {
                 cout << 0 << endl; //모든 토마토 다 익었을 경우
        }
        else
        {
                 int result = BFS();
                 cout << result << endl;
        }
        return 0;
}
