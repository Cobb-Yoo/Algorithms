#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w){
    int answer = 0;
    int len = stations.size();
    
    int start = 1;
    bool flag = 1;
    for(int i=0;i<len;i++){
        int left = stations[i] - w - 1;
        int right = stations[i] + w + 1;
        int length = left - start + 1;
        
        if(length < 0) length = 0;
        
        answer += length/(w*2+1);
        if(length%(w*2+1) != 0) answer += 1;
        
        if(right > n){
            flag = 0;
            break;
        }
        
        start = right;
    }

    if(flag){
        int length = n - start + 1;
        answer += length/(w*2+1);
        if(length%(w*2+1) != 0) answer += 1;
    }
    
    return answer;
}
