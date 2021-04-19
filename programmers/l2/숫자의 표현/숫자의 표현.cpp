#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int len = n/2+1;
    
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=i;j<=len;j++){
            sum += j;
            if(sum == n){
                answer++;
                break;
            }else if(sum > n){
                break;
            }
        }
    }
    
    return answer+1;
}
