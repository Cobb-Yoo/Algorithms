#include <bits/stdc++.h>
using namespace std;

vector<int> y;
vector<int> x;

int main(){
	int n,m,l;
	cin >> n >> m >> l;
	
	x.push_back(0);
	x.push_back(n);
	y.push_back(0);
	y.push_back(m);

	for(int i=0;i<l;i++){
		int a,b;
		cin >> a >> b;
		
		if(a) x.push_back(b);
		else y.push_back(b);
	}
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	int answer = 0;
	int x_len = x.size();
	int y_len = y.size();
	
	for(int i=1;i<x_len;i++){
		for(int j=1;j<y_len;j++){
			int c = y[j]-y[j-1];
			int l = x[i]-x[i-1];
			
			answer = max(answer, c*l);
		}
	}
	
	cout << answer << endl;
}
