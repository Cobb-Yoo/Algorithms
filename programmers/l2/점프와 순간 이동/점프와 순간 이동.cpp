using namespace std;

int solution(int n){
    int ans = 0;
    int tmp = n;
    
    while(tmp != 0){
        if(tmp & 1) ans++;
        tmp >>= 1;
    }

    return ans;
}
