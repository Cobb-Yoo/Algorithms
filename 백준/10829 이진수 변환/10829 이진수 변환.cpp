#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
	ll n; cin >> n;
	
	vector<bool> v;
	
	while(n){
		if((n&1)) v.push_back(1);
		else v.push_back(0);
		
		n >>= 1;
	}
	
	for(int i=v.size()-1;i>=0;i--){
		cout << v[i];
	}
}


