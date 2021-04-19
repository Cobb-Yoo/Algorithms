#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int len1 = lost.size();
    int len2 = reserve.size();
    int answer = n - len1;
    
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(reserve[j] == lost[i]){
                reserve[j] = -1;
                lost[i] = -1;
                answer++;
                break;
            }
        }
    }
    
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(reserve[j]-1 == lost[i] || reserve[j]+1 == lost[i]){
                reserve[j] = -1;
                answer++;
                break;
            }
        }
    }
    
    return answer;
}
