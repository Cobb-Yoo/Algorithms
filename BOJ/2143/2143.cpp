#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int Max = 1001;
int arr[Max], brr[Max];

int main(){
	int t; cin >> t;
	int n,m;
	vector<int> v, w;
	
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	
	cin >> m;
	for(int i=0;i<m;i++) cin >> brr[i];
	
	for(int i=0;i<n;i++){
		int sum = arr[i];
		v.push_back(sum);
		for(int j=i+1;j<n;j++){
			sum += arr[j];
			v.push_back(sum);
		}
	}
	
	for(int i=0;i<m;i++){
		int sum = brr[i];
		w.push_back(sum);
		for(int j=i+1;j<m;j++){
			sum += brr[j];
			w.push_back(sum);
		}
	}
	
	sort(w.begin(), w.end());
	
	ll answer =0 ;
	for(auto iter : v){
		int diff = t - iter;
		auto ub = upper_bound(w.begin(), w.end(), diff); 
		auto lb = lower_bound(w.begin(), w.end(), diff);
		answer += (ub-lb);
	}
	cout << answer;
}
