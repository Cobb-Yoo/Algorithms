#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int arr[n+1];
    
    if(n < 3) return n;
    
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i=3;i<=n;i++){
        arr[i] = (arr[i-1]+arr[i-2]) % 1000000007;
    }
    
    return arr[n];
}
