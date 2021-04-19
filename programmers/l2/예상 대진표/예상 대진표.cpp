using namespace std;

int solution(int n, int a, int b){
    int answer = 0;
    a--;
    b--;
    
    while(a!=b){
        a >>= 1;
        b >>= 1;
        
        answer++;
    }

    return answer;
}
