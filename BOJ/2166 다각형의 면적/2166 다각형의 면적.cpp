#include <bits/stdc++.h>
using namespace std;

vector<pair<double,double>> v;

double getTriangle(pair<double,double> x, pair<double,double> y, pair<double,double> z){
	return ((x.first*y.second+y.first*z.second+z.first*x.second)-(x.first*z.second+y.first*x.second+z.first*y.second))/2;
}

int main(){
	int n; cin >> n;
	
	for(int a,b,i=0;i<n;i++){
		cin >> a >> b;
		
		v.push_back({a,b});
	}
	
	double ans=0;
	for(int i=2;i<n;i++){
		ans += getTriangle(v[0], v[i-1], v[i]);
	}
	
	printf("%.1f\n", abs(ans));
}
