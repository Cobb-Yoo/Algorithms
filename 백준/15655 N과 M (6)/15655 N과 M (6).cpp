#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000+1;

int n,m;
vector<int> arr;
bool visited[9];

void solve(vector<int> &v){
	if(v.size() == m){
		for(int i : v){
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	
	for(int i=0;i<n;i++){
		if(!v.empty() && v.back() >= arr[i]) continue;
		
		v.push_back(arr[i]);
		solve(v);
		v.pop_back();
	}
}

int main(){
	vector<int> v;
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++) {
		int tmp; cin >> tmp;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(), arr.end());
	
	solve(v);
}
