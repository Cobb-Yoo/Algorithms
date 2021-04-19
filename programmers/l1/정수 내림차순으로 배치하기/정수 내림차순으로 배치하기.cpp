#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a,int b){
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;
    while(n > 0){
        arr.push_back(n%10);
        n/=10;
    }
    
    int len = arr.size();
    sort(arr.begin(),arr.end(),cmp);
    
    for(int i=0;i<len;i++){
        answer *= 10;
        answer += arr[i];
    }
    
    return answer;
}
