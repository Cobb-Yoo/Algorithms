#include <iostream>
using namespace std;

const int MAX = 1000000;

int a[MAX];
int b[MAX];
int c[MAX];

int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,len;
	cin >> n >> m;
	len = n+m;
	
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	
	int a_idx=0, b_idx=0, c_idx=0;
	
	while(a_idx<n && b_idx<m){
		if(a[a_idx] < b[b_idx]) c[c_idx++] = a[a_idx++];
		else c[c_idx++] = b[b_idx++];
	}
	
	while(a_idx<n) c[c_idx++] = a[a_idx++];
	while(b_idx<m) c[c_idx++] = b[b_idx++];
	
	for(int i=0;i<c_idx;i++) cout << c[i] << " ";
}
