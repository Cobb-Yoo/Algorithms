#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool cmp1 (pair<int,int> a, pair<int,int> b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

bool cmp2 (int a, int b){
	return a < b;
}

int main(){
	int n,k;
	cin >> n >> k;
	
	//수용량이 작은 가방부터 채우는게 좋을것 같음.
	vector<pair<int,int>> data; // first == 무게, second == 가치 
	for(int i=0;i<n;i++) {
		int w,p;
		cin >> w >> p;
		data.push_back({w,p});
	}
	
	vector<int> arr(k);
	for(int i=0;i<k;i++) cin >> arr[i];
	
	sort(data.begin(), data.end(),cmp1);
	sort(arr.begin(), arr.end(),cmp2);
	
	long long answer = 0;
	priority_queue<int> q;
	for(int i=0,j=0;i<k;i++){
		
		while(j < n && arr[i] >= data[j].first) q.push(data[j++].second);
		
		if(!q.empty()){
			answer += q.top();
			q.pop();
		}
	}
	
	cout << answer << endl;
}
