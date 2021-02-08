#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	
	int cnt = 0;
	for(int i=n;i>=1;i--){
		if(n%i == 0) cnt++;
		if(cnt == m){
			cout << n/i;
			return 0;
		}
	}
	
	if(cnt != m) cout << 0;
}
