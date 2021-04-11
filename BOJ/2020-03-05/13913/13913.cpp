#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100000 + 1;
 
int parent[MAX]; //해당 지점 방문 직전 지점 저장
bool visited[MAX];
vector<int> path; //경로 저장
 
int minSecond(int N, int K)
{
    queue<pair<int, int>> q;
 
    q.push(make_pair(N, 0));
    visited[N] = true;
 
    while (!q.empty())
    {
        int curLoc = q.front().first;
        int curSec = q.front().second;
        q.pop();
                
		if (curLoc == K) //목적지 도달 시 break
        {
            int idx = curLoc;
                 
            while (idx != N)
            {
                path.push_back(idx);
                idx = parent[idx];
            }
            path.push_back(N);
 
            return curSec;
        }
                 
   		if (curLoc + 1 < MAX && !visited[curLoc + 1])
    	{
        	q.push(make_pair(curLoc + 1, curSec + 1));
	        visited[curLoc + 1] = true;
    	    parent[curLoc + 1] = curLoc;
	    }
    	if (curLoc - 1 >= 0 && !visited[curLoc - 1])
	    {
    	    q.push(make_pair(curLoc - 1, curSec + 1));
        	visited[curLoc - 1] = true;
	        parent[curLoc - 1] = curLoc;
    	}
	    if (curLoc * 2 < MAX && !visited[curLoc * 2])
    	{
        	q.push(make_pair(curLoc * 2, curSec + 1));
	        visited[curLoc * 2] = true;
    	    parent[curLoc * 2] = curLoc;
		}
    }
} 

int main(void)
{
        int N, K;
        cin >> N >> K;
 
        cout << minSecond(N, K) << "\n";
       
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << " ";
        cout << endl;
        return 0;
}
