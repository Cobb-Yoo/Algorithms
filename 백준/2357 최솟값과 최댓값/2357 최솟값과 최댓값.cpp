#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

int n,m;
vector<ll> v;


ll init_maxTree(vector<ll> &maxTree, int node, int start, int end){
	if(start == end){
		return maxTree[node] = v[start];
	}
	else{
		int mid = (start+end)/2;
		return maxTree[node] = max(init_maxTree(maxTree, node*2, start, mid), init_maxTree(maxTree, node*2+1, mid+1, end));
	}
}

ll get_max(vector<ll> &maxTree, int node, int start, int end, int left, int right){
	if(left > end || right < start){
		return -1;
	}
	if(left <= start && right >= end){
		return maxTree[node];
	}
	
	int mid = (start+end)/2;
	return max(get_max(maxTree, node*2, start, mid, left, right), get_max(maxTree, node*2+1, mid+1, end, left,right));
}

ll init_minTree(vector<ll> &minTree, int node, int start, int end){
	if(start == end){
		return minTree[node] = v[start];
	}
	else{
		int mid = (start+end)/2;
		return minTree[node] = min(init_minTree(minTree, node*2, start, mid), init_minTree(minTree, node*2+1, mid+1, end));
	}
}

ll get_min(vector<ll> &minTree, int node, int start, int end, int left, int right){
	if(left > end || right < start){
		return 1000000001;
	}
	if(left <= start && right >= end){
		return minTree[node];
	}
	
	int mid = (start+end)/2;
	return min(get_min(minTree, node*2, start, mid, left, right), get_min(minTree, node*2+1, mid+1, end, left,right));
}

int main(){	
	ios_base::sync_with_stdio(0);
	cin.tie();
	
	cin >> n >> m;
	int h = (int) ceil(log2(n));
    int tree_size = (1 << (h + 1));
    
    
	for(int i=0;i<n;i++){
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	
	vector<ll> minTree(tree_size);
	vector<ll> maxTree(tree_size);
	
	
	init_minTree(minTree, 1, 0, n-1);
	init_maxTree(maxTree, 1, 0, n-1);
	
	int a,b;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		
		cout << get_min(minTree, 1, 0, n-1, a-1 , b-1) << " " << get_max(maxTree, 1, 0, n-1, a-1 , b-1) << "\n";
	}
}
