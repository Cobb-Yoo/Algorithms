#include<cstdio>
#include<vector>
 
using namespace std;
 
vector<vector<int>> map;
bool visit[101] = { false };
int computer_num, ans = 0;
 
void dfs(int x)
{
    ans++;
    visit[x] = true;
 
    for (int k = 0; k < map[x].size(); k++)
    {
        if (!visit[map[x][k]])dfs(map[x][k]);
    }
    return;
}
 
int main()
{
    int n, from, to;
    scanf("%d %d", &computer_num, &n);
    map.resize(computer_num + 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &from, &to);
        map[from].push_back(to);
        map[to].push_back(from);
    }
 
    dfs(1);
 
    printf("%d", ans - 1);
    return 0;
}
