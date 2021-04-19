#include <string>
#include <vector>
#define ll long long
using namespace std;

long long solution(int n, vector<int> times) {
    
    ll len = times.size();
    ll max = (ll)times.back() * n;
    ll min = 1;
    ll mid = (max + min) / 2;
    ll sum = 0;
    ll answer = max;
    
    while(min <= max){
        sum = 0;
        mid = (min + max) / 2;
        
        for(int i=0;i<len;i++) sum += mid/times[i];
        
        if(sum < n) min = mid+1;
        else {
            if(mid <= answer) answer = mid;
            max = mid - 1;
        }
    }
    
    return answer;
}
