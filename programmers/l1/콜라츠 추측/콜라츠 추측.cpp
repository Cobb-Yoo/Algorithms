#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    
    while(n != 1){
        if(answer == 500) return -1;
        
        n & 1 ? n = n*3 + 1 : n = n >> 1;
        answer++;
    }
    return answer;
}
