#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int len1 = arr1.size();
    int len2 = arr1[0].size();
    int len3 = arr2[0].size();
    
    vector<vector<int>> answer;
    
    for(int i=0;i<len1;i++){
        vector<int> arr;
        for(int k=0;k<len3;k++){
            int tmp=0;
            for(int j=0;j<len2;j++){
                tmp+=arr1[i][j] * arr2[j][k];
            }
            arr.push_back(tmp);
        }
        answer.push_back(arr);
    }
    return answer;
}
