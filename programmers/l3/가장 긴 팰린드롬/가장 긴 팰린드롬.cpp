#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=1;
    int len = s.size();
    int high,low;
    
    for(int i=1;i<len;i++){
        high = i+1;
        low = i-1;
            
        while(0<=low && high < len && s[low] == s[high]){
            if(high - low + 1 > answer) answer = high - low + 1;
            low--;
            high++;
        }
        
        high = i;
        low = i-1;
            
        while(0<=low && high < len && s[low] == s[high]){
            if(high - low + 1 > answer) answer = high - low + 1;
            low--;
            high++;
        }
    }
    
    return answer;
}
