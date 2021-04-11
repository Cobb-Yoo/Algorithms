#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
vector<vector<int>> v;
int arr[1000];
int answer = 0;
queue<int> q;

bool cmp (vector<int> a, vector<int> b){
	return a[2] < b[2];
}

void unioon(int a, int b){
	if(arr[a] > arr[b]) a^=b^=a^=b;
	
	arr[a] += arr[b];
	arr[b] = a;
}

int find(int n){
	if(arr[n] < 0){
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

int main(){
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b,cost;
		cin >> a >> b >> cost;
		
		v.push_back({a-1,b-1,cost});
	}
	
	sort(v.begin(),v.end(),cmp);
	
	memset(arr,-1,sizeof(arr));
	
	for(int i=0;i<m;i++){
		int a_parent = find(v[i][0]);
		int b_parent = find(v[i][1]);
		int cost = v[i][2];
		
		if(a_parent != b_parent){
			unioon(a_parent, b_parent);
			answer += cost;
		}
	}
	
	cout << answer << endl;
}
