#include <iostream>
#include <vector>
using namespace std;

const int MAX = 987654321;

int main(){
	int n,s;
	
	cin >> n >> s;
	vector<int> v(n);
	
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	
	int left=0,right=0;
	int sum = v[0];
	int len = MAX;
	
	while(left<=right && right < n){
		if(sum < s) sum += v[++right];
		else if(sum == s){
			len = min(len, right-left+1);
			sum += v[++right];
		}
		else{
			len = min(len, right-left+1);
			sum -= v[left++];
		}
	}
	
	if(len == MAX) cout << 0;
	else cout << len;
}
