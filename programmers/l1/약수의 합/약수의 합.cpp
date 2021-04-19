#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    int len = sqrt(n);
    for(int i=1;i<=len;i++){
        if(!(n%i)){
            if(i*i == n){
                answer += i;
                break;
            }
            answer += i;
            answer += n/i;
        }
    }
    return answer;
}
