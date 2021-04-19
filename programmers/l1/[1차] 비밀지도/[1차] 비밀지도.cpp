#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> arr3;
    for(int i=0;i<n;i++) arr3.push_back(arr1[i] | arr2[i]);
    
    for(int i=0;i<n;i++){
        string tmp="";
        for(int j=0;j<n;j++){
            arr3[i] % 2 ? tmp += "#": tmp += " ";
            arr3[i] /= 2;
        }
        
        reverse(tmp.begin(),tmp.end());
        answer.push_back(tmp);
    }
    
    return answer;
}
