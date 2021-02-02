#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	
	if(n == 1){
		cout << 1;
		return 0;
	}
	
	int begin = 2, end = 7, idx = 6;
	int cnt=1;
	while(cnt++){
		if(begin <= n && n <= end){
			cout << cnt;
			return 0;
		}
		
		begin += idx;
		idx += 6;
		end += idx;
	}
}
