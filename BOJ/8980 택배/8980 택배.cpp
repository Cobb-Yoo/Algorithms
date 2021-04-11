#include <bits/stdc++.h>
using namespace std;

int n,c,m;
int arr[2001];
typedef struct Node{
	int start;
	int terminal;
	int box;
}Node;
vector<Node> v;

bool cmp(Node a, Node b){
	if(a.terminal == b.terminal) return a.start < b.start;
	return a.terminal < b.terminal;
}

int main(){
	cin >> n >> c >> m;
	
	int s,t,b;
	for(int i=0;i<m;i++){
		cin >> s >> t >> b;
		v.push_back({s,t,b});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i=1;i<=n;i++) arr[i] = c;
	
	int ans=0;
	for(int i=0;i<m;i++){
		int Min = arr[v[i].start];
		
		for(int j=v[i].start+1;j<v[i].terminal;j++){
			Min = min(Min, arr[j]);
		}
		
		int cnt = min(v[i].box, Min);
		ans += cnt;
		
		for(int j=v[i].start;j<v[i].terminal;j++){
			arr[j] -= cnt;
		}
	}
	cout << ans;
}
