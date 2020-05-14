#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int mod = 1000000;
string s;
int len;
int dp[5020];

int main(){
	cin >> s;
	len = s.size();
	
	memset(dp,0,sizeof(dp));
	
	dp[0] = 1;
	dp[1] = 1;
	
	
	if(s[0]=='0') {
		cout << 0 << endl;
		return 0;
	}
	
	for(int i=2;i<=len;i++){
		if(s[i-1] > '0') dp[i] = dp[i-1] % mod;
		
		int x = (s[i-2]-'0')* 10 + s[i-1] - '0';
		if(9 < x && x < 27) dp[i] = (dp[i]+dp[i-2]) % mod;
	}
	
	cout << dp[len] << endl;
}
