using namespace std;

int GCD(int a,int b){
    if(!b) return a;
    else return GCD(b,a%b);
}

long long solution(int w,int h)
{
	long long answer;
    int gcd = GCD(w,h);
    
    answer = (long long)w*(long long)h - gcd*(w/gcd + h/gcd - 1);
    
	return answer;
}
