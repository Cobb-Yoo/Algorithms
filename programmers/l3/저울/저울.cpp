#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 0;
    
    sort(weight.begin(),weight.end());
    
    int len = weight.size();
    for(int i=0;i<len;i++){
        if(answer+1 < weight[i]) break;
        answer += weight[i];
    }
    return answer+1;
}
