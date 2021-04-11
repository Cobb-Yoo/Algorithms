#include <iostream>
#include <vector>
using namespace std;

int gcd(int a,int b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	
	for(int T=0;T<t;T++){
		int n; cin >> n;
		long long answer = 0;
		
		vector<int> v(n);
		
		for(int i=0;i<n;i++) cin >> v[i];
		
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				
				answer += gcd(v[i],v[j]);
			}
		}
		
		cout << answer << endl;
	}
}
