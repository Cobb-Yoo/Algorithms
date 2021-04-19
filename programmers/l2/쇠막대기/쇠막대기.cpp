#include <string>
#include <vector>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int len = arrangement.length();
    int cnt=0;
    
    for(int i=0;i<len;i++){
        if(arrangement[i] == '(') cnt++;
        else {
            if(arrangement[i-1] == '(') answer += --cnt;
            else {
                answer++;
                cnt--;
            }
        }
    }
    return answer;
}
