#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> fibo;

void init_fibo_array(){
	fibo.push_back(1);
	fibo.push_back(2);
	
	int idx=2;
	while(1){
		int num = fibo[idx-1]+fibo[idx-2];
		if(num > 1000000000) break;
		
		fibo.push_back(num);
		idx++;
	}
}

vector<int> solve(int num){
	int len = fibo.size();
	
	vector<int> v;
	for(int i=len-1;i>=0;i--){
		if(fibo[i] <= num){
			num -= fibo[i];
			v.push_back(fibo[i]);
		}
		
		if(num <= 0) break;
	}
	
	return v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	
	init_fibo_array();
	
	for(int quest,i=0;i<t;i++){
		cin >> quest;
		
		vector<int> ans = solve(quest);
		
		int len = ans.size();
		for(int i=len-1;i>=0;i--){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	
}
