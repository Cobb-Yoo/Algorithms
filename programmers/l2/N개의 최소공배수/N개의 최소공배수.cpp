#include <string>
#include <vector>

using namespace std;

int getGCD(int a, int b) {
    if(b == 0) return a;
    return getGCD(b, a%b);
}
  
int getLCM(int a, int b) {
    return a * b / getGCD(a, b);
}

int solution(vector<int> arr) {
    int answer = 1;
    int len = arr.size();
    
    for(int i=0;i<len;i++) answer = getLCM(answer, arr[i]);
    
    return answer;
}
