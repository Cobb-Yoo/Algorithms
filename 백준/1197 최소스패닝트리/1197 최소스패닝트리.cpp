#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

queue<int> q;
vector<vector<int>> varr;
int arr[100000];
int answer = 0;

int find(int n){
	if(arr[n] < 0) {
		while(!q.empty()){
			arr[q.front()] = n;
			q.pop();
		}
		return n;
	}
	else {
		q.push(n);
		return find(arr[n]);
	}
}

void unioon(int a, int b){
	if(arr[a] > arr[b]) a^=b^=a^=b;
	
	arr[a] += arr[b];
	arr[b] = a;
}

bool cmp(vector<int> a, vector<int> b){
	return a[2] < b[2];
}

int main(){
	memset(arr,-1,sizeof(arr));
	int v, e;
	cin >> v >> e;

	for(int i=0;i<e;i++){
		int a,b,cost;
		cin >> a >> b >> cost;
			
		varr.push_back({a,b,cost});
	}
	
	sort(varr.begin(), varr.end(), cmp);
	
	for(int i=0;i<e;i++){
		int a_parent = find(varr[i][0]);
		int b_parent = find(varr[i][1]);
		int cost = varr[i][2];
		
		if(a_parent != b_parent) {
			unioon(a_parent, b_parent);
			answer += cost;
		}
	}
	
	cout << answer << endl;
}
