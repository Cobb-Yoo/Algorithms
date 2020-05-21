#include <iostream> 
#include <string>
using namespace std;

int main(){
	int n,f;
	int answer=0;
	
	cin >> n >> f;
	
	n -= (n%100);
	
	while(1){
		if((n+answer) % f == 0) break;
		answer++;
	}
	
	printf("%02d\n",answer);
}
