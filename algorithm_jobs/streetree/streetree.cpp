#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, w;

int gcd(int a, int b){
	if(a < b) a^=b^=a^=b;
	
	return a%b == 0 ? b : gcd(b, a%b);
}

int main(){
	int n,cnt=0; cin >> n;
	
	for(int tmp,i=0;i<n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	int len = v.size()-1;
	for(int i=0;i<len;i++) w.push_back(v[i+1]-v[i]);
	
	int g = w[0];
	
	for(int i=1;i<len;i++) g = gcd(g, w[i]);
	for(int i=0;i<len;i++) cnt += w[i]/g - 1;
	
	cout << cnt;
}
