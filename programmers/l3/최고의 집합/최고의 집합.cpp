#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int tmp = s/n;
    int total = 0;
    
    if(tmp == 0) return {-1};
    else{
        for(int i=0;i<n;i++){
            answer.push_back(tmp);
            total += tmp;
        }
    }
    
    while(total < s){
        for(int i=n-1;i>=0;i--){
            if(total < s){
                answer[i]++;
                total++;
            }else{
                break;
            }
        }
    }
    
    return answer;
}
