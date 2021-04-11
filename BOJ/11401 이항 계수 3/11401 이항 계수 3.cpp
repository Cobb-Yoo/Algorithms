#include <iostream>
#define ll long long
using namespace std;

const int MAX = 4000000;
const ll P = 1000000007;
int n,k;

ll fac[MAX+1];
ll arr[MAX+1];

ll pow(ll a, ll b){
	ll tmp = 1;
	while(b > 0){
		if(b % 2){
			tmp *= a;
			tmp %= P;
		}
		a *= a;
		a %= P;
		b /= 2;
	}
	
	return tmp;
}

void init(){
	fac[1] = 1;
	for(int i=2;i<=MAX;i++) fac[i] = (fac[i-1] * i) % P;
	arr[MAX] = pow(fac[MAX],P-2);
	for(int i=MAX-1;i>0;i--) arr[i] = (arr[i+1]*(i+1))%P;
}

int main(){
	cin >> n >> k;
	
	init();
	
	if(n==k || !k) cout << 1 << endl;
	else{
		ll answer = fac[n] * arr[k]%P * arr[n-k]%P;
		cout << answer << endl;	
	}
	
}


