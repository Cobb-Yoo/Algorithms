#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

const int MAX = 1000000000 + 1;
const int NUM = 100000 + 1;
ll arr[NUM];
ll minTree[NUM*4];

ll init_minTree(int node, int start, int end){
	if(start == end){
		return minTree[node] = arr[start];
	}	
	else {
		int mid = (start+end) >> 1;
		return minTree[node] = min(init_minTree(node<<1, start, mid), init_minTree((node<<1)+1, mid+1, end));	
	}
}

ll get_min(int node, int start, int end, int left, int right){
	if(left > end || right < start){
		return MAX;
	}
	if(left <= start && right >= end){
		return minTree[node];
	}
	
	int mid = (start+end) >> 1;
	return min(get_min(node<<1,start,mid,left,right), get_min((node<<1)+1,mid+1,end,left,right));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	
	int n,m,a,b;
	scanf("%d %d", &n, &m);
	
	
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	init_minTree(1, 0, n-1);
	
	for(int i=0;i<m;i++){
		scanf("%d %d", &a,&b);
		
		printf("%lld\n", get_min(1, 0, n-1, a-1, b-1));
	}
}
