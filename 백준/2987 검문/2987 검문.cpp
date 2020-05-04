#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int GCD(int a, int b){
	if(a%b == 0) return b;
	else return GCD(b,a%b);
}

int main(){
	int n;
	cin >> n;
	
	vector<int> v(n);
	
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	
	sort(v.begin(),v.end());
	
	int gcd = v[1] - v[0];
	
	for(int i=2;i<n;i++){
		gcd = GCD(gcd, v[i]-v[i-1]);
	}
	
	vector<int> result;
	
	for(int i=2;i*i <= gcd ;i++){
		if(gcd % i == 0){
			result.push_back(i);
			result.push_back(gcd/i);
		}
	}
	result.push_back(gcd);
	
	sort(result.begin(),result.end());
	result.erase(unique(result.begin(),result.end()),result.end());
	
	int len = result.size();
	
	for(int i=0;i<len;i++){
		cout << result[i] << " ";
	}
}
