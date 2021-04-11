#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;
vector<int> v;

bool possible(int dist){
	int cnt = 1;
	int left = v[0];
	int len = v.size();
	
	for(int i=1;i<len;i++){
		if(v[i] - left >= dist){
			cnt++;
			left = v[i];
		}
	}
	
	if(cnt >= c) return 1;
	return 0;
}

int main(){
	cin >> n >> c;
	
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(),v.end());
	
	int left = 1;
	int right = v[v.size()-1]-v[0];
	int mid = 0;
	int answer=0;
	
	while(left <= right){
		mid = (left + right) / 2;
		
		if(possible(mid)){
			answer = max(answer, mid);
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	
	cout << answer << endl;
}
