#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int main(){
	int n; cin >> n;
	int a,b,c,d;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c >> d;
		
		v.push_back({a*100+b, c*100+d});
	}
	
	sort(v.begin(), v.end());
	int idx = -1;
	int tmp=0;
	int result=0;
	
	for(int i=301;i<=1130;i=tmp){
		bool flag = 0;
		idx++;
		
		for(int j=idx;j<v.size();j++){
			if(v[j].first > i) break;
			
			if(tmp < v[j].second){
				tmp = v[j].second;
				idx = j;
				flag = 1;
			}
		}
		
		if(flag) result++;
		else{
			cout << 0;
			return 0;
		}
	}
	
	cout << result << endl;
}
