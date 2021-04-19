#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool arr[1000001];

int solution(int n) {
    int answer = 0;
    
    int len = sqrt(n);
     for (int i = 2; i <= len; i++) { 
        if (!arr[i]){
            for (int j = i + i; j <= n; j += i){
                arr[j]=1;
            }
        }
    }
    
    for(int i=1;i<=n;i++) if(!arr[i]) answer++;
    
    return answer-1;
}
