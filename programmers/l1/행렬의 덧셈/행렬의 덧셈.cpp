#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int len1 = arr1.size();
    int len2 = arr1[0].size();
    
    for(int i=0;i<len1;i++){
        vector<int> v;
        for(int j=0;j<len2;j++){
            v.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(v);
    }
    
    return answer;
}
