#include <iostream>
#include <queue>
#define ll long long
using namespace std;

ll a,b;

int main(){
	cin >> a >> b;
	int cnt=0;
	
	while(a<b){
		if(b%10 == 1){
			b /= 10;
			cnt++;
		}
		else if((b&1)==0){
			b >>= 1;
			cnt++;
		}
		else{
			cout << -1;
			return 0;
		}
	}
	
	if(a > b) cout << -1 << endl;
	else cout << cnt+1 << endl;
}
