#include <bits/stdc++.h>

int solve(int n){
    int cnt = 0;
    
    int i;
    for(i=1;i<=n;i++){
        if(n%i == 0) cnt++;
    }
    
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i= left;i<=right;i++){
        int num = solve(i);
        
        if(num&1) answer -= i;
        else answer += i;
    }
    
    return answer;
}
