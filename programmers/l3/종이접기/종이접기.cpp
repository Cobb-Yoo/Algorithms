#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    
    for(int i=1;i<n;i++){
        vector<int> tmp;
        int len = answer.size();
        
        int j;
        for(j=0;j<len;j++){
            tmp.push_back(j%2);
            tmp.push_back(answer[j]);
        }
        tmp.push_back(j%2);
        answer = tmp;
    }
        
    return answer;
}
