#include <iostream>
using namespace std;

const int MAX = 100000;

int arr[MAX+1];
int tree[MAX*4];

void update(int node, int start, int end, int idx, int dif){
	if(start<=idx && idx<=end) tree[node] += dif;
	else return;
	
	if(start == end) return;
	
	int mid = (start+end)/2;
	update(node*2,start,mid,idx,dif);
	update(node*2+1,mid+1,end,idx,dif);
}

int getSum(int left, int right, int node, int start, int end){
	if(left<= start && end <= right) return tree[node];
	if(right < start || end < left) return 0;	
	
	int mid = (start+end)/2;
	return getSum(left, right, node*2, start, mid)+getSum(left, right, node*2+1, mid+1, end);
}

int init(int node, int start, int end){
	if(start == end) return tree[node] = arr[start];
	
	int mid = (start+end)/2;
	tree[node] = init(node*2, start, mid)+init(node*2+1,mid+1,end);
	return tree[node];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> arr[i];
	init(1,1,n);
	
	for(int i=0;i<m;i++){
		int begin, end;
		cin >> begin >> end;
		
		cout << getSum(begin, end, 1, 1, n) << "\n";
	}
}
