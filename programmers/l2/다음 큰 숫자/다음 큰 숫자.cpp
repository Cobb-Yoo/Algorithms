#include <string>
#include <vector>

using namespace std;

int check_one(int n){
    int cnt = 0;
    while(n > 0){
        if(n & 1) cnt++;
        n >>= 1;        
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;

    int a = check_one(n);

    for(int i=n+1;;i++){
        answer = check_one(i);
        if(a == answer) return i;
    }
}
