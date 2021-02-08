#include <iostream>
using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	
	pair<int,int> idx;
	idx.first = 1;
	idx.second = m;
	
	int ans = 0;
	for(int tmp,i=0;i<k;i++){
		cin >> tmp;
		
		if(idx.first <= tmp && tmp < idx.second) continue;
		else if(idx.first > tmp){
			int len = idx.first-tmp;
			ans += len;
			idx.first -= len;
			idx.second -= len;
		}
		else{
			int len = tmp-idx.second;
			ans += len;
			idx.first += len;
			idx.second += len;
		}
	}
	
	cout << ans;
}
