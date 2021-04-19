#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int len = money.size();
    
    int arr[100001] = {0};
    arr[0] = 1;
    for(int i=money[0];i<=n;i+=money[0]){
        arr[i] = 1;
    }
    
    for(int i=1;i<len;i++){
        for(int j=0;j<=n;j++){
            if(j >= money[i]) arr[j] += arr[j-money[i]] % 1000000007;            
        }
    }
    answer = arr[n];
    
    return answer;
}
