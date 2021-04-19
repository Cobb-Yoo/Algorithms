#include <string>
#include <vector>
#define ll long long
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    ll tmp = 1;
    vector<int>arr;
    
    for(int i=1;i<=n;i++) {
        tmp *= i;
        arr.push_back(i);
    }
    
    k--;
    
    while(n){
        tmp /= n--;
        
        answer.push_back(arr[k/tmp]);
        arr.erase(arr.begin()+k/tmp);
        
        k %= tmp;
    }
    
    return answer;
}
