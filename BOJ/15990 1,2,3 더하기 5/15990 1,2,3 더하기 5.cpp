#include <iostream>
#define mod	1000000009
#define ll long long
using namespace std;

ll arr[100001][4];
int n;

void init(){
	arr[1][1] = arr[2][2] = arr[3][1] = arr[3][2] = arr[3][3] = 1;
	
	for(int i=4;i<=100000;i++){
		if(i-1 >= 0) arr[i][1] = (arr[i-1][2]+arr[i-1][3]) % mod;
		if(i-2 >= 0) arr[i][2] = (arr[i-2][1]+arr[i-2][3]) % mod;
		if(i-3 >= 0) arr[i][3] = (arr[i-3][1]+arr[i-3][2]) % mod;
	}
}

ll getAnswer(){
	return (arr[n][1] + arr[n][2] + arr[n][3]) % mod;
}

int main(){	
	int t; cin >> t;
	
	init();
	
	for(int i=0;i<t;i++){
		cin >> n;
		
		printf("%lld\n",getAnswer());
	}
}
