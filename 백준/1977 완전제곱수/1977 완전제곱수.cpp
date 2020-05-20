#include <iostream>
#include <cmath> 
using namespace std;

int main(){
	int m,n;
	cin >> m >> n;
	
	int answer=0;
	int s = sqrt(m-1)+1;
	s *= s;
	for(int i=sqrt(m-1)+1;i*i<=n;i++) answer += i*i;
	
	if(answer) cout << answer << endl << s;
	else cout << -1 << endl;
}
