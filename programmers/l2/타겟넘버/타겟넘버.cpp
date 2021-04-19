#include <iostream>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> n, int t, int sum, int idx)
{
    if (idx == n.size())  //끝까지 갔으면
    {
        if (sum == t)
            answer++;
        return;
    }
    dfs(n, t, sum + n[idx], idx + 1);
    dfs(n, t, sum - n[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {

    dfs(numbers,target,0,0);
    return answer;
}
