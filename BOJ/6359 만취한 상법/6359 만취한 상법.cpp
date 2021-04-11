#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

bool b[MAX+1];
int dp[MAX+1];

int main(){
	int T;
	cin >> T;
	
	
	while(T--){
		int n;
		cin >> n;
		
		memset(b,1,sizeof(b));
		dp[1] = 1;
		
		for(int i=2;i<=n;i++){
			for(int j=i;j<=n;j+=i){
				b[j] = !b[j];
			}
			
			if(b[i]) dp[i] = dp[i-1]+1;
			else dp[i] = dp[i-1];
		}
		
			
		cout << dp[n] << endl;
	}
}
