#include <iostream>
#define ll long long
using namespace std;

const int MAX = 1000000;
ll arr[MAX+1];
ll tree[MAX*3];

void update(int node, int start, int end, int idx, int dif){
	if(start<=idx && idx<=end) tree[node] += dif;
	else return;
	
	if(start == end) return;
	
	int mid = (start+end)/2;
	update(node*2,start,mid,idx,dif);
	update(node*2+1,mid+1,end,idx,dif);
}

ll getSum(int left, int right, int node, int start, int end){
	if(left<= start && end <= right) return tree[node];
	if(right < start || end < left) return 0;	
	
	int mid = (start+end)/2;
	return getSum(left, right, node*2, start, mid)+getSum(left, right, node*2+1, mid+1, end);
}

ll init(int node, int start, int end){
	if(start == end) return tree[node] = arr[start];
	
	int mid = (start+end)/2;
	tree[node] = init(node*2, start, mid)+init(node*2+1,mid+1,end);
	return tree[node];
}
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	
	for(int i=1;i<=n;i++) cin >> arr[i];
	init(1,1,n);
	
	for(int i=0;i<m+k;i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		if(a == 1){
			int x = c - arr[b];
			arr[b] = c;
			update(1,1,n,b,x);
		}
		else{
			cout << getSum(b,c,1,1,n) << endl;
		}
	}
}
