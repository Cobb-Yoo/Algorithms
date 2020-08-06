#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

int n,m,k;
long long arr[MAX];
long long tree[MAX*4];

long long init(int start, int end, int node){
	if(start==end) return tree[node] = arr[start];
	int mid = (start+end)/2;
	
	return tree[node] = init(start,mid,node*2) + init(mid+1,end,node*2+1);
}

long long sum(int start, int end, int node, int left, int right){
	if(left > end || right < start) return 0;
	if(left<=start && end<=right) return tree[node];
	
	int mid = (start+end)/2;
	return sum(start,mid,node*2,left,right)+sum(mid+1,end,node*2+1,left,right);
}

void update(int start, int end, int node, int index, int dif){
	if(index < start || index > end) return;
	tree[node]+=dif;
	
	if(start==end) return;
	
	int mid = (start+end)/2;
	update(start,mid,node*2,index,dif);
	update(mid+1,end,node*2+1,index,dif);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	
	init(0,n-1,1);
	
	for(int i=0;i<m+k;i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		
		if(a == 1){
			int x = c-arr[b-1];
			update(0,n-1,1,b-1,x);
		}
		else{
			cout << sum(0,n-1,1,b-1,c-1) << endl;
		}
		//a가 1이면 b번째 수를 c로 바꾼다.
		//a가 2이면 b부터 c까지의 수의 합을 구한다. 
	}
}
