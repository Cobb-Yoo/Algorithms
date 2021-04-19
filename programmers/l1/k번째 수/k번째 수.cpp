#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    int len = commands.size();
    vector<int> answer;

    for(int i=0;i<len;i++){
        vector<int> arr;
        for(int j=commands[i][0]-1;j<commands[i][1];j++){
            arr.push_back(array[j]);
        }

        sort(arr.begin(),arr.end());
        answer.push_back(arr[commands[i][2]-1]);
    }

    return answer;
}
